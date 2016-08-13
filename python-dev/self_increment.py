#!/usr/bin/python
#-*- coding: utf-8 -*-

#http://stackoverflow.com/questions/1485841/behaviour-of-increment-and-decrement-operators-in-python

import commands

def ServerStatus(host, port):
    cmd = "nc -z " + host + " " + str(port)
    return commands.getstatusoutput(cmd)

if __name__ == '__main__':
    db_set = ["db1", "db2", "db3"]
    count = 0 
    for index, db_name in enumerate(db_set):
        prefix = ""
        if index < 1:
            prefix = "Primary-"
        else:
            prefix = "Secondary-"
        if count < 1:
            print prefix + db_name
            #++count #the value of count does not change 
            count += 1
