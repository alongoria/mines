Python 2.6.6 (r266:84297, Aug 24 2010, 18:13:38) [MSC v.1500 64 bit (AMD64)] on win32
Type "copyright", "credits" or "license()" for more information.

    ****************************************************************
    Personal firewall software may warn about the connection IDLE
    makes to its subprocess using this computer's internal loopback
    interface.  This connection is not visible on any external
    interface and no data is sent to or received from the Internet.
    ****************************************************************
    
IDLE 2.6.6      
>>> aye = 'A'
>>> bee = "B"
>>> cee = '''C'''
>>> dee = """D"""
>>> print aye, bee, cee, dee
A B C D
>>> print aye,bee,cee,dee
A B C D
>>> print aye+bee+cee+dee
ABCD
>>> afirst = "This is \\ backslash."
>>> asecond = r"This is a \ backslash."
>>> print afirst, asecond
This is \ backslash. This is a \ backslash.
>>> x = 3.14
>>> print "Our favorite ratio:" + x

Traceback (most recent call last):
  File "<pyshell#11>", line 1, in <module>
    print "Our favorite ratio:" + x
TypeError: cannot concatenate 'str' and 'float' objects
>>> xAsString = str(x)
>>> print "Our favorite ratio:" + xAsString
Our favorite ratio:3.14
>>> "Here is an integer %d, a float %f, and a string %s" % ( int(1), float(2), str('three') )
'Here is an integer 1, a float 2.000000, and a string three'
>>> "One formatter float: %f" % math.pi

Traceback (most recent call last):
  File "<pyshell#15>", line 1, in <module>
    "One formatter float: %f" % math.pi
NameError: name 'math' is not defined
>>> import math
>>> "One formatter float: %f" % math.pi
'One formatter float: 3.141593'
>>> "Another formatted float: %f" % (math.pi, )
'Another formatted float: 3.141593'
>>> "Here is an integer %d, a float %f, and a string %s" % ( int(1), str('three'), float(2) )

Traceback (most recent call last):
  File "<pyshell#19>", line 1, in <module>
    "Here is an integer %d, a float %f, and a string %s" % ( int(1), str('three'), float(2) )
TypeError: float argument required, not str
>>> "Here is an integer %d, a string %s, a float %f" % ( int(1), str('three'), float(2) )
'Here is an integer 1, a string three, a float 2.000000'
>>> "One formatted float: %f" % math.pi
'One formatted float: 3.141593'
>>> "Another formatted float: %f" % ( math.pi, )
'Another formatted float: 3.141593'
>>> 
>>> "%d%02d%04d%08d" % (1,2,3,4)
'102000300000004'
>>> "%10.3f%10.3f%10.3f%10.3f
SyntaxError: EOL while scanning string literal
>>> "%10.3f%10.3f%10.3f%10.3f" % (1,2,3,4)
'     1.000     2.000     3.000     4.000'
>>> x = [5,6,7,8]
>>> "%d%-02d%-04d%-08d" % tuple(x)
'56 7   8       '
>>> "%-12s%-12s\n%-12f%-12d" % ("float","interger",math.pi,42)
'float       interger    \n3.141593    42          '
>>> print "%-12s%-12s\n%-12f%-12d" % ("float","interger",math.pi,42)
float       interger    
3.141593    42          
>>> 
>>> f = file("example-of-simple-tabular-output.txt", "w")
>>> f.write( "&-12s%-12s\n" % ("float","interger",) )

Traceback (most recent call last):
  File "<pyshell#33>", line 1, in <module>
    f.write( "&-12s%-12s\n" % ("float","interger",) )
TypeError: not all arguments converted during string formatting
>>> f.write( "%-12s%-12s\n" % ("float","interger",) )
>>> f.write( "%-12.3s%-12d\n" % ("float","interger",) )

Traceback (most recent call last):
  File "<pyshell#35>", line 1, in <module>
    f.write( "%-12.3s%-12d\n" % ("float","interger",) )
TypeError: %d format: a number is required, not str
>>> f.write( "%-12.3s%-12s\n" % ("float","interger",) )
>>> f.write( "%-12.3s%-12s\n" % (math.pi,42) )
>>> f.close()
>>> 
