# Lab3

# N(m,sig)

# P(X <= a) = pnorm(a, m, sig)
# P(X > a) = 1 - pnorm(a, m, sig) = pnorm(a, m, sig, F)
# P(a < X <= b) = pnorm(b, m, sig) - pnorm(a, m, sig)

# qnorm(p, m, sig)

# ZAD 1
# a) u(0.97) N(0,1)

qnorm(0.97, 0, 1)
qnorm(0.97)

# b) chi kwadrat(0.975;9);

qchisq(0.975,9)

# c) t(0.95,9)

qt(0.95,9)

# d) F(0.995;10;23)

qf(0.995,10,23)

# ZAD 2
# a) P(X < 2.5)

pnorm(2.5, 1.5, 2) 

# b) P(X > -0.5) 

pnorm(-0.5, 1.5, 2, F)


# c) P(0.5 < X < 2)

pnorm(2, 1.5, 2) - pnorm(0.5, 1.5, 2)

# |x| <= 2 <=> -2 <= x <= 2
# |x| > 2 <=> x < -2 lub x > 2

# P(|5x - 3| < 2) = P(-2 < 5x-3 < 2) = P(1 < 5x < 5) =
# P(1/5 < x < 1)

# P(|4x-3| > 1) = P(4x-3 < -1) + P(4x-3 > 1) =
# = P(4x < 2) + P(4x > 4) = P(x < 1/2) + P(x > 1) =
# = pnorm(1/2, m, sig) + pnorm(1, m ,sig, F)

# d) P(|X - 2| < 3) = P(-3 < x-2 < 3) = P(0 < x < 5)

pnorm(5, 1.5, 2) - pnorm(-1, 1.5, 2)

# e) P(|2X - 1| < 1) = P(-1 < 2x-1 < 1) = 
# = P(0 < 2x < 2) = P(0 < x < 1)

pnorm(1, 1.5, 2) - pnorm(0, 1.5, 2)

# f) P(|X| > 0.5) = P(x < -0.5) + P(x > 0.5)

pnorm(-0.5, 1.5, 2) + pnorm(0.5, 1.5, 2, F)

# g) P(|3x - 1| > 2) = P(3x-1 < -2) + P(3x-1 > 2) =
# = P(3x < -1) + P(3x > 3) = P(x < -1/3) + P(x > 1)

pnorm(-1/3, 1.5, 2) + pnorm(1, 1.5, 2, F)

# ZAD 3
# Czas �wiecenia �ar�wek pochodz�cych z masowej
# produkcji jest zmienn� losow� X o rozk�adzie
# normalnym N(1000 h, 50 h). Oblicz, ile przeci�tnie
# �ar�wek spo�r�d 4000 �wieci kr�cej ni� 900 h.

# N(1000, 50)

# P(x <= 900)

pnorm(900, 1000, 50) * 4000

# ZAD 4
# Przy za�o�eniu, �e wyniki w skoku w dal maj� rozk�ad
# normalny o parametrach 6.8m oraz 0.3 m:
# a) obliczy� ilu zawodnik�w na 30 osi�gnie w skoku
# w dal co najmniej 7.1 m;
# b) jaki wynik uzyskali zawodnicy, poni�ej kt�rego
# jest 15% najs�abszych rezultat�w?

# N(6.8,0.3)

# a)
# P(x > 7.1)

pnorm(7.1, 6.8, 0.3, F) * 30

# b)
# P(X < k) = 0.15
# P(x < 7.1)

qnorm(0.15, 6.8, 0.3)

# ZAD 5
# Op�nienie poci�gu do stacji A jest zmienn� losow�
# o rozk�adzie normalnym N(15 min; 13 min). Obliczy�
# prawdopodobie�stwo, �e:
# a) poci�g, kt�ry mia� przyjecha� o 22:00 przyjedzie
# mi�dzy 22:05 a 22:10;
# b) ten sam poci�g przyjedzie po 22:20.

# N(15, 13)

# a)
# P(5 < X < 10)

pnorm(10,15,13)-pnorm(5,15,13)

# b)
# P(x > 20)

pnorm(20,15,13,F)

# ZAD 6
# Zmienna losowa ma rozk�ad N(20, 5). Wyznaczy�
# nieznane warto�ci k1, k2, k3, k4, je�eli wiadomo,
# �e zmienna ta przyjmuje warto��:
# a) mniejsz� ni� k1 z prawdopodobie�stwem 0.8849;
# b) wi�ksz� od k2 z prawdopodobie�stwem 0.6554;
# c) odchylaj�c� si� od �redniej nie wi�cej ni� o
# k3 z prawdopodobie�stwem 0.6826;
# d) odchylaj�c� si� od �redniej nie mniej ni� o
# k4 z prawdopodobie�stwem 0.00511.

# N(20, 5)
# a)

# P(X < k1) = 0.8849

qnorm(0.8849,20,5)

# k1 = 0.8849

# b)

# P(X > k2) = 0.6554

qnorm(0.6554,20,5, F)

# c)

# (1-0.6826) / 2

# 20 - k3 = qnorm((1-0.6826) / 2, 20, 5)
# k3 = 20-qnorm((1-0.6826) / 2, 20, 5)

20-qnorm((1-0.6826) / 2, 20, 5)

# d)

20-qnorm(0.00511/2, 20, 5)
