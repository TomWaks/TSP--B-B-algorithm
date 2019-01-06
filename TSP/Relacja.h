#include <iostream>
#ifndef RELACJA_H
#define RALACJA_H
#include "Macierz.h"

using namespace std;

class Relacja: public Macierz{  //************************************* klasa pochodna po klasie 'Macierz'
private:
    int numer_wiersza, numer_kolumny;
public:
    Relacja(int rozmiar_tablicy);
    virtual ~Relacja();
    virtual int najwieksza_suma();
    int zwroc_numer_kolumny();
    int zwroc_numer_wiersza();
    void usuwanie_kolumny_wiersz(int nr_wiersza, int nr_kolumny); // przez usuniecie rozumiemy ustawienie wartosci '-1'
    int ilosc_liczb_wiekszych_kolumna(int n_kolumny);
    int ilosc_liczb_wiekszych_wiersz(int n_wiersza);
    int ktora_kolumna();
    int ktory_wiersz();
};
#endif // RELACJA_H
