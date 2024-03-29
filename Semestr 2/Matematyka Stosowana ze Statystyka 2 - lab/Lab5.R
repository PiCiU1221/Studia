# Lab 5

# ZAD 1 
# Przeci�tne miesi�czne wynagrodzenie brutto w
# gospodarce narodowej w roku 2016 wynios�o 4001.50 z�.
# Wiadomo, �e 15% zatrudnionych w tej grupie osi�ga
# zarobki od 3503 do 4500 z�. Przyjmuj�c, �e rozk�ad
# p�ac jest normalny, obliczy� jakiej wysoko�ci
# pensje otrzymuje 25% najwi�cej zarabiaj�cych w tym
# sektorze.

m = 4001.50

# P(3503 <= X <= 4500) = 15%

sig = (3503 - m) / qnorm((1 - 0.15) / 2)

qnorm(0.75, m, sig)

# ZAD 2
# Decyl trzeci miesi�cznego wynagrodzenia brutto
# w wojew�dztwie zachodniopomorskim w pa�dzierniku
# 2018 roku w grupie przedstawicieli w�adz
# publicznych, wy�szych urz�dnik�w i kierownik�w
# wynosi� 5281.21 z� za� kwartyl g�rny 9090.90 z�.
# Przyjmuj�c, �e rozk�ad p�ac jest normalny,
# wyznaczy�
# a) procent pracownik�w zarabiaj�cych mniej ni�
# 3200 z� brutto,
# b) procent pracownik�w zarabiaj�cych ponad 7800 z�
# brutto,
# c) maksymalne wynagrodzenie brutto otrzymywane
# przez 15% pracownik�w najmniej zarabiaj�cych
# w tym sektorze.

# A = [ 1 qnorm(p1)]    B = [ a1 ]
#     [ 1 qnorm(p2)]        [ a2 ]

# a) P(X <= 5281.21) = 0.3
#    P(X <= 9090.9) = 0.75

# (5282.21 - m) / sig = qnorm(0.3)
# (9090.9 - m) / sig = qnorm(0.75)

# m + sig * qnorm(0.3) = 5281.21
# m + sig * qnorm(0.75) = 9090.9

A = matrix(c(1,1,qnorm(0.3),qnorm(0.75)),2,2)
B = matrix(c(5281.21,9090.9),2,1)

m = solve (A,B) [1]
sig = solve (A,B) [2]

pnorm(3200, m, sig)

# b) 

pnorm(7800, m, sig, F)

# c)

qnorm(0.15, m, sig)


# ZAD 3
# Czas trwania zakup�w dla 20% klient�w sklepu
# Ikea wynosi ponad 2 godziny, a dla 44% poni�ej
# 1.5 godz. Zak�adaj�c, �e czas trwania zakup�w
# mo�na okre�li� za pomoc� rozk�adu normalnego,
# wyznaczy�:
# a) prawdopodobie�stwo spotkania klienta, kt�rego
# czas pobytu w sklepie wynosi kr�cej ni� 0.5 godziny,
# b) procent klient�w, kt�rzy sp�dzaj� w sklepie
# Ikea ponad 2.5 godziny,
# c) czas graniczny 13% klient�w, kt�rzy robi�
# zakupy najd�u�ej.

# P(X >= 2) = 0.2  (odwracamy gdy X >=)
# P(X <= 1.5) = 0.44

A = matrix(c(1,1,qnorm(0.8),qnorm(0.44)),2,2)
B = matrix(c(2,1.5),2,1)

m = solve (A,B) [1]
sig = solve (A,B) [2]

# a)
pnorm(0.5, m, sig)

# b)
pnorm(2.5, m, sig, F)

# c)
qnorm(0.87, m, sig)


# ZAD 4
# �rednia wzrostu doros�ych kobiet w Polsce to
# oko�o 165 cm i wiadomo, �e oko�o 93 % kobiet
# mierzy co najmniej 155 cm i nie wi�cej ni� 175 cm.
# Wiedz�c, �e wzrost kobiet ma rozk�ad normalny,
# okre�li� ile kobiet w�r�d 500 b�dzie mierzy�
# powy�ej 170 cm.

m = 165

# P(155 =< X <= 175) = 0.93

# P(X >= 155)
# P(X <= 175)

sig = (155 - m) / qnorm((1 - 0.93) / 2)

# P(X >= 170) * 500 = ?

pnorm(170, m, sig, F) * 500

# ZAD 5
# Rozk�ad wynik�w kolokwium 1. z matematyki
# stosowanej ze statystyk� 2 na zaj�ciach
# laboratoryjnych z wykorzystaniem �rodowiska R
# mo�na szacowa� za pomoc� rozk�adu normalnego.
# Wynik bardzo dobry (ponad 90%) zwykle osi�ga
# jedna osoba w grupie 12 student�w, natomiast
# 2 osoby na 12 nie zalicza w pierwszym terminie
# (nie osi�ga 50%). Jaki minimalny wynik osi�ga
# 10% najlepiej przygotowanych student�w?

# P(X >= 90) = 1/12
# P(X < 50) = 2/12

A = matrix(c(1,1,qnorm(11/12),qnorm(2/12)),2,2)
B = matrix(c(90,50),2,1)

m = solve (A,B) [1]
sig = solve (A,B) [2]

qnorm(0.90, m, sig) #88.27362

# ZAD 6
# Badania Pomorskiego Uniwersytetu Medycznego w
# Szczecinie wykaza�y, �e wiek pacjent�w leczonych
# z powodu raka krtani ma rozk�ad normalny.
# W analizowanym okresie na 524 pacjent�w tylko
# 2 by�o poni�ej 17 roku �ycia oraz 7
# przekroczy�o 70 lat. Wyznaczy� prawdopodobie�stwo,
# �e leczenia z powodu raka krtani wymaga� b�d�
# osoby w wieku od 45 do 55 lat.

# P(X <= 17) = 2/524
# P(X >= 70) = 7/524

A = matrix(c(1,1,qnorm(2/524),qnorm(517/524)),2,2)
B = matrix(c(17,70),2,1)

m = solve (A,B) [1]
sig = solve (A,B) [2]

# P(45 <= X <= 55) = ?

pnorm(55,m,sig) - pnorm(45,m,sig) #0.3327448