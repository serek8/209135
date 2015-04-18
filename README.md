# 209135
Zajęcia z Projektowania Algorytmów Sztucznej Inteligencji

<h1>Raport</h1>
<h2>Sortowanie przez scalanie</h2>

Poprawiona wersja sortowania przez Scalanie.

Wysokość drzewa sortowania to O(log n)
	- przy kazdym wywołaniu rekurencyjnym dzielimy sekwencje na pół
Ilość operacji wykonywanych na węzłach na poziomie i to O(n)
	- dzielimy i scalamy 2^i sekwencji o rozmiarze n/2
	- wykonujemy 2^(i+1) wywołań rekurencyjnych

Czyli cała złożoność obliczeniowa sortowania przez scalanie wynosi O(n*log(n))

Wykokane pomiary to:
![alt tag](https://github.com/serek8/209135/tree/Lab_6/sprawozdanie/mergesort.png)
Co zgadza się z założeniem o złożonośi obliczniowej sortowania przez scalanie.
<br />
