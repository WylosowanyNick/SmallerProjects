inp = int(input())
for _ in range(inp):
    inp = input()
    result = 0
    for i in range(len(inp)):
        if int(inp[i])==4:
            result += 1

    print(result)
    