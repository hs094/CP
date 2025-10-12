for _ in range(int(input())):
    s = list(input())
    n = len(s)
    while s[-1] == '0':
        _ = s.pop()
    print(n-1-s.count(0))