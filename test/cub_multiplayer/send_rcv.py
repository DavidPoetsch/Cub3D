# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    send_rcv.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/17 18:44:53 by dpotsch           #+#    #+#              #
#    Updated: 2025/04/17 20:17:36 by dpotsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import socket
from config import Config
from enums import Result

class SendRcv:
	pos_old = [0.0, 0.0]
	sock = None

	@classmethod
	def setup_socket(cls):
		cls.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
		cls.sock.bind((Config.own_ip, Config.port))

	@classmethod
	def send_msg(cls, msg):
		try:
			cls.sock.sendto(msg.encode(), (Config.other_ip, Config.port))
			print(f"[SENT] {msg}")
		except Exception as e:
			print(f"[ERROR] Sending: {e}")
			exit(0)

	@classmethod
	def read_sock(cls):
		res = Result()
		try:
			data, _ = cls.sock.recvfrom(1024)
			res.data = data.decode()
			print(f"[RECEIVED] {res.data}")
			return res
		except Exception as e:
			return Result.return_err(f"[ERROR] Receiving: {e}")
