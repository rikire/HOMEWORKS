def search(s, k):
    count = 0
    if len(s) - k < 3:
        return 0
    for i in range(k, len(s), 3):
        if s[i] in 'ACE':
            if s[i+1] != s[i] and s[i+1] in 'ADF':
                if s[i + 2] != s[i+1] and s[i+2] in 'ABF':
                    count += 1
                    continue

        break
    return count


with open('k7c-2.txt') as inf:
    s = inf.readline()
    count = 0
    for i in range(len(s)):
        if s[i] in 'ACE':
            count = max(search(s, i), count)
    print(count)