#include <iostream>
#include "Graf.h"
#include "Wezel.h"
#ifndef KRAWEDZ_H
#define KRAWEDZ_H

using namespace std;

class Krawedz: public Graf
{
    private:
        int wartosc;
    public:
        Krawedz();
        virtual ~Krawedz();
        void oblicz_wartosc(Wezel &w1, Wezel &w2);
        int zwroc_wartosc();

};

#endif // KRAWEDZ_H
