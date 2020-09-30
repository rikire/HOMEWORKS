def search(s, k):
    count = 0
    if len(s) - k < 3:
        return 0
    for i in range(k, len(s), 3):
        if s[i] == 'D' and s[i+1] == 'A' and s[i + 2] == 'F':
            count += 1
        else:
            break
    return count


with open('k7b-6.txt') as inf:
    s = inf.readline()
    count = 0
    for i in range(len(s)):
        if s[i] == 'D':
            count = max(search(s, i), count)
    print(count)