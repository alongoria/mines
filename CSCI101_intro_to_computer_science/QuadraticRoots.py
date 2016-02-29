## ax^2 + bx + c = 0

a = input("Enter 'a' coefficient: " ,)
b = input("Enter 'b' coefficient: " ,)
c = input("Enter 'c' coefficient: " ,)

import math

z = (b**2)-(4*a*c)
x = (-b/(2*a))         

if z < 0 :
   z = -z 
   y = math.sqrt(z)
   c = ((y)/(2*a))
   print "<%8.5f,%8.5fi>,<%8.5f,-%8.5fi>" % (x,c,x,c)

else:
    root1 = x + (math.sqrt(z)/(2*a))
    root2 = x - (math.sqrt(z)/(2*a))
    print "%8.5f,%8.5f" % (root1,root2)

    
    
    
   



