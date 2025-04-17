# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    config.py                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/17 18:31:58 by dpotsch           #+#    #+#              #
#    Updated: 2025/04/17 20:53:51 by dpotsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import os

class Config:
	### IP
	port = 5005
	own_ip = "0.0.0.0"
	other_ip = "0.0.0.0"

	###FILES
	f_enemy_pos = "enemy_pos.txt"
	f_player_pos = "player_pos.txt"
	f_enemy_state = "enemy_state.txt"
	f_player_state = "player_state.txt"

	@classmethod
	def add_full_paths(cls):
		# Get the directory where the script is located
		base_path = os.path.dirname(os.path.abspath(__file__))
		# Join base path with each file name
		cls.f_enemy_pos = os.path.join(base_path, cls.f_enemy_pos)
		cls.f_player_pos = os.path.join(base_path, cls.f_player_pos)
		cls.f_enemy_state = os.path.join(base_path, cls.f_enemy_state)
		cls.f_player_state = os.path.join(base_path, cls.f_player_state)

	@classmethod
	def get_ip_addresses(cls):
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
