f = file( "test3.txt", "r" )

def readNumbersFile(f):
    thelist = []
    x = f.readlines()
    for n in x:
        t = int(n)
        thelist.append(t)
    return thelist
    thelist = readNumbersFile(f)
    print thelist
thelist = readNumbersFile(f)

a = 3
e = 7


def isSequence(thelist,a,e):
    if len(thelist) >= 1 and thelist[-1] == a and thelist[0]:
        i = 1
        while i < len(thelist):
            if thelist[i] == e:
                i = i + 1
            elif thelist[i] == a:
                if i == len(thelist) - 1:   
                    return True
            i = i + 1
        return False
    else:
        return False

def maxSequence(thelist, a, e):
    maxL = 0
    maxI = 0
    index = 0
    length = 1
    
    while length < len( thelist ):
        index = 0

        while index + length <= len( thelist ):
            subList = thelist[index: index + length + 1]
            if isSequence(subList, a, e):
                if len(subList) > maxL:
                    maxL = len(subList)
                    maxI = index
            index = index + 1
        length = length + 1
    if maxL == 1: return (0,0)
    return (maxL,maxI)
    
      
    
def isPalindrome ( theSubList ):
    NewList = list(theSubList)
    NewList.reverse()
    if theSubList == NewList:
        return True
    else:
        return False
    

def maxPalindrome( theList ) :
    maxL = 0
    maxI = 0
    index = 0
    length = 1
    
    while length < len( theList ):
        index = 0

        while index + length <= len( theList ):
            subList = theList[index: index + length + 1]
            if isPalindrome(subList):
                if len(subList) > maxL:
                    maxL = len(subList)
                    maxI = index
            index = index + 1
        length = length + 1
    if maxL == 1: return (0,0)
    return (maxL,maxI)


print "List =", thelist
if maxPalindrome( thelist ) != (0,0):
    (c,b) = maxPalindrome( thelist )
    xlist = thelist[b:c + b]
    if isSequence(xlist, a, e) == True:
        print "Largest palindrome is a sequence!!!!, start =",b,", length =",c
    else:
        print "Largest palindrome is NOT a sequence. :("
        


