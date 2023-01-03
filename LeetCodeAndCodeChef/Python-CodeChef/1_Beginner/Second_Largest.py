for _ in range(int(input())):
    A, B, C = map(int, input().split())
    
    if (B<=A and A<=C) or (C<=A and A<=B):
        print(A)
    elif (A<=B and B<=C) or (C<=B and B<=A):
        print(B)
    else:
        print(C)
