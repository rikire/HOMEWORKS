# остатки на 3
s = [0, 0, 0]
s_prev = [0, 0, 0]
with open('012 - 10.10.2020/27-B_demo.txt') as inf:
    n = int(inf.readline().rstrip())
    for _ in range(n):
        a, b = map(int, inf.readline().rstrip().split())
        for i in s_prev:
            p = (a + i) % 3
            if s[p] == 0:
                s[p] = a + i
            else:
                if i != 0:
                    s[p] = min(s[p], a + i)
        for i in s_prev:
            p = (b + i) % 3
            if s[p] == 0:
                s[p] = b + i
            else:
                s[p] = min(s[p], b + i)
        s_prev = s.copy()
        s = [0, 0, 0]
if s_prev[1] == 0:
    print(s_prev[2])
elif s_prev[2] == 0:
    print(s_prev[1])
else:
    print(min(s_prev[1], s_prev[2]))