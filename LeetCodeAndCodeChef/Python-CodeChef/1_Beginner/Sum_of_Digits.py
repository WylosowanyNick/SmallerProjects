inp = int(input())
for _ in range(inp):
    inp = input()
    result = 0
    for i in range(len(inp)):
        result += int(inp[i])
    
    print(result)
