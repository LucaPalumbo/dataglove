import time
from vmg30 import VMG30  # supponendo che la classe sia salvata in un file chiamato vmg30.py

def main():
    glove = VMG30(port="/dev/ttyUSB0")  # modifica la porta se necessario
    glove.open_device()

    if not glove.send_start_packet(packet_type=1):  # PKT_TYPE_QUAT_FINGER
        print("Started data streaming...")
    else:
        print("Failed to send start packet.")
        return

    try:
        while True:
            if glove.read_stream() == 0 and glove.is_new_packet_available():
                glove.reset_new_packet()

                # stampa sensori
                sensors = glove.sensors
                print("Sensors:", sensors)

                # stampa orientamenti
                print("Wrist RPY:", glove.rpy_wrist)
                print("Hand RPY:", glove.rpy_hand)

                print("Wrist quaternion:", glove.quaternion_wrist)
                print("Hand quaternion:", glove.quaternion_hand)

                print("Packet tick:", glove.packet_tick)
                print("-" * 40)

            time.sleep(0.01)  # leggera attesa per evitare busy waiting

    except KeyboardInterrupt:
        print("\nInterruzione da tastiera ricevuta. Chiudo la connessione...")

    finally:
        glove.close_device()

if __name__ == "__main__":
    main()