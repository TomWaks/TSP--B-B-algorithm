#include <iostream>
#include <vector>
#include "Wezel.h"
#ifndef DROGA_H
#define DROGA_H

using namespace std;

class Droga{
    private:
    vector<Wezel*>sciezka; //****************** wektor bedzie przechowywal optymalna droge komiwojazera

    public:
        Droga();
        ~Droga();
        void dodaj(Wezel &obiekt); //********** dodanie obiektu typu 'Wezel' do wektora 'sciezka'
        Wezel* zwroc(int i); //**************** zwrocenie wskaznika na obiekt typu 'Wezel'
        int zwroc_rozmiar(); //**************** zwrocenie rozmiaru wektora

};



#endif // DROGA_H
