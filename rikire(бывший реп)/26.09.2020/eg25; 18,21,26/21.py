import math
def search(n):
    s = []
    for i in range(1, int(math.sqrt(n))):
        if n%i == 0:
            s.append(i)
    return s


for i in range(190201,190231):
    s = search(i)
    if len(s) == 4:
        print(sorted(s)[::-1])