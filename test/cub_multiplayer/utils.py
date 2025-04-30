# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    utils.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/17 18:35:02 by dpotsch           #+#    #+#              #
#    Updated: 2025/04/30 14:31:30 by dpotsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import os
import posix_ipc
from enums import *
from config import Config

def clear_file(path):
	Config.sem_filelock.acquire()
	try:
		with open(path, 'w'):
				pass  # 'w' mode truncates the file
	except Exception as e:
		print(f"Failed to clear file '{path}': {e}")
	finally:
			Config.sem_filelock.release()

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

def file_is_empty(path):
	Config.sem_filelock.acquire()
	empty = os.path.exists(path) and os.path.getsize(path) == 0
	Config.sem_filelock.release()
	return empty

def write_file(path, data):
	Config.sem_filelock.acquire()
	res = Result()
	if not data.endswith('\n'):
		data += '\n'
	try:
		with open(path, 'w') as f:
			res.data = f.write(data)
	except Exception as e:
		res.msg = f"Failed to write file {path}"
		res.state = ResultState.ERROR
	Config.sem_filelock.release()
	return res

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
