# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    config.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/17 18:31:58 by dpotsch           #+#    #+#              #
#    Updated: 2025/04/22 13:44:36 by dpotsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import os
import posix_ipc
from dotenv import load_dotenv

class Config:
	### IP
	port = 5005
	own_ip = "0.0.0.0"
	other_ip = "0.0.0.0"

	###FILES
	f_receive_pos = "f_receive_pos.txt"
	f_send_pos = "send_pos.txt"
	f_receive_msg = "receive_msg.txt"
	f_send_msg = "send_msg.txt"

	### Semaphore file lock
	sem_filelock = None
	sem_name = "/semaphore_filelock"

	@classmethod
	def add_full_paths(cls):
		# Get the directory where the script is located
		base_path = os.path.dirname(os.path.abspath(__file__))
		# Join base path with each file name
		cls.f_receive_pos = os.path.join(base_path, cls.f_receive_pos)
		cls.f_send_pos = os.path.join(base_path, cls.f_send_pos)
		cls.f_send_msg = os.path.join(base_path, cls.f_send_msg)
		cls.f_receive_msg = os.path.join(base_path, cls.f_receive_msg)

	@classmethod
	def get_ip_addresses(cls):
			load_dotenv()
			cls.own_ip = os.getenv('OWN_IP')
			cls.other_ip = os.getenv('OTHER_IP')

			if not cls.own_ip:
				print("OWN_IP is not set in environment variables.")
				exit(0)
			if not cls.other_ip:
				print("OTHER_IP is not set in environment variables.")
				exit(0)
	
	@classmethod
	def print_ip_addresses(cls):
			print(f"OWN_IP:		{cls.own_ip}")
			print(f"OTHER_IP:	{cls.other_ip}")

	@classmethod
	def init_semaphore(cls):
		cls.sem_filelock = posix_ipc.Semaphore(cls.sem_name, posix_ipc.O_CREAT, initial_value=1)
