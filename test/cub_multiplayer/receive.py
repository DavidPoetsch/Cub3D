# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    receive.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/17 18:36:18 by dpotsch           #+#    #+#              #
#    Updated: 2025/04/30 14:47:01 by dpotsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import threading
import time
import os
from send_rcv import SendRcv
from utils import write_file
from utils import parse_pos
from utils import file_is_empty
from config import Config

# Buffer and lock
msg_buffer = []
buffer_lock = threading.Lock()
BUFFER_SIZE = 5

def write_enemy_pos(pos):
	write_file(Config.f_receive_pos, f"{pos[0]},{pos[1]}")

# Background writer thread
def write_received_msg_worker():
	while True:
		with buffer_lock:
			if msg_buffer and file_is_empty(Config.f_receive_msg):
					msg = msg_buffer.pop(0)
					write_file(Config.f_receive_msg, msg)
		time.sleep(0.01)

def enqueue_received_msg(msg):
	with buffer_lock:
		if len(msg_buffer) < BUFFER_SIZE:
			msg_buffer.append(msg)
		else:
			print("[WARNING] Receive buffer full. Dropping message.")

def parse_msg(msg):
	if "pos:" in msg:
		msg = msg.replace("pos:", "")
		pos = parse_pos(msg)
		if pos[0] != -1.0:
			write_enemy_pos(pos)
	else:
		enqueue_received_msg(msg)

def receive():
	threading.Thread(target=write_received_msg_worker, daemon=True).start()
	while True:
		res = SendRcv.read_sock()
		if res.is_success():
			parse_msg(res.data)
		else:
			print(res.msg)
			exit()
