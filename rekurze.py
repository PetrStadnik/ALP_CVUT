

def count(a, b, w="decrease"): # w rozhoduje jestli se bude přičítat, nebo odečítat, v základu je nastavené na odečítání

    if w == "increase": #4 a potom zase přičítá
        a = a + b
        print(a)
        if a != ai: #5 dokud se nerovná původně zadanému a, které jsme označlili jako ai
            count(a, b, "increase")
    else: #1 odečítá a vypisuje a
        print(a)
        if 0 > a - b: #3 dokud by se nesalo, že by to po odečnení bylo menší než 0, pak nastaví w na přičítání
            count(a, b, "increase")
        else:
            count(a - b, b) #2 funkce volá sama sebe se změněnými parametry, a je zmenšené o b, b se nemění



if __name__=='__main__':
    ai = int(input())
    bi = int(input())
    count(ai, bi) # volám funkci poprvé
