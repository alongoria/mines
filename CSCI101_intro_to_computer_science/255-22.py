last = 0
current = 1
while current < 100:
    print current
    temp = last
    last = current
    current = last + 1
    print temp, last, current
