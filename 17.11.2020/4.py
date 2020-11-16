# 110

n = int(input())
left_3 = 0
left_1 = 0
right_3 = 0
right_1 = 0
m = 0
for _ in range(n):
    a = int(input())
    if a > m:
        if m !=0:
            if m % 3 == 0:
                left_3 += 1
            else:
                left_1 += 1

        m = a

        left_1 += right_1
        left_3 += right_3
        right_1 = 0
        right_3 = 0
    else:
        if a % 3 == 0:
            right_3 += 1
        else:
            right_1 += 1
total = left_3 * right_1 + left_3 * right_3 + left_1 * right_3
print(total)
