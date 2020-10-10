for i in range(1000, 10000):
    a = (i//1000) * ((i//100)%10)
    b = (i%10) * ((i//10)%10)
    if (a == 12 and b == 4) or (b == 12 and a == 4):
        print(i)
        break
