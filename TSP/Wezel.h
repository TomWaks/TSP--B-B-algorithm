#include <iostream>
#include "Graf.h"
#ifndef WEZEL_H
#define WEZEL_H

using namespace std;

class Wezel: public Graf
{
    private:
        static int licznik; //********* na jego podstawie numerujemy kolejne miasta
    public:
        Wezel();
        virtual ~Wezel();
        virtual void zmien_nazwe(); //* wczytujemy nazwe miasta z pliku TXT
        void wczytaj_wspol();  //****** wcztujemy wspolrzedne miasta z pliku TXT


};

#endif // WEZEL_H

