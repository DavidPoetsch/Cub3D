# udp_position_sync.py
import socket
import threading
import time
from utils import get_ip
from utils import get_other_ip

PORT = 5005

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((get_ip(), PORT))

def read_player_pos():
		try:
				with open('player_pos.txt', 'r') as f:
						x, y = map(float, f.read().strip().split(','))
						return [x, y]
		except Exception:
				print("failed to read file")
				return [-1.0, -1.0]

def write_enemy_pos(pos):
		try:
				with open('enemy_pos.txt', 'w') as f:
						f.write(f"{pos[0]},{pos[1]}")
		except Exception as e:
				print(f"Failed to write enemy_pos.txt: {e}")

def listen():
		while True:
				try:
						data, _ = sock.recvfrom(1024)
						x, y = map(float, data.decode().strip().split(','))
						write_enemy_pos([x, y])
						print(f"[RECEIVED] Other player: {[x, y]}")
				except Exception as e:
						print(f"[ERROR] Receiving: {e}")
						exit(0)

def send():
		pos_old = [0.0, 0.0]
		while True:
				try:
						pos = read_player_pos()
						if (pos != pos_old and pos[0] != -1.0):
							pos_old = pos
							message = f"{pos[0]},{pos[1]}"
							sock.sendto(message.encode(), (get_other_ip(), PORT))
							print(f"[SENT] My position: {pos}")
				except Exception as e:
						print(f"[ERROR] Sending: {e}")
						exit(0)
				time.sleep(0.1)

# Start threads
threading.Thread(target=listen, daemon=True).start()
threading.Thread(target=send, daemon=True).start()

# Keep the main thread alive
try:
		while True:
				time.sleep(1)
except KeyboardInterrupt:
		print("Exiting...")
