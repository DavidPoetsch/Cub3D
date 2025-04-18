# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    enums.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpotsch <poetschdavid@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/17 19:07:16 by dpotsch           #+#    #+#              #
#    Updated: 2025/04/17 20:10:58 by dpotsch          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

from enum import Enum

class State(Enum):
	DEAD = 0
	ALIVE = 1

class ResultState(Enum):
	SUCCESS = 0
	ERROR = 1

class Result:
	def __init__(self):
		self.msg = None
		self.data = None
		self.state = ResultState.SUCCESS

	@classmethod
	def return_err(cls, msg):
		res = cls()
		res.msg = msg
		res.state = ResultState.ERROR
		return res

	def is_error(self):
		return self.state != ResultState.SUCCESS

	def is_success(self):
		return self.state == ResultState.SUCCESS
