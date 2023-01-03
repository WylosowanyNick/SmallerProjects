player_1, player_2, lead = 0, 0, 0
for _ in range(int(input())):
    p1, p2 = map(int, input().split(' '))
    player_1 += p1
    player_2 += p2
    if abs(lead)<abs(player_1-player_2):
        lead = player_1-player_2
    
if 0<lead:
    print(1, abs(lead))
else:
    print(2, abs(lead))
