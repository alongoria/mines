import urllib2
theURL = "http://inside.mines.edu/~khellman/teaching/csci101/qo/coursegrades.dat"
urlConnection = urllib2.urlopen( theURL )
lines = urlConnection.readlines()

f = file( "HttpCalculatedCourseGrades.txt", "w" )

for j in lines [1:len(lines)]:

    var = j.split()

    CWID = var[0]
    final = float(var[1])
    I = float(var[2])
    II = float(var[3])
    prgm = float(var[4])
    ind = float(var[5])
    grp = float(var[6])

    grade = final*.25 + II*.20 + I*.15 + prgm*.20 + ind*.10 + grp*.10

    f.write( "%s" % CWID )
    f.write( "%6.2f" % grade )
    f.write( "%6.2f" % final )
    f.write( "%6.2f" % II )
    f.write( "%6.2f" % I )
    f.write( "%6.2f" % prgm )
    f.write( "%6.2f" % ind )
    f.write( "%6.2f" % grp )
    f.write( "\n" )


f.close()
