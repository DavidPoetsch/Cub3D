import psutil
import threading
import socket
import time
from config import Config
from send_rcv import SendRcv
from send import send
from receive import receive
from utils import write_file

Config.get_ip_addresses()
Config.print_ip_addresses()
Config.add_full_paths()
Config.init_semaphore()

### init files
write_file(Config.f_send_msg, "alive")

# Setup socket
SendRcv.setup_socket()

# Start threads
threading.Thread(target=receive, daemon=True).start()
threading.Thread(target=send, daemon=True).start()


def get_cub3d_pid():
	for proc in psutil.process_iter(['pid', 'name']):
		try:
				if proc.info['name'] == 'cub3D':
						return proc.info['pid']
		except (psutil.NoSuchProcess, psutil.AccessDenied):
				continue
	return None

# Keep the main thread alive
count = 3
try:
		while True:
			pid = get_cub3d_pid()
			if pid is None:
				count -= 1
				if count <= 0: 
					print("cub3d is not running.")
					exit(0)
			else:
				count = 10
			time.sleep(1)
except KeyboardInterrupt:
		print("Exiting...")
