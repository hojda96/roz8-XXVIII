********************************************************************
This exercise is taken from the book “Opus Magnum C++11” by J. Grebosz, as far as I know there is no English version. 
In his book author suggests using Polish variable names, so I did. Comments are also in Polish. 

 

The complete list of exercises can be found on author website: 

https://ifj.edu.pl/private/grebosz/opus_php/wybor_rozdzialu.php 

********************************************************************



W układzie pomiarowym eksperymentu fizycznego dane (sygnały)  przychodzą z czterech niezależnych
kanałów  o umownych nazwach FRS, GER, HEC, DGF. Każda sytuacja przyjścia  sygnałów zwana
jest zdarzeniem. W danym zdarzeniu każdy  z tych sygnałów może wystąpić lub nie. Łatwo 
zauważyć, że możliwych jest 16 różnych  sytuacji. W trakcie pomiaru robiona jest statystyka
występowania  tych możliwych 16 typów zdarzeń. Robimy to tak, że  zajście poszczególnych
sytuacji zliczamy w 16-elementowej  tablicy o nazwie statystyka. W przypadku  wystąpienia danej
sytuacji inkrementowany jest przypisany jej  element tablicy statystyka.  
To przypisanie elementu tablicy statystyka  do danego typu zdarzenia jest dość sprytne. Zauważ,
 że mamy cztery sygnały, z których każdy może  w danym zdarzeniu wystąpić lub nie. Każdemu
z tych  czterech sygnałów przyporządkujemy więc jeden  z czterech bitów słowa w zapisie binarnym.
 
	[Po widok tej tabeli odsyłamy do książki]
   
W trakcie pomiaru sprawdzamy, czy w danym konkretnym zdarzeniu wybrany  sygnał jest obecny. Jeśli
tak, to bit tego sygnału  jest ustawiany na 1. Jeśli tego sygnału nie ma, jego bit  jest ustawiany
na zero. Ustawiając lub zerując w ten sposób  bity dla wszystkich czterech sygnałów, wytwarzamy
w rezultacie  jakąś liczbę binarną.  
Na przykład, jeśli w danym zdarzeniu sygnał FRS nie  wystąpił (0), sygnał GER nie wystąpił
(0),  sygnał HEC wystąpił (1) i sygnał DGF wystąpił  (1), tworzy to binarną liczbę 0011.
Taka liczba binarna  w postaci dziesiątkowej to 3. Zatem w tablicy statystyka  element o indeksie
3 przypisany jest do sytuacji wystąpienia  sygnałów HEC i DGF. Wartość tego elementu  3 inkrementujemy,
czyli niniejszym zwiększyliśmy licznik  odpowiadający wystąpieniu takiego typu zdarzenia. 
Łatwo obliczyć, że w tablicy statystyka  element o indeksie 15 (co binarnie zapisujemy jako
1111) odpowiada  sytuacji równoczesnego wystąpienia wszystkich sygnałów  FRS, GER, HEC, DGF.
 
Dla ułatwienia poniższa tabelka pokazuje wszystkie możliwe  kombinacje sygnałów, odpowiadający
im rozkład  zer i jedynek (binarnie) i wartość takiej liczby binarnej  (w postaci dziesiątkowej),
czyli numer elementu tablicy  statystyka, w którym zliczamy danego  typu zdarzenia.  
	[Po widok tej tabeli odsyłamy do książki]
   
To tyle tytułem wstępu. Teraz właściwe zadanie.  
1) Napisz program, w którym w funkcji main  będzie definicja takiej (lokalnej) tablicy statystyka,
 i wypełnij tę tablicę jakimiś przykładowymi  wartościami, co odpowiadało będzie zebraniem
statystyki  wystąpienia danych kombinacji sygnałów.  
2) Napisz funkcję, która tę statystykę wyświetli  na ekranie w taki mniej więcej sposób
(wartości liczbowe  są przykładowe):  
	Poszczegolne kombinacje wystapily nastepujaca liczbe razy
	Kombinacja: DGF  –> 346 razy
	Kombinacja: HEC  –> 652 razy
	Kombinacja: HEC DGF  –> 737 razy
	Kombinacja: GER  –>  277 razy
	Kombinacja: GER DGF  –> 444 razy
			...itd aż do kombinacji FRS GER HEC DGF...  
Jak widzisz, jest to wypisanie kolejnych elementów tablicy, z  tym że temu wypisowi towarzyszy
opis kombinacji sygnałów.  Gdyby jakaś kombinacja nie wystąpiła ani razu (wartość  danego
elementu tablicy statystyka byłaby  zerowa), wówczas oczywiście takiej linii statystyki nie
 wypisujemy.  
Uwaga: ten symboliczny opis kombinacji (np. „FRS HEC DGF")  musi być konstruowany na bieżąco
na podstawie  wyglądu binarnego zapisu numeru elementu tablicy, który  właśnie wypisujemy.
Opis ten nie może być więc  „zaszyty" na stałe w programie.  
Wskazówka: to znaczy, że mając kolejny element tablicy  o numerze n, należy sprawdzić, które
bity w  danym numerze n są ustawione na 1, i wypisać na ekranie  odpowiadające im nazwy sygnałów.
 
Na przykład, jeśli jest to element o indeksie 5, co binarnie  zapisujemy jako 0101, to znaczy,
że wystąpiły sygnały  GER i DGF i takie dwa teksty powinny się w opisie pojawić.  
Zatem Twoje zadanie polega na tym, byś napisał pętlę  for przebiegającą po wszystkich  elementach
tablicy statystyka i dla każdego  elementu wypisał właściwą mu kombinację sygnałów  (tekstów)
oraz wartość przechowywaną w tym elemencie  tablicy (czyli wartość licznika danej sytuacji).
 
3) Gdy napiszesz tę funkcję i będzie działała  poprawnie, pojawia się jeszcze jedno życzenie
eksperymentatora.  
Chciałby on mianowicie, aby wypisywane na ekranie kombinacje  pojawiały się nie tak jak są
umieszczone w tablicy  (po kolei), ale począwszy od najbardziej skomplikowanych kombinacji  do
najprostszych. Czyli najpierw powinna zostać wypisana linijka  ze statystyką kombinacji 4 sygnałów,
następnie  linijki z różnymi kombinacjami 3 sygnałów, potem  z kombinacjami 2 sygnałów,
a na końcu – wystąpienia  sygnałów pojedynczych.  
Zatem na przykład tak:  
Kombinacje 4-bitowe ***********
Kombinacja: FRS GER HEC DGF  -> 345 razy
Kombinacje 3-bitowe ***********
Kombinacja: GER HEC DGF  -> 161 razy
Kombinacja: FRS HEC DGF  -> 253 razy
Kombinacja: FRS GER DGF  -> 299 razy
Kombinacja: FRS GER HEC  -> 322 razy
Kombinacje 2-bitowe ***********
Kombinacja: HEC DGF  -> 69 razy
        ...itd. aż do kombinacji FRS (pojedynczej)...  
