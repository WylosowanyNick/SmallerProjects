for _ in range(int(input())):
    # Pobieranie danych o samochodach
    input()
    tab = list(map(lambda x: int(x), input().split(' ')))

    # Liczenie samochodów jadących z maksymalną prędkością opiera się na:
    # Porównywaniu kolejnych samochodów względem najwolniejszego samochodu
    # znajdującego się przed tymi samochodami. Wtedy tylko ten samochód
    # będzie się poruszał z maksymalną prędkością (o ile inne nie mają
    # takiej samej prędkości).

    mini = tab[0]
    cnt = 1
    for i in range(1, len(tab)):
        if mini>tab[i]:
            mini = tab[i]
            cnt += 1

    # Wyświetlanie wyniku:
    print(cnt)
