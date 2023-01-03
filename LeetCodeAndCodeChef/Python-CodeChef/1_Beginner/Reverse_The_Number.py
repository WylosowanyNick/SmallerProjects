inp = int(input())
for _ in range(inp):
    result = input()[::-1]
    reading = 0
    for i in range(len(result)):
        if 0 < int(result[i]):
            reading = i
            break
    
    print(result[i:])
