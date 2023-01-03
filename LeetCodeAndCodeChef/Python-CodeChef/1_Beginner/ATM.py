inp = input()
inp = inp.split(' ')
x=int(inp[0])
y=float(inp[1])

if x%5==0 and x+0.5<=y:
    print(str(y-x-0.5)+'0\n')
else:
    print(str(y)+'0\n')
