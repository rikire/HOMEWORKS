# Это первая программа(не модифицированная)
# под один символ будет выделятся 3 десятичных цифры


def remake_digital(x):
    return '0' * (3 - len(str(x))) + str(x)


def remake_char(x):
    return '0' * (3 - len(str(ord(x)))) + str(ord(x))


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
    while len(s) > 0:
        t = s[0]
        k = search(s, t)
        s = s[k:]
        s_sec += remake_digital(k) + ' ' + remake_char(t) + ' '
    return s_sec


def DERLE(s):
    sec_s = ''
    k = 0
    s = s.split()
    for i in range(len(s)):
        if i % 2 == 0:
            k = int(s[i])
        else:
            sec_s += chr(int(s[i])) * k
    return sec_s


s = input()
s2 = RLE(s)
print(s2)
print(DERLE(s2))
