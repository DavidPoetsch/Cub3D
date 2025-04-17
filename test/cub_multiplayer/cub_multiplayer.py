import threading
import socket
import time
from config import Config
from send_rcv import SendRcv
from send import send
from receive import receive

Config.get_ip_addresses()
Config.print_ip_addresses()
Config.add_full_paths()

# Setup socket
SendRcv.setup_socket()

# Start threads
threading.Thread(target=receive, daemon=True).start()
threading.Thread(target=send, daemon=True).start()

# Keep the main thread alive
try:
		while True:
				time.sleep(1)
except KeyboardInterrupt:
		print("Exiting...")
