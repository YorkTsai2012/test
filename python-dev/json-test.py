#!/usr/bin/python
#-*- coding: utf-8 -*-
#中文

import json

#http://stackoverflow.com/questions/8009882/how-to-read-large-file-line-by-line-in-python
def handlev2(path):
	with open(path) as file:
		count = 1
		for line in file:
			d = json.loads(line)
			for k in d:
				print "", str(count), k, d[k]
			count += 1

def handle(path):
	try:
		file = open(path, "r")
		count = 1
		for line in file:
			d = json.loads(line)
			for k in d:
				print "", str(count), k, d[k]
			count += 1

	finally:
		if file:
			file.close()

if __name__ == '__main__': 
	#handle("input.data")
	print __name__
	handlev2("input.data")
