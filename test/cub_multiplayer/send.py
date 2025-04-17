# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    send.py                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/17 18:36:02 by dpotsch           #+#    #+#              #
#    Updated: 2025/04/17 20:21:01 by dpotsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import socket
import time
from send_rcv import SendRcv
from config import Config
from utils import read_file
from enums import Result

def parse_pos(pos_string):
	pos_string = pos_string.strip().split(',')
	x, y = map(float, pos_string)
	return [x, y]

def update_player_pos():
	res = read_file(Config.f_player_pos)
	if res.is_error():
		print(res.msg)
		return [-1.0, -1.0]
	pos = parse_pos(res.data)
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
		time.sleep(0.1)
