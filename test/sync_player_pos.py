# udp_position_sync.py
import socket
import threading
import time

MY_IP = '192.168.1.10'
OTHER_IP = '192.168.1.11'

MY_IP = '10.12.4.9'
OTHER_IP = '10.12.4.8'

PORT = 5005

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((MY_IP, PORT))

def read_player_pos():
		try:
				with open('player_pos.txt', 'r') as f:
						x, y = map(float, f.read().strip().split(','))
						return [x, y]
		except Exception:
				return [0.0, 0.0]

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
						if (pos != pos_old):
							pos_old = pos
							message = f"{pos[0]},{pos[1]}"
							sock.sendto(message.encode(), (OTHER_IP, PORT))
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
<<<<<<< HEAD
    while True:
        player_pos[0] += 50
        player_pos[1] += 100
        print(f"[SENT] My position: {player_pos}")
        time.sleep(0.5)
=======
		while True:
				time.sleep(1)
>>>>>>> fe44043abd84920c6285152af60d46f93641eef7
except KeyboardInterrupt:
		print("Exiting...")
