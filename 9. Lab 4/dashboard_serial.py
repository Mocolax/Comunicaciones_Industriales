
# dashboard_serial.py
import streamlit as st
import serial
import serial.tools.list_ports
import threading
import time
import pandas as pd
from datetime import datetime
import plotly.graph_objects as go

st.set_page_config(page_title="Dashboard RS485 Arduino", layout="wide")
st.title("Dashboard RS485 Arduino")

# Sidebar controls
ports = [p.device for p in serial.tools.list_ports.comports()]
port = st.sidebar.selectbox("Puerto serial", options=ports if ports else ["escribe_puerto_manual"])
baud = st.sidebar.number_input("Baudios", min_value=1200, max_value=115200, value=9600, step=1200)
start = st.sidebar.button("Conectar")
stop = st.sidebar.button("Desconectar")

status = st.empty()
log = st.empty()

if "ser" not in st.session_state:
    st.session_state.ser = None
if "data" not in st.session_state:
    st.session_state.data = []

def reader_loop(ser):
    while st.session_state.ser is ser:
        try:
            line = ser.readline().decode(errors="ignore").strip()
            if not line:
                continue
            ts = datetime.now()
            # Expect lines like:
            #   TX val 512 seq 10
            #   RX ok val 512 ang 90
            rec = {"ts": ts, "raw": line, "val": None, "ang": None, "kind": None}
            if "TX" in line:
                rec["kind"] = "TX"
            if "RX" in line:
                rec["kind"] = "RX"
            for key in ["val", "ang", "seq"]:
                tag = key + " "
                if tag in line:
                    try:
                        rec[key] = int(line.split(tag)[1].split()[0])
                    except:
                        pass
            st.session_state.data.append(rec)
        except Exception as e:
            time.sleep(0.05)

col1, col2 = st.columns([2,1])

with col1:
    plot_placeholder = st.empty()
with col2:
    table_placeholder = st.empty()

if start and st.session_state.ser is None:
    try:
        ser = serial.Serial(port, baudrate=baud, timeout=0.2)
        st.session_state.ser = ser
        threading.Thread(target=reader_loop, args=(ser,), daemon=True).start()
        status.success("Conectado")
    except Exception as e:
        status.error(f"Error al abrir puerto: {e}")

if stop and st.session_state.ser is not None:
    try:
        st.session_state.ser.close()
    except:
        pass
    st.session_state.ser = None
    status.info("Desconectado")

# Live update loop
placeholder = st.empty()
while True:
    df = pd.DataFrame(st.session_state.data[-500:])
    if not df.empty:
        fig = go.Figure()
        if "val" in df:
            fig.add_scatter(x=df["ts"], y=df["val"], mode="lines", name="val")
        if "ang" in df:
            fig.add_scatter(x=df["ts"], y=df["ang"], mode="lines", name="ang")
        fig.update_layout(height=400, margin=dict(l=10,r=10,t=20,b=10))
        plot_placeholder.plotly_chart(fig, use_container_width=True)

        table_placeholder.dataframe(df.tail(10), use_container_width=True)
    time.sleep(0.25)
