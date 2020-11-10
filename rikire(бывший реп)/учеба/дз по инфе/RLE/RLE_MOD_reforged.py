# Это первая программа(не модифицированная)
# под один символ будет выделятся 3 десятичных цифры,
# а под цифры будем выделять не 1 доп бит,
# а целый 1 символ, какое расточительство памяти!!!!


def remake_digital_0(x):
    return '0' + '0' * (3 - len(str(x))) + str(x)


def remake_digital_1(x):
    return '1' + '0' * (3 - len(str(x))) + str(x)


def remake_char(x):
    return '0' * (3 - len(str(ord(x)))) + str(ord(x))


def deremake(x):
    return x[1:]


def search(s, a):
    k = 0
    for i in s:
        if i == a:
            k += 1
            continue
        break
    return k


def RLE(s):
    s_sec = ''
    s_help = ''
    t_sum = 0
    while len(s) > 0:
        t = s[0]
        k = search(s, t)
        if k == 1:
            t_sum += 1
            s_help += remake_char(t) + ' '
        else:
            if t_sum > 0:
                s_sec += remake_digital_0(t_sum) + ' ' + s_help
                t_sum = 0
                s_help = ''
            s_sec += remake_digital_1(k) + ' ' + remake_char(t) + ' '

        s = s[k:]

    if t_sum > 0:
        s_sec += remake_digital_0(t_sum) + ' ' + s_help

    return s_sec


def DERLE(s):
    sec_s = ''
    k = 0
    s = s.split()
    while len(s) > 0:
        t = s[0]
        if t[0] == '1':
            k = int(deremake(t))
            sec_s += chr(int(s[1])) * k
            s = s[2:]
        else:
            k = int(t)
            for i in range(k):
                sec_s += chr(int(s[i + 1]))
            s = s[k + 1:]
    return sec_s


s = input()
s2 = RLE(s)
print(s2)
print(DERLE(s2))
