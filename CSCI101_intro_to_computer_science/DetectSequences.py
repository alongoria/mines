f = open("bogus=empty.txt", "r")
e = 7
a = 3
c = 0
z = ""


bad = f.readline()

while bad is not a:
    bad = f.readline()
    if (bad == ""):
        print "BOGUS"
        break
     

end = False
good = f.readline()
good = int(good)
while good is not a or end == True:
    good = f.readline()
    c = c + 1
    while a != z:
        good = f.readline()
        c = c + 1
        
        if good is True:
            end == True

        if end is True:
            end == False
            f.readline()
            c = c + 1
    

        elif good is e:
        
            end = True
        
        
        print "Accept", c
        break



