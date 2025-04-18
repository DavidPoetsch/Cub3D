# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    send.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/17 18:36:02 by dpotsch           #+#    #+#              #
#    Updated: 2025/04/18 16:45:18 by dpotsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import time
from send_rcv import SendRcv
from config import Config
from utils import read_file
from utils import parse_pos
from utils import clear_file
from utils import parse_pos

def update_player_pos():
	res = read_file(Config.f_player_pos)
	if res.is_error():
		print(res.msg)
		return [-1.0, -1.0]
	pos = parse_pos(res.data)
	if pos[0] != -1.0:
		if pos != SendRcv.pos_old:
			SendRcv.pos_old = pos
			SendRcv.send_msg(f"pos: {pos[0]},{pos[1]}")

def update_enemy_state():
	res = read_file(Config.f_enemy_state)
	if res.is_error():
		print(res.msg)
		return
	msg = res.data.replace('\n', '')
	if (len(msg) <= 1):
		return
	clear_file(Config.f_enemy_state)
	SendRcv.send_msg(msg)

def send():
	while True:
		update_player_pos()
		update_enemy_state()
		# time.sleep(0.05)
