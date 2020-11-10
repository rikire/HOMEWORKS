with open('26-1.txt') as inf:
    s, n = map(int, inf.readline().split())
    data = []
    for i in range(n):
        data.append(int(inf.readline()))
    data.sort()
    i_prev = 0
    k = 0
    t_s = 0
    for i in data:
        if t_s + i >= s:
            break
        t_s += i
        k += 1
        i_prev = i
    p = s - t_s + i_prev
    for i in data[::-1]:
        if i <= p:
            print(k, ' ', i)
            break