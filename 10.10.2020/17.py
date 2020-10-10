s = 0
k = 0
for i in range(2050, 9167):
    if i%7==0 and i%13!=0 and i%14!=0 and i%19!=0 and i%22!=0:
        k +=1
        s = max(s,i)
print(k, s)