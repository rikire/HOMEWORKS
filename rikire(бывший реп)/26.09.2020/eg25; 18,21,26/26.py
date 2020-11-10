import math
def search(n):
    s = []
    for i in range(1, int(math.sqrt(n))):
        if n%i == 0:
            s.append(i)
    return s


for i in range(78920,92430):
    s = search(i)
    if len(s) == 5:
        print(sorted(s))