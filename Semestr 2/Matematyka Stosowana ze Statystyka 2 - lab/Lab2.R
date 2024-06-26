# Lab2

# ZAD 1
# Prawdopodobie�stwo, �e statystyczny student nie jest
# przygotowany do �wicze� wynosi 1/3. Nauczyciel wybiera
# przypadkowo 4 osoby. Niech X oznacza liczb� os�b
# spo�r�d wybranych, kt�re nie s� przygotowane do
# �wicze�. Wyznaczy� rozk�ad prawdopodobie�stwa
# tej zmiennej losowej. Obliczy� prawdopodobie�stwo, �e:
# a) liczba os�b nieprzygotowanych jest mniejsza ni� 2
# b) liczba os�b nieprzygotowanych wynosi co najmniej 3.

# rozklad dwumianowy, n = 4, p = 1/3

x = c(0:4)

pr = dbinom(x,4,1/3)

rozklad = cbind(x,pr)

plot(x,pr)

# a)
# P(X < 2) = P(X <= 1)

pbinom(1,4,1/3)

# b)
# P(X >= 3) = 1 - P(X < 3) = 1 - P(X <= 2)

1 - pbinom(2,4,1/3)
pbinom(2,4,1/3,F)

# ZAD 2
# Niech X oznacza liczb� samochod�w przeje�d�aj�cych
# w ci�gu minuty przez Plac Szarych Szereg�w w
# Szczecinie. Zmienna ta mo�e by� opisana za pomoc�
# rozk�adu Poissona z parametrem (intensywno�ci�)
# lampda=12.
# 1) Obliczy� prawdopodobie�stwo, �e w ci�gu minuty
# przejedzie przez ten plac:
# a) dok�adnie 15 samochod�w,
# b) od 7 do 13 samochod�w.
# 2) Prawdopodobie�stwo, �e liczba samochod�w
# przeje�d�aj�cych przez ten plac w ci�gu
# minuty jest nie wi�ksza ni� k wynosi 0.96.
# Wyznaczy� warto�� k.

# rozklad Poissona, lambda = 12

# 1) a) P(X = 15)
dpois(15,12)

# 1) b) P(7 <= X <= 13)
sum(dpois(c(7:13),12))

ppois(13,12) - ppois(6,12)

# 2) P(X <= k) = 0.96, k - kwantyl rzedu 0.96
qpois(0.96,12)

# ZAD 3
# Prawdopodobie�stwo awarii aparatury do�wiadczalnej
# w jednym do�wiadczeniu wynosi 0.02. Do�wiadczenia
# mo�na przeprowadza� dowoln� liczb� razy. Obliczy�
# prawdopodobie�stwo, �e pierwsza awaria zdarzy si�:
# a) w czwartym do�wiadczeniu,
# b) nie p�niej ni� w trzecim do�wiadczeniu.

# rozklad geometryczny, p = 0.02
# (zawsze jeden mniej)
# a) P(X = 3)
dgeom(3,0.02)

# b) P(X <= 2)
sum(dgeom(c(0:2),0.02))

pgeom(2,0.02)

# ZAD 4
# W sk�ad pewnego agregatu wchodzi 100 element�w
# okre�lonego rodzaju.Prawdopodobie�stwo uszkodzenia
# w ci�gu roku ka�dego z tych element�w wynosi 0.01
# i nie zale�y od stanu pozosta�ych. Obliczy�
# prawdopodobie�stwo uszkodzenia w ci�gu roku:
# a) dok�adnie dw�ch element�w,
# b) nie wi�cej ni� dw�ch element�w.
# W obu podpunktach obliczy� tak�e przybli�enie
# rozk�adem Poissona.

# a) P(X = 2) n = 100, p = 0.01

dbinom(2,100,0.01)

# rozklad poissona

dpois(2,100*0.01)

# b) P(X <= 2)

pbinom(2,100,0.01)

# rozklad poissona

ppois(2,100*0.01)

# ZAD 5
# W pewnej rodzinie dwoje spo�r�d czworga dzieci
# urodzi�o si� w niedziel�. Jakie jest
# prawdopodobie�stwo tego zdarzenia?

# p = 1/7

dbinom(2,4,1/7)

# ZAD 6
# Urz�dzenie sk�ada si� mi�dzy innymi z 750 lamp.
# Prawdopodobie�stwo awarii ka�dej lampy w ci�gu
# jednej doby pracy urz�dzenia jest jednakowe i
# wynosi 0.004. Obliczy� prawdopodobie�stwo, �e w
# ci�gu jednej doby pracy urz�dzenia ulegn� awarii
# co najmniej 3 lampy.

# P ()

pbinom(2,750,0.004,F)

# ZAD 7
# W rodzinie jest dziesi�cioro dzieci. Przyjmuj�c,
# �e prawdopodobie�stwo urodzenia si� ch�opca i
# dziewczynki jest r�wne obliczy� prawdopodobie�stwo,
# �e w danej rodzinie jest:
# a) pi�ciu ch�opc�w,
# b) ch�opc�w nie mniej ni� trzech i nie wi�cej
# ni� o�miu.

# p = 0.5, n = 10

dbinom(5,10,0.5)
# 0.2460938

sum(dbinom(c(3:8),10,0.5))
# 0.9345703

# ZAD 8
# Do�wiadczenie polega na rzucaniu dwiema kostkami
# do gry tak d�ugo, a� suma oczek wyniesie 3.
# Obliczy� prawdopodobie�stwo zdarze�:
# a) trzeba b�dzie wykona� pi�� rzut�w,
# b) suma oczek r�wna 3 nie pojawi si� w sze�ciu
# kolejnych rzutach.

dgeom(4,1/18)
# 0.04420111

# P(X >= 6) = 1 - P(X <= 5)
pgeom(5,1/18,F)
# 0.7096734

# ZAD 10
# Hazardzista kontynuuje gr� w ruletk�, obstawiaj�c
# zawsze �czerwone�, a� uda mu si� w ko�cu wygra�.
# Zak�adaj�c, �e prawdopodobie�stwo wypadni�cia pola
# czerwonego wynosi 18/38, a hazardzist� sta� jedynie
# na 5 zak�ad�w, oblicz prawdopodobie�stwo, �e: 
# a) uda mu si� wygra� w drugim podej�ciu,
# b) uda mu si� wygra�, nim wyda pieni�dze.

# a) P(X = 1)
dgeom(1,18/38)

# b) P(X <= 4)
pgeom(4,18/38)
