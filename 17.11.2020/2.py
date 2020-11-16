# 3-ИЙ МИНИМУМ

n = int(input())
arr = []
for _ in range(n):
    s = int(input())
    if s in arr:
        continue
    else:
        if len(arr) < 3:
            arr.append(s)
            arr.sort()
            continue
        else:
            if s < arr[0]:
                arr[2] = arr[1]
                arr[1] = arr[0]
                arr[0] = s
            elif s < arr[1]:
                arr[2] = arr[1]
                arr[1] = s
            elif s < arr[2]:
                arr[2] = s

if len(arr) < 3:
    print('#')
else:
    print(arr[2])
