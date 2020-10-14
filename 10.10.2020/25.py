m = 0
mk = 0
k = 0
for i in range(568023, 569231):
    for j in range(1, i + 1):
        if i % j == 0:
            k += 1
    if k > mk:
        m = i
        mk = k
    if k == mk:
        m = min(m, i)
    k = 0
print(m, mk)
