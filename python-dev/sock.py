#!/bin/python
# -*- coding: utf-8 -*-

import socket

s = socket.socket()
#sinceLinux3.9,见man7socket
s.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
s2 = socket.socket()
s2.setsockopt(socket.SOL_SOCKET,socket.SO_REUSEADDR,1)
s.bind(('127.0.0.1', 8001))
s2.bind(('127.0.0.1', 8002))
#都可以使用同一本地地址来连接哦
#s.connect(('127.0.0.1',8001))
#s2.connect(('127.0.0.1',8002))
