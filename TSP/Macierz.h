#include <iostream>
#ifndef MACIERZ_H
#define MACIERZ_H

using namespace std;

class Macierz{  //*********************************************************klasa czysto abstrakcyjna
protected:
    int **tab_2D;
    int rozmiar;
public:
    Macierz(int rozmiar_tablicy);
    virtual ~Macierz();
    virtual int min_wart_kolumna(int nr_kolumny);
    virtual int min_wart_wiersza(int nr_wiersza);
    virtual int min_wart_kolumna_bez_0_pojedynczego(int nr_kolumny);
    virtual int min_wart_wiersza_bez_0_pojedynczego(int nr_wiersza);
    virtual void odejmij_wartosc_od_kolumny(int nr_kolumny, int wartosc);
    virtual void odejmij_wartosc_od_wiersza(int nr_wiersza, int wartosc);
    virtual void wyswietl_macierz();
    virtual int zwroc_wartosc(int nr_wiersza, int nr_kolumny);
    virtual void ustal_wartosc(int wartosc, int nr_wiersza, int nr_kolumny);
    virtual int najwieksza_suma() = 0;
    virtual int zwroc_numer_kolumny() = 0;
    virtual int zwroc_numer_wiersza() = 0;
    virtual void usuwanie_kolumny_wiersz(int nr_wiersza, int nr_kolumny) =0;
    virtual int ktora_kolumna() = 0;
    virtual int ktory_wiersz() = 0;

};



#endif // MACIERZ_H
