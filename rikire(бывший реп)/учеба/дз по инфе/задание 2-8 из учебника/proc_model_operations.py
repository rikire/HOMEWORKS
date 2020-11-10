# ТУТ ВСЯКИЕ ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ

def From_hex(c):
    return ord(c) - ord('A') + 10


def OP1(s, R):
    # s[1] - kuda, s[2] - kogo
    print('R{0} := {1}'.format(s[1], s[2]))
    if s[2] in 'ABCDF':
        t = From_hex(s[2])
    else:
        t = int(s[2])
    R[int(s[1])] = t


def OP2(s, R):
    # s[1] - kogo, s[2] - kuda
    print('R{0} := R{1}'.format(s[2], s[1]))
    R[int(s[2])] = R[int(s[1])]


def OP3(s, R):
    # s[1] - kogo, s[2] - kuda
    print('R{0} := R{0} + R{1}'.format(s[2], s[1]))
    R[int(s[2])] += R[int(s[1])]
    R[int(s[2])] %= 256


def OP4(s, R):
    # s[1] - kogo, s[2] - kuda
    print('R{0} := R{0} - R{1}'.format(s[2], s[1]))
    R[int(s[2])] -= R[int(s[1])]
    if R[int(s[2])] < 0:
        R[int(s[2])] = (255 + R[int(s[2])]) % 256
    else:
        R[int(s[2])] %= 256


def OP5(s, R):
    # s[1] - kogo, s[2] - kuda
    print('R{0} := R{0} * R{1}'.format(s[2], s[1]))
    R[int(s[2])] *= R[int(s[1])]
    R[int(s[2])] %= 256


def OP6(s, R):
    # s[1] - kogo, s[2] - kuda
    print('R{0} := R{0} // R{1}'.format(s[2], s[1]))
    if R[int(s[1])] == 0:
        raise ZeroDivisionError
    R[int(s[2])] //= R[int(s[1])]


def OP7(s, R):
    # s[1] - kogo, s[2] - kuda
    print('R{0} := R{0} И R{1}'.format(s[2], s[1]))
    R[int(s[2])] &= R[int(s[1])]
    R[int(s[2])] = R[int(s[2])] % 256


def OP8(s, R):
    # s[1] - kogo, s[2] - kuda
    print('R{0} := R{0} ИЛИ R{1}'.format(s[2], s[1]))
    R[int(s[2])] |= R[int(s[1])]
    R[int(s[2])] = R[int(s[2])] % 256


def OP9(s, R):
    print('R{0} := R{0} ИСКЛ ИЛИ R{1}'.format(s[2], s[1]))
    R[int(s[2])] ^= R[int(s[1])]
    R[int(s[2])] = R[int(s[2])] % 256


def OP10(s, R):
    print('R{0} := НЕ R{1}'.format(s[2], s[1]))
    R[int(s[2])] = (255 - R[int(s[1])]) % 256
