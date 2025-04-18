# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    utils.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/17 18:35:02 by dpotsch           #+#    #+#              #
#    Updated: 2025/04/18 09:30:06 by dpotsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import posix_ipc
from enums import *
from config import Config

def clear_file(path):
	try:
		with open(path, 'w') as f:
			pass  # Opening in 'w' mode automatically clears the file
	except Exception as e:
			print(f"Failed to clear file '{path}': {e}")

def read_file(path):
	Config.sem_filelock.acquire()
	res = Result()
	try:
		with open(path, 'r') as f:
			res.data = f.read()
	except Exception:
		res.msg = f"Failed to read file {path}"
		res.state = ResultState.ERROR
	Config.sem_filelock.release()
	return res

def write_file(path, data):
	Config.sem_filelock.acquire()
	res = Result()
	try:
		with open(path, 'w') as f:
			res.data = f.write(data)
	except Exception as e:
		res.msg = f"Failed to write file {path}"
		res.state = ResultState.ERROR
	Config.sem_filelock.release()
	return res
