for _ in range(int(input())):
    for G in range(int(input())):
        I, N, Q = map(int, input().split())

        if N%2==0 or I==Q:
            print(N//2)
        else :
            print((N+1)//2)
