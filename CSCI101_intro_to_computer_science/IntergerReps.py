
def promptBinary():
    binary = raw_input("Input binary sequence: " )

    List = [int(i) for i in str(binary)]  
     
    return List

def decimalValue(List):
    decimal = 0
    index = len(List) - 1
    x = 0
    
    for n in List:
        if n == 1:
            decimal = 2**index
            index = index - 1
            x = decimal + x
        else:
            index = index - 1
    
    return x

def complement(List):
    complement = []
    for i in List:
        if i == 1:
            f = 0
            complement.append(f)
        if i == 0:
            f = 1
            complement.append(f)
    
    return complement

def decimalTwos(List):
    decimal = 0
    Twos = 0
    sign = (-(2**(len(List)-1)))*List[len(List)-1]
    Twos = sign + Twos
    Twos = Twos + decimalValue(List[1:])

    return Twos
    
List = promptBinary()
print "Binary =", List
Complement = complement(List)
print "Complement =", Complement
Decimal = decimalValue(List)
print "Decimal Value =", Decimal
Twos = decimalTwos(List)
print "Two's Complement Value =", Twos




