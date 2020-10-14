with open('26_demo.txt') as inf:
    n = inf.readline()
    n = 8200
    s = inf.readlines()
    for i in range(len(s)):
        s[i] = int(s[i].rstrip())
    s.sort()
    k = 0
    t = 0
    d = 0
    for i in s:
        k += i
        t += 1
        if k > n:
            k -= i
            break
    s.reverse()
    for i in s:
        if n - k >= i:
            d = i
            break
print(t, d)
