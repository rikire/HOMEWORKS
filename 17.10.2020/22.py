from random import randrange


class door:
    def __init__(self):
        self.value = 0
        self.chosen = False


count = {'menyali': 0, 'nemenyali': 0}
guessed = {'menyali': 0, 'nemenyali': 0}
for _ in range(200000):
    s = [door(), door(), door()]
    n = randrange(0, 3)
    s[n].value = 1
    n = randrange(0, 3)
    s[n].chosen = True
    for i in s:
        if not i.chosen and i.value == 0:
            s.pop(s.index(i))
    n = randrange(0, 2)
    if n == 1:
        count['menyali'] += 1
        for i in s:
            if not i.chosen and i.value == 1:
                guessed['menyali'] += 1
    if n == 0:
        count['nemenyali'] += 1
        for i in s:
            if i.chosen and i.value == 1:
                guessed['nemenyali'] += 1
print('количество попыток', count)
print('количество отгаданных', guessed)
