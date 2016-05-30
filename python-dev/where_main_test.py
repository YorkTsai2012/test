#!/usr/bin/python

import sys 

# python 自省  http://www.ibm.com/developerworks/cn/linux/l-pyint/index1.html

if __name__ == "__main__":
    print "hello"
    print globals()
    print dir(sys.modules[__name__])
    print type(sys.modules[__name__])
