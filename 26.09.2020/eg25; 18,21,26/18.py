import math
def search(n):
    s = []
    for i in range(1, int(math.sqrt(n))):
        if n%i == 0:
            s.append(i)
    return s


for i in range(143146,143216):
    s = search(i)
    if len(s) == 6:
        print(sorted(s))