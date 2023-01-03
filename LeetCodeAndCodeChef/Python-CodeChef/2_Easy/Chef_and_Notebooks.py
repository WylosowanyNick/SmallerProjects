for _ in range(int(input())):
    X, Y, K, N = map(int, input().split())
    note = []
    for _ in range(N):
        note.append(list(map(int, input().split())))
    
    sub = X-Y
    result = False
    for el in note:
        if sub<=el[0] and el[1]<=K:
            result = True
            break
    
    if result:
        print("LuckyChef")
    else:
        print("UnluckyChef")
