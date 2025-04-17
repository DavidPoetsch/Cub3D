# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    utils.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/17 18:35:02 by dpotsch           #+#    #+#              #
#    Updated: 2025/04/17 20:22:52 by dpotsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from enums import *

def clear_file(path):
	try:
		with open(path, 'w') as f:
			pass  # Opening in 'w' mode automatically clears the file
	except Exception as e:
			print(f"Failed to clear file '{path}': {e}")

def read_file(path):
	res = Result()
	try:
		with open(path, 'r') as f:
			res.data = f.read()
			return res
	except Exception:
		msg = f"Failed to read file {path}"
		return Result.return_err(msg)

def write_file(path, data):
	res = Result()
	try:
		with open(path, 'w') as f:
			res.data = f.write(data)
		return res
	except Exception as e:
		msg = f"Failed to write file {path}"
		return Result.return_err(msg)

