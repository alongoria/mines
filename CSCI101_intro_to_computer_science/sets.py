Python 2.6.6 (r266:84297, Aug 24 2010, 18:13:38) [MSC v.1500 64 bit (AMD64)] on win32
Type "copyright", "credits" or "license()" for more information.

    ****************************************************************
    Personal firewall software may warn about the connection IDLE
    makes to its subprocess using this computer's internal loopback
    interface.  This connection is not visible on any external
    interface and no data is sent to or received from the Internet.
    ****************************************************************
    
IDLE 2.6.6      
>>> emptySet = set([])  # or emptySet = set()
>>> dataSet = set([ 3, 'A', 7, 'S', 3.14159 ])
>>> print "emptySet is", emptySet
emptySet is set([])
>>> # or just 'evaluate' the variable name...
>>> dataSet
set(['A', 3.1415899999999999, 'S', 3, 7])
>>> help(emptySet.add)
Help on built-in function add:

add(...)
    Add an element to a set.
    
    This has no effect if the element is already present.

>>> help(dataSet.add)
Help on built-in function add:

add(...)
    Add an element to a set.
    
    This has no effect if the element is already present.

>>> a = set([1, 3, 1, 3, 3, 1])
>>> print a
set([1, 3])
>>> a.remove(3)
>>> print a
set([1])
>>> emptySet.add(5)
>>> prina

Traceback (most recent call last):
  File "<pyshell#12>", line 1, in <module>
    prina
NameError: name 'prina' is not defined
>>> print a
set([1])
>>> dataSet.add(5)
>>> print a
set([1])
>>> a.remove(0)

Traceback (most recent call last):
  File "<pyshell#16>", line 1, in <module>
    a.remove(0)
KeyError: 0
>>> print emptySet
set([5])
>>> emptySet.remove(5)
>>> print emptySet
set([])
>>> print a
set([1])
>>> a.add(5)
>>> print a
set([1, 5])
>>> n = dataSet.union( set([1,3,46,-1]) ).
SyntaxError: invalid syntax
>>> n = dataSet.union( set([1,3,46,-1]).
		   print a
		   
SyntaxError: invalid syntax
>>> n = dataSet.union( set([1,3,46,-1])
		   a
		   
SyntaxError: invalid syntax
>>> p = dataSet.difference( set([1]) ).
SyntaxError: invalid syntax
>>> p = dataSet.difference( set([1]) )
>>> 
>>> fe
		       

Traceback (most recent call last):
  File "<pyshell#35>", line 1, in <module>
    fe
NameError: name 'fe' is not defined
>>> a = set([1, 3 ])
>>> b = set([ 'One', 'Three' ])
>>> c = a.union(b)
\
>>> print c
set([1, 3, 'Three', 'One'])
>>> true_or_false = 3 in c
>>> print "3 is in c", true_or_false
3 is in c True
>>> d = c.union(b)
>>> print d
set([1, 3, 'Three', 'One'])
>>> print  "'FortyTwo' is in d", 'FortyTwo' in c
'FortyTwo' is in d False
>>> Six is in d
SyntaxError: invalid syntax
>>> print "'Six' is in d"
'Six' is in d
>>> "'Six' is in d", true_or_false
("'Six' is in d", True)
>>> d.remove('FortyTwo')

Traceback (most recent call last):
  File "<pyshell#48>", line 1, in <module>
    d.remove('FortyTwo')
KeyError: 'FortyTwo'
>>> d.discard('FortyTwo')
>>> print d
set([1, 3, 'Three', 'One'])
>>> 
