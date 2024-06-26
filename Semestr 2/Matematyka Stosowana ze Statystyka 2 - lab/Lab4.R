# Lab4

# P(X <= a) = p => (a-m)/sig = qnorm(p)

# ZAD 1

# Wiek komputer�w w pewnej firmie kszta�tuje si� zgodnie
# z rozk�adem normalnym.Ustali� prawdopodobie�stwo
# wylosowania komputera, kt�ry ma od 3 do 6 lat, przy
# za�o�eniu, �e:
# a) w�r�d 200 komputer�w 100 ma powy�ej 5 lat, a
# sig =1;
# b) prawdopodobie�stwo wylosowania komputera, kt�ry
# ma poni�ej 6 lat wynosi 0.6 a sig^2 = 4.


# X - wiek komputerow

# P(3 <= X <= 6) = ?

# a) 

# P(X > 5) = 0.5
# P(X <= 5) = 0.5

sig = 1

# (5-m)/sig = qnorm(0.5) /* sig
# 5-m = qnorm(0.5) * sig
# m = 5 - sig * qnorm(0.5)

pnorm(6,m,sig) - pnorm(3,m,sig)

# b) 

# P(X < 6) = 0.6
sig = 2

# (6 - m)/sig = qnorm(0.6)

m = 6 - sig * qnorm(0.6)

pnorm(6,m,sig) - pnorm(3,m,sig)

# ZAD 2
# Przeci�tny wska�nik rentowno�ci obrotu brutto
# podmiot�w gospodarczych w sektorze publicznym
# wynosi 5.2%. Zak�adaj�c, �e wska�nik ten mo�na
# aproksymowa� za pomoc� rozk�adu normalnego,
# obliczy� warto�� odchylenia standardowego,
# wiedz�c, �e 12.1% podmiot�w gospodarczych osi�ga
# wska�nik rentowno�ci poni�ej 3%. Okre�li� warto��
# kwantyla rz�du 0.8.

# m = 5.2% = 5.2

# P(X < 3) = 12.1% = 0.121

# (3 - m)/ sig = qnorm(0.121)

m = 5.2
sig = (3 - m) / qnorm(0.121)

qnorm(0.8, m, sig)

# ZAD 3
# Wyk�adowca prowadz�cy wyk�ad z matematyki
# stosowanej ze statystyk� II przychodzi do sali na
# og� 5 minut przed wyznaczon� godzin� rozpocz�cia
# zaj��. Zak�adaj�c, �e czas przyj�cia jest zmienn�
# losow� o rozk�adzie normalnym, okre�li�, jakie jest
# prawdopodobie�stwo sp�nienia si� tego wyk�adowcy
# na zaj�cia, je�eli wiadomo, �e w oko�o 95%
# przypadk�w wyk�adowca jest w sali co najmniej
# 3 minuty przed rozpocz�ciem zaj��.

m = -5

# P(X <= -3) = 0.95
# (-3 - m)/sig = qnorm(0.95)

sig = (-3 - m) / qnorm(0.95)

pnorm(0, m, sig, F)


# ZAD 4

m = 0.46

# P(X > 0.5) = 0.4

# (50 - m) / sig = 1 - qnorm(0.46)
# (50 - m) = (1 - qnorm(0.46)) * sig
# (50 - m) / (1 - qnorm(0.46)) = sig

sig = (0.5 - m) / qnorm(0.6)

# a) 
pnorm(0.7, m, sig, F)

# b)
qnorm(0.9, m, sig)

# ZAD 5

m = 86.5

# P(82.5 <= X <= 90.5) = 0.3472

# P(X <= 82.5) = (1 - 0.3472) / 2

# (82.5 - m) / sig = qnorm((1 - 0.3472) / 2)

sig = (82.5 - m) / qnorm((1 - 0.3472) / 2)

pnorm(95, m, sig, F) * 400
