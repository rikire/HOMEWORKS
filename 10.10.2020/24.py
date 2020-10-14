with open('24_demo.txt') as inf:
    s = inf.readline()
    k = 0
    m = 0
    for i in s:
        if i == 'X':
            k += 1
        else:
            m = max(k, m)
            k = 0
    print(max(m, k))
