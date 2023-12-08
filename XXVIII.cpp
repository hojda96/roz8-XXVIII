#include <iostream>

using namespace std;

void wypisz(int tablica[]) {
    for (int i = 0; i < 16; i++) {

        if (tablica[i] == 0) continue;//jesli puste, nie wypsiujemy
        cout << "Kombinacja: ";

        if (i == 0) {
            cout << "bez sygnalow ";
        }

        if (i & 8) {
            cout << "FRS ";
        }

        if (i & 4) {
            cout << "GER ";
        }

        if (i & 2) {
            cout << "HEC ";
        }

        if (i & 1) {
            cout << "DGF ";
        }

        cout << tablica[i] << " razy\n";
    }
}

void wypiszkolejno(int tablica[]) {
    for (int j = 4; j >= 0; j--) {

        for (int i = 0; i < 16; i++) {
            int liczba_sygnalow = 0;
            if (tablica[i] == 0) continue;//jesli puste, nie wypsiujemy
            if (i & 8) liczba_sygnalow++;
            if (i & 4) liczba_sygnalow++;
            if (i & 2) liczba_sygnalow++;
            if (i & 1) liczba_sygnalow++;


            if (liczba_sygnalow == j) {
                cout << "Kombinacja " << j << " sygnalow: ";

                if (i == 0) {
                    cout << "bez sygnalow ";
                }

                if (i & 8) {
                    cout << "FRS ";
                }

                if (i & 4) {
                    cout << "GER ";
                }

                if (i & 2) {
                    cout << "HEC ";
                }

                if (i & 1) {
                    cout << "DGF ";
                }

                cout << tablica[i] << " razy\n";
            }
        }
    }
}

int main()
{
    int i = 3;
    int tab[16] = { 432,43,42,7,0,32,876,43,24,0,143,753,546,415,543,43 };

    wypisz(tab);
    cout << "\n\n";
    wypiszkolejno(tab);
}