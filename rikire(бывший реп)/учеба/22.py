for x in range(1000):
    a = 0
    b = 1
    t = x
    while x > 0:
        if x%2 > 0:
            a += 1
        else:
            b += x%5
        x //= 5
    if a == 2 and b == 9:
        print(t)