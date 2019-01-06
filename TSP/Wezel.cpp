#include <iostream>
#include <fstream>
#include "Wezel.h"
#include "Wyjatek.h"
#define KTORY 2

using namespace std;

int Wezel::licznik = 0;
Wezel::Wezel():Graf()
{
    licznik++;
    numer = licznik;
    nazwa = "BRAK";
}

Wezel::~Wezel(){}

void Wezel::zmien_nazwe()
{
    fstream plik;

    if(KTORY == 1)
         plik.open("miasta1.txt", ios::in);
    else
    {
        if(KTORY == 2)
             plik.open("miasta2.txt", ios::in);
        else
        {
            if(KTORY == 3)
                 plik.open("miasta3.txt", ios::in);

        }
    }

    if(plik.good() == true)
    {
        for(int i=0; i<this->numer; i++)
        plik >> this->nazwa;
    }
    else
         throw(Wyjatek("Blad otwarcia pliku! Nie mozna odczytac liczby miast!!!"));





    plik.close();

}

 void Wezel::wczytaj_wspol()
 {
    fstream plik;
    char w_powietrze=0;

    if(KTORY == 1)
        plik.open("wspolrzedne1.txt", ios::in);
    else
    {
        if(KTORY == 2)
            plik.open( "wspolrzedne2.txt", std::ios::in);
        else
        {
            if(KTORY == 3)
                plik.open( "wspolrzedne3.txt", std::ios::in);

        }
    }

    if(plik.good() == true)
    {
         plik >> w_powietrze;
        for (int i=0; i<this->numer;i++)
        {
            plik >> this->x_wspol;
            plik >> this->y_wspol;
        }
    }
    else
         throw(Wyjatek("Blad otwarcia pliku! Nie mozna odczytac liczby miast!!!"));




    plik.close();
}
