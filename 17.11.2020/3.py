# 97 СУММА КРАТНАЯ ТРЕМ, ПРОИЗВЕДЕНИЕ - ПЯТИ

n = int(input())
# для кратных 5
l1 = [0, 0, 0]
# для не кратных 5
l2 = [0, 0, 0]
total = 0
for _ in range(n):
    a = int(input())
    p = a % 3
    if a % 5 == 0:
        total += l2[(3 - p)%3] + l1[(3 - p)%3]
        l1[p] += 1
    else:
        total += l1[(3 - p)%3]
        l2[p] += 1
print(total)
