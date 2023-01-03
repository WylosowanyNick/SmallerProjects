# log10(100!) = 157,97
# Zatem największy input ma 158 cyfr

for _ in range(int(input())):
    n = int(input())

    # Liczenie silni będzie się opierało na iteracyjnych przemnażaniach
    # wartości tablicy reprezentujących dużą liczbę

    tab_p = [1] + [0]*158
    tab_n = [0]*159
    for i in range(1, n+1):
        # Poniższa pętla wykonuje operacje przemnażania całej liczby
        for j in range(len(tab_p)):
            tab_n[j] = tab_p[j] * i
        
        # Poniższa pętla jest częścią powyższej operacji
        for j in range(len(tab_p)-1):
            tab_p[j] = tab_n[j]%10
            tab_n[j+1] += tab_n[j]//10 # Ta instrukcja wymaga zwiększenia wielkości tablic tab_p i tab_n o jeden

    # Przedstawienie otrzymanej liczby:
    # Usunięcie nadmiarowych zer z jej reprezentacji dziesiętnej:
    flag = 0
    for i in range(len(tab_p)-1, -1, -1):
        if tab_p[i] != 0:
            flag = i
            break

    # Przedstawienie otrzymanego wyniku (zapisanego odwrotnie)
    print(''.join(list(map(lambda x: str(x), tab_p[flag::-1]))))

# Program można zoptymalizować pod kątem operacji przemnażania (wystarczy pominąć nieprzemnażane zera)