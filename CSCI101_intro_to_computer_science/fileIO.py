Python 2.6.6 (r266:84297, Aug 24 2010, 18:13:38) [MSC v.1500 64 bit (AMD64)] on win32
Type "copyright", "credits" or "license()" for more information.

    ****************************************************************
    Personal firewall software may warn about the connection IDLE
    makes to its subprocess using this computer's internal loopback
    interface.  This connection is not visible on any external
    interface and no data is sent to or received from the Internet.
    ****************************************************************
    
IDLE 2.6.6      
>>> f = file( "test,txt", "w" )
>>> f = file( "test.txt", "w" )
>>> f.write( "Hello file." )
>>> f.write( "Good-bye file." )
>>> f.close()
>>> f = file( "test.txt", "w" )
>>> f.write( "Hello file!\n" )
>>> f.write( "Good-bye file.\n" )
>>> f.close()
>>> f = file( "test.txt", "a")
>>> f.write( "\nA third sentence on the fourth line of the file.\n" )
>>> f.close()
\
>>> f = file( "test.txt", "r" )
>>> f.readline()
'Hello file!\n'
>>> line2 = f.readline()
>>> emptyline = f.readline()
>>> line3 = f.readline()
>>> f.readline()
''
>>> f.readline()
''
>>> f.readline()
''
>>> f.close()
>>> print line2
Good-bye file.

>>> print emptyline


>>> print line 3
SyntaxError: invalid syntax
>>> print line3
A third sentence on the fourth line of the file.

>>> print len( f.readline() )

Traceback (most recent call last):
  File "<pyshell#25>", line 1, in <module>
    print len( f.readline() )
ValueError: I/O operation on closed file
>>> 
