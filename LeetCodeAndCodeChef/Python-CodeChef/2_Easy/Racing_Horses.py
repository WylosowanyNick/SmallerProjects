for _ in range(int(input())):
    input()
    tab = list(map(int, input().split()))
    tab.sort()
    print(min([tab[i+1]-tab[i] for i in range(len(tab)-1)]))
