for _ in range(int(input())):
    input()
    A = list(map(int, input().split()))
    uj = A[int(input())-1]
    
    cnt = 0
    for el in A:
        if el<uj:
            cnt += 1
    
    print(cnt+1)
