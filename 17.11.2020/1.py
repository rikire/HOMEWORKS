def is_palind(cs):
    t = 0
    for K in cs:
        if cs[K] % 2 == 1:
            t += 1
    if t > 1:
        return False
    else:
        return True


s = input()
s = s[0:-1]
cs = {}
for i in s:
    if i in cs:
        cs[i] += 1
    else:
        cs[i] = 1
if not is_palind(cs):
    print('No')
else:
    print("Yes")
    st_left = ''
    st_right = ''
    center = ''
    keys = list(cs.keys())
    keys.sort()
    for i in keys:
        t = cs[i]
        st_left = st_left + str(i) * (t // 2)
        st_right = str(i) * (t // 2) + st_right
        if t % 2 == 1:
            center = i

    print(st_left + center + st_right)
