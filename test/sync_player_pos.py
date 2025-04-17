# udp_position_sync.py
import socket
import threading
import time

MY_IP = '192.168.1.10'
OTHER_IP = '192.168.1.11'

MY_IP = '10.12.4.8'
OTHER_IP = '10.12.4.9'

PORT = 5005

# Dummy player position
player_pos = [0, 0]
other_player_pos = [0, 0]

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((MY_IP, PORT))

def listen():
    global other_player_pos
    while True:
        data, _ = sock.recvfrom(1024)
        x, y = map(float, data.decode().split(','))
        other_player_pos = [x, y]
        print(f"[RECEIVED] Other player: {other_player_pos}")

def send():
    while True:
        message = f"{player_pos[0]},{player_pos[1]}"
        sock.sendto(message.encode(), (OTHER_IP, PORT))
        time.sleep(0.1)  # 10 updates per second

# Start threads
threading.Thread(target=listen, daemon=True).start()
threading.Thread(target=send, daemon=True).start()

# Dummy position update loop
try:
    while True:
        player_pos[0] += 100
        player_pos[1] += 200
        print(f"[SENT] My position: {player_pos}")
        time.sleep(0.5)
except KeyboardInterrupt:
    print("Exiting...")
