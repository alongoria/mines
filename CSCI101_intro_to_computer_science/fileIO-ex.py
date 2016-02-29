Python 2.6.6 (r266:84297, Aug 24 2010, 18:13:38) [MSC v.1500 64 bit (AMD64)] on win32
Type "copyright", "credits" or "license()" for more information.

    ****************************************************************
    Personal firewall software may warn about the connection IDLE
    makes to its subprocess using this computer's internal loopback
    interface.  This connection is not visible on any external
    interface and no data is sent to or received from the Internet.
    ****************************************************************
    
IDLE 2.6.6      
>>> f = file( "myfamily.txt", "w" )
>>> f.write( "Martin\n" )
>>> f.write( "Rebecca\n" )
>>> f.write( " Adrian\n" )
>>> f.close
<built-in method close of file object at 0x0000000003555660>
>>> 
>>> f.close()
>>> f = file( "myfamily.txt", "r" )
>>> print line1

Traceback (most recent call last):
  File "<pyshell#8>", line 1, in <module>
    print line1
NameError: name 'line1' is not defined
>>> f.readline()
'Martin\n'
>>> line2 = f.readline
>>> line3 = f.readline
>>> emptyline = f.readline
>>> line4 = f.readline
>>> f.readline
<built-in method readline of file object at 0x0000000003555A50>
>>> f.readline()
'Rebecca\n'
>>> f.readline()
'Adrian\n'
>>> f.readline()
'\n'
>>> f.readline()
'i changed this usind Notepad\n'
>>> f.readline()
''
>>> f.readline()
''
>>> f.close()
>>> print line4
<built-in method readline of file object at 0x0000000003555A50>
>>> print line2
<built-in method readline of file object at 0x0000000003555A50>
>>> f = file( "myfamily.yxy", "r" )

Traceback (most recent call last):
  File "<pyshell#24>", line 1, in <module>
    f = file( "myfamily.yxy", "r" )
IOError: [Errno 2] No such file or directory: 'myfamily.yxy'
>>> f = file( "myfamily.txt", "r" )
>>> print line2
<built-in method readline of file object at 0x0000000003555A50>
>>> f.readline()
'Martin\n'
>>> f.readline()
'Rebecca\n'
>>> f.readline()
'Adrian\n'
>>> f.readline()
'\n'
>>> f.readline()
'i changed this usind Notepad\n'
>>> f.readline()
''
>>> f.readline()
''
>>> f.readline()
''
>>> >>> line2 = f.readline
>>> line3 = f.readline
>>> emptyline = f.readline
>>> line4 = f.readline
SyntaxError: invalid syntax
>>> line2 = f.readline
>>> print line2
<built-in method readline of file object at 0x0000000003555B70>
>>> 
