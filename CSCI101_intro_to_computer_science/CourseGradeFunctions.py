import urllib2
theURL = "http://inside.mines.edu/~khellman/teaching/csci101/qo/coursegrades.dat"


def download(theURL):
    urlConnection = urllib2.urlopen( theURL )
    lines = urlConnection.readlines()
    return lines

lines = download(theURL)

def parse(lines):
    tokens = lines.split()
    values = []
    values.append(str(tokens[0]))
    values.append(float(tokens[1]))
    values.append(float(tokens[2]))
    values.append(float(tokens[3]))
    values.append(float(tokens[4]))
    values.append(float(tokens[5]))
    values.append(float(tokens[6]))
    return values

def courseGrade(tokens):
    CWID = tokens[0]
    final = float(tokens[1])
    I = float(tokens[2])
    II = float(tokens[3])
    prgm = float(tokens[4])
    ind = float(tokens[5])
    grp = float(tokens[6])
    cg = (final*.25 + II*.20 + I*.15 + prgm*.20 + ind*.10 + grp*.10)
    return cg


def printStudent(out,cg,values):

    out.write( "%.2f" % cg )
    out.write( "%12s" % values[0] )
    out.write( "%12.2f" % values[1] )
    out.write( "%12.2f" % values[2] )
    out.write( "%12.2f" % values[3] )
    out.write( "%12.2f" % values[4] )
    out.write( "%12.2f" % values[5] )
    out.write( "%12.2f" % values[6] )
    out.write( "\n" )

out = file("HttpCalculatedCourseGrades.txt", "w")

lines = download(theURL)
for l in lines[1:] :   # the [1:] skips the first line of labels
    scores = parse(l)
    cg = courseGrade(scores)
    printStudent( out, cg, scores )

out.close()






    
