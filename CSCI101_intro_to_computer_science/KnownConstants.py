import math
f = file("KnownConstants.txt", "w")
f.write( "%-08s%7s\n" % ("CONSTANT","VALUE") )
f.write( "---------------\n" )
f.write( "%-08s%7.3f\n" % ("PI", math.pi) )
f.write( "%-08s%7.3f\n" % ("E", math.e) )
f.write( "%-08s%7.3f\n" % ("E^PI", math.e**math.pi) ) 
f.close()

                                                        
