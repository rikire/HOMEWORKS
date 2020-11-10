def search(s, k):
    count = 0
    if len(s) - k < 2:
        return 0
    for i in range(k, len(s), 2):
        if s[i] == 'C' and s[i+1] == 'A':
            count += 1
        else:
            break
    return count


with open('k7b-5.txt') as inf:
    s = inf.readline()
    count = 0
    for i in range(len(s)):
        if s[i] == 'C':
            count = max(search(s, i), count)
    print(count)