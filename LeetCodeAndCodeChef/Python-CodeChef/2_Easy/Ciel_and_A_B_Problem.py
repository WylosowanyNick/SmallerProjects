A, B = map(int, input().split(' '))
res = A-B
print(res+1 if res%10<9 else res-1)
