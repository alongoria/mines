Python 2.6.6 (r266:84297, Aug 24 2010, 18:13:38) [MSC v.1500 64 bit (AMD64)] on win32
Type "copyright", "credits" or "license()" for more information.

    ****************************************************************
    Personal firewall software may warn about the connection IDLE
    makes to its subprocess using this computer's internal loopback
    interface.  This connection is not visible on any external
    interface and no data is sent to or received from the Internet.
    ****************************************************************
    
IDLE 2.6.6      
>>> emptyList = []  # or emptyList = list()
>>> dataList = [ 3, 'A', 7, 'S', 3.14159 ]
>>> print "emptyList is", emptyList
emptyList is []
>>> dataList
[3, 'A', 7, 'S', 3.1415899999999999]
>>> emptyList
[]
>>> print dataList[1]
A
>>> dataList[2]
7
>>> dataList[3]
'S'
>>> dataList[6]

Traceback (most recent call last):
  File "<pyshell#8>", line 1, in <module>
    dataList[6]
IndexError: list index out of range
>>> dataList[-1]
3.1415899999999999
>>> dataList[-2]
'S'
>>> dataList[0]
3
>>> dataList[5]

Traceback (most recent call last):
  File "<pyshell#12>", line 1, in <module>
    dataList[5]
IndexError: list index out of range
>>> help(emptyList.insert)
Help on built-in function insert:

insert(...)
    L.insert(index, object) -- insert object before index

>>> emptyList.insert(2,"inserted string"), dataList.insert(-1,"THE_END")
(None, None)
>>> emptyList
['inserted string']
>>> a = [1,3,1,3,3,1]
>>> print a
[1, 3, 1, 3, 3, 1]
>>> a.remove(3)
>>> print a
[1, 1, 3, 3, 1]
>>> a = [1,3,1,3,3,1,2]
>>> del a[1]
>>> print a
[1, 1, 3, 3, 1, 2]
>>> ================================ RESTART ================================
>>> a = [1,3,1,3,3,1,2]
>>> del a[1]
>>> print a
[1, 1, 3, 3, 1, 2]
>>> del a[1]
>>> print a
[1, 3, 3, 1, 2]
>>> del [-1]
SyntaxError: can't delete literal
>>> del a[-1]
>>> print a
[1, 3, 3, 1]
>>> b = ['x']+a+['x']
>>> print b
['x', 1, 3, 3, 1, 'x']
>>> c = b*2
>>> print c
['x', 1, 3, 3, 1, 'x', 'x', 1, 3, 3, 1, 'x']
>>> true_or_false = 3 in c
>>> print "3 is in c", true_or_false
3 is in c True
>>> print "'y' is in c', 'y' in c
SyntaxError: EOL while scanning string literal
>>> print "'y' is in c", "y' in c
SyntaxError: EOL while scanning string literal
>>> print "'y' is in c", 'y' in c
'y' is in c False
>>> 
