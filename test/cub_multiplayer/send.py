# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    send.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/17 18:36:02 by dpotsch           #+#    #+#              #
#    Updated: 2025/04/18 09:44:27 by dpotsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import time
from send_rcv import SendRcv
from config import Config
from utils import read_file
from enums import Result
from utils import clear_file

def parse_pos(pos_string):
	pos_string = pos_string.strip()
	if not pos_string or ',' not in pos_string:
			return [-1.0, -1.0]
	parts = pos_string.split(',')
	if len(parts) != 2:
			return [-1.0, -1.0]
	try:
			x, y = map(float, parts)
			return [x, y]
	except ValueError:
			return [-1.0, -1.0]

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
	if "dead" in res.data:
		clear_file(Config.f_enemy_state)
		SendRcv.send_msg("dead")

def send():
	while True:
		update_player_pos()
		update_enemy_state()
		# time.sleep(0.05)
