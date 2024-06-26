# Lab 6

# ci�g zmiennych losowych X1, ... , Xn
# EXi = m, D^2Xi = sig^2

# P(X1 + ... + Xn <= x) =CTG=
# pnorm(x, n * m, sig* sqrt(n))

# X1, X2, ... , Xn EXi = p D^2Xi = p * q

# P(X1 + ... + Xn <= x) =CTG=
# pnorm(x,n*p,sqrt(n*p*q))

# P(k1 <= X1 + ... + <= k2) =
# P(k1 - 0.5 <= X1 + .. + Xn <= k2 + 0.5)


# ZAD 1
# Maksymalne obci��enie windy osobowej wynosi 900 kg.
# Zak�adaj�c, �e �rednia waga cz�owieka wynosi 75 kg
# z odchyleniem standardowym 15 kg wyznaczy�
# prawdopodobie�stwo, �e
# a) przy 13 osobach w windzie, limit wagi nie
# zostanie przekroczony,
# b) �rednia waga 13 os�b jest wi�ksza od 70 i
# mniejsza od 75 kg.

n = 13
m = 75
sig = 15

# a) P(X1 + ... + X13 <= 900)

pnorm(900, n*m, sig*sqrt(n))

# b)
# P(70 < X1 + ... + X13 / 13 < 75) =
# P(70*13 < X1 + ... + X13 < 75*13) =
# P(910 < X1 + ... + X13 < 975)

pnorm(975, n * m, sig*sqrt(n)) -
  pnorm(910, n * m, sig*sqrt(n))


# ZAD 2
# Prawdopodobie�stwo urodzenia ch�opca w badanym
# regionie wynosi 0.525. Obliczy� prawdopodobie�stwo,
# �e w�r�d 1000 noworodk�w b�dzie:
# a) mniej ni� 480 dziewczynek,
# b) ch�opc�w wi�cej ni� 450 i mniej ni� 520.
# W obu podpunktach, o ile to mo�liwe, wyznaczy�
# r�wnie� przybli�enia tych prawdopodobie�stw
# korzystaj�c z rozk�adu Poissona oraz CTG.

n = 1000

# S = X1 + ... + X1000

# a) sukces - urodzenie dziewczynki

p = 0.475
q = 0.525

# P(S < 480) = P(S <= 479)

pbinom(479,n,p)

# rozk�ad Poissona - nie s� spe�nione za�o�enia, bo
# p = 0.475 > 0.1

# CTG, P(S <= 479) = P(S <= 479.5)

pnorm(479.5, n*p, sqrt(n*p*q))

# b) sukces - urodzenie chlopca

p = 0.525
q = 0.475

# P(S < 520) = P(S <= 519)
pbinom(519,n,p) - pbinom(451,n,p)

sum(dbinom(451:519,n,p))

# CTG, P(451 <= S <= 519) =
# P(450.5 <= S <= 519.5)

pnorm(519.5, n*p, sqrt(n*p*q)) -
  pnorm(450.5, n*p, sqrt(n*p*q))


# ZAD 3
# Pewien towar ma wadliwo�� 8%. Zakupiono 1200 sztuk
# tego towaru. Obliczy� prawdopodobie�stwo, �e odsetek
# znalezionych w tej partii sztuk wadliwych b�dzie
# wi�kszy ni� 7% ale nie przekroczy 11%. Zadanie
# rozwi�za� korzystaj�c z rozk�adu dwumianowego
# oraz CTG.

n = 1200
p = 0.08
q = 1-p

# S = X1 + ... + X1200
# P(0.07 < S/1200 <= 0.11) =
# P(84 < S <= 132) = 
# P(85 <= S <= 132)

pbinom(132,n,p) - pbinom(85,n,p)

sum(dbinom(85:132,n,p))

# CTG, P(85 <= S <= 132) =
# P(84.5 <= S <= 132.5)

pnorm(132.5, n*p, sqrt(n*p*q)) -
  pnorm(84.5, n*p, sqrt(n*p*q))


# ZAD 4
# Hurtownia sprowadza kaw� w opakowaniach, kt�rych
# deklarowana waga wynosi 2 kg, a w rzeczywisto�ci
# waga ta podlega rozk�adowi z warto�ci� oczekiwan�
# 1.99 kg i odchyleniem standardowym 0.05 kg.
# W�a�cicielkawiarni oceni� swoje zapotrzebowanie na
# nast�pne p�rocze na 500 kg kawy i tyle zakupi� w
# hurtowni. Jakie jest prawdopodobie�stwo, �e b�dzie
# on musia� dokupi� kaw� z powodu nieuwzgl�dnionych
# ubytk�w wagowych w zakupionym towarze?
  
m = 1.99
sig = 0.05
n = 250

pnorm(500, n*m, sig*sqrt(n))


# ZAD 5
# W pewnej drukarni prawdopodobie�stwo wydrukowania
# ksi��ki z niezadrukowan� chocia� jedn� stron� wynosi
# 0.01. Obliczy� prawdopodobie�stwo, �e w nak�adzie
# 5000 ksi��ek odsetek wybrakowanych b�dzie poni�ej
# 1.5%. Zadanie rozwi�za� korzystaj�c z rozk�adu
# dwumianowego oraz CTG.

n = 5000
p = 0.01
q = 1-p

# S = X1 + ... + X1200
# P(S/5000 < 0.015) =
# P(S < 75) = 
# P(S <= 74)
pbinom(74,n,p) # 0.9994585

# CTG, P(S <= 74.5)

pnorm(74.5, n*p, sqrt(n*p*q)) # 0.9997514
