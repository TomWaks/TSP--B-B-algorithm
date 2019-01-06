#include <iostream>
#ifndef PRZEJSCIE_H
#define PRZEJSCIE_H

using namespace std;
class Przejscie
{
    int skad;
    int dokad;


    public:
        Przejscie();
        ~Przejscie();
        void przypisz_wartosc_skad(int wartosc);
        void przypisz_wartosc_dokad(int wartosc);
        int zwroc_wartosc_skad();
        int zwroc_wartosc_dokad();

};

#endif // PRZEJSCIE_H
