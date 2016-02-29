name = raw_input("Insert Student name: ")
final = input("Insert Final Exam Grade: ")
II = input("Insert Exam II Grade: ")
I = input("Insert Exam I Grade: ")
prog = input("Insert Programming and Written Assignments Grade: ")
ind = input("Insert Individual Scores on LGQs: ")
g = input("Insert Group Scores on LGQs (use median group score): ")
grade = final*.25 + II*.20 + I*.15 + prog*.20 + ind*.10 + g*.10
print "Student =", name
print "Course Grade =", grade, "%"

f = file( "CalculatedCourseGrades.txt", "a" )
f.write( "%s" % name )
f.write( "%6.2f" % grade )
f.write( "%6.2f" % final )
f.write( "%6.2f" % II )
f.write( "%6.2f" % I )
f.write( "%6.2f" % prog )
f.write( "%6.2f" % ind )
f.write( "%6.2f" % g )
f.write( "\n" )
f.close()
