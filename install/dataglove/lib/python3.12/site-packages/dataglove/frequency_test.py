import time
from vmg30 import VMG30  # Assicurati che il file sia vmg30.py

def main():
    glove = VMG30(port="/dev/ttyUSB0")  # Modifica se usi una porta diversa, es: COM3 su Windows
    glove.open_device()

    if glove.send_start_packet(packet_type=1) != 0:
        print("Errore nell'avviare lo streaming")
        return

    print("Streaming avviato. Calcolo della frequenza in corso...")

    last_tick = None
    last_time = time.time()
    total_packets = 0

    try:
        while True:
            if glove.read_stream() == 0 and glove.is_new_packet_available():
                glove.reset_new_packet()
                tick = glove.packet_tick
                now = time.time()

                if last_tick is not None:
                    delta_tick = tick - last_tick
                    delta_time = now - last_time

                    if delta_time > 0:
                        # tick sembra essere incrementale per ogni pacchetto ricevuto
                        frequency = delta_tick / delta_time
                        print(f"Frequenza stimata: {frequency:.2f} Hz", end="\r")

                last_tick = tick
                last_time = now
                total_packets += 1

    except KeyboardInterrupt:
        print("\nInterruzione da tastiera ricevuta.")
    finally:
        glove.close_device()
        print(f"Streaming fermato. Totale pacchetti ricevuti: {total_packets}")

if __name__ == "__main__":
    main()