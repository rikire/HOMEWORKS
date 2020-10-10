def f(n):
    if n > 2:
        print(n)
        f(n//2)
        f(n-1)


f(7)