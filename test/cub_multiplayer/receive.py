# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    receive.py                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/17 18:36:18 by dpotsch           #+#    #+#              #
#    Updated: 2025/04/24 14:03:03 by dpotsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from send_rcv import SendRcv
from utils import write_file
from utils import parse_pos
from config import Config

def write_enemy_pos(pos):
	write_file(Config.f_receive_pos, f"{pos[0]},{pos[1]}")

def write_received_msg(state):
	write_file(Config.f_receive_msg, state)

def parse_msg(msg):
	if "pos:" in msg:
		msg = msg.replace("pos:", "")
		pos = parse_pos(msg)
		if pos[0] != -1.0:
			write_enemy_pos(pos)
	else:
		write_received_msg(msg)

def receive():
	while True:
		res = SendRcv.read_sock()
		if res.is_success():
			parse_msg(res.data)
		else:
			print(res.msg)
			exit()
