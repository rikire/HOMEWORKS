# 117

n = int(input())
m = 0
ma = 0
mb = 0

# создать двумерный массив в питоне = жесть
# на протяжении 2 часов я не мог понять, почему мой код не работает
# а не работал он из-за вот такой записи
# idx = [[0] * 7] * 5 - создаст 5 ссылок на 7 ссылок (я люблю динамическую типизацию)
idx = [0 for _ in range(5)]
for i in range(5):
    idx[i] = [0 for _ in range(7)]

for i in range(1, n + 1):
    a = int(input())
    i %= 5
    p = a % 7
    b = idx[i][(7 - p) % 7]
    if a + b > m and b != 0:
        ma = a
        mb = b
        m = a + b
    idx[i][p] = max(a, idx[i][p])
if m == 0:
    print(0)
else:
    print(ma, mb)
