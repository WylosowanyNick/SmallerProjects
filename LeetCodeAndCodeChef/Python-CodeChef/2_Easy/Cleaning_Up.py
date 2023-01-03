for _ in range(int(input())):
    n, m = list(map(int, input().split()))
    tab_1 = list(map(int, input().split()))
    tab_2 = [True]*n

    for el in tab_1:
        tab_2[el-1] = False
    
    cnt = 0
    tab_chef = []
    tab_assistant = []
    for i in range(n):
        if tab_2[i]:
            if cnt%2==0:
                tab_chef.append(i+1)
            else:
                tab_assistant.append(i+1)
            cnt += 1
    
    print(' '.join(map(str, tab_chef)))
    print(' '.join(map(str, tab_assistant)))
