n = int(input())
s = {}
for i in range(37):
    s[i] = []
for i in range(n):
    k = int(input())
    p = k%37
    s[p].append(k)
    s[p].sort()
    if len(s[p]) > 2:
        s[p].pop(0)
for i in s:
    
print(s)