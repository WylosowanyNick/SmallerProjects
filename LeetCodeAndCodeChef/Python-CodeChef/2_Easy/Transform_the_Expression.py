for _ in range(int(input())):
    tab = list(input()) 
    
    i = 5
    while 1<len(tab):
        if tab[i] == ')':
            tab[(i-4):(i+1)] = [tab[i-3]+tab[i-1]+tab[i-2]]
            i -= 3
        else:
            i += 1
    
    print(tab[0])
