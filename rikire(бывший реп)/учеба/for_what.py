import csv

s = []
with open(r'C:\Users\302-8\Downloads\18.csv') as inf:
    i = csv.reader(inf)
    for j in i:
        s.append(list(j))
    for i in range(len(s)):
        s[i] = s[i][0].split(';')
    s[0][0] = '23'
    for i in range(len(s)):
        for j in range(len(s[i])):
            s[i][j] = int(s[i][j])
    for i in range(1, len(s[0])):
        if s[0][i] == 0:
            continue
        elif s[0][i - 1] != 0:
            s[0][i] = s[0][i] + s[0][i - 1]
        else:
            s[0][i] = 0
    for i in range(1, len(s)):
        if s[i][0] == 0:
            continue
        if s[i-1][0] !=0:
            s[i][0] += s[i - 1][0]
        else:
            s[i][0] = 0
    for i in range(1, len(s)):
        for j in range(1, len(s[i])):
            #s[i][j]
            if s[i][j] == 0:
                continue
            if s[i-1][j] == 0:
                if s[i][j-1] == 0:
                    s[i][j] = 0
                    continue
                else:
                    s[i][j] = s[i][j-1] + s[i][j]
                    continue
            else:
                if s[i][j-1] == 0:
                    s[i][j] = s[i-1][j] + s[i][j]
                    continue
                else:
                    s[i][j] = max(s[i][j] + s[i-1][j], s[i][j] + s[i][j-1])
                    continue
#2053 - max
#1053 - min
    for i in s:
        print(i)