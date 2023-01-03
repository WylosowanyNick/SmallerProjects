from itertools import count

for _ in range(int(input())):
    num = int(input())
    suma = 0

    for i in count(start=1):
        div=num//(5**i)
        if div==0:
            break
        
        suma += div
    
    print(suma)
