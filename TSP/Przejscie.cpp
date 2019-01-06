#include <iostream>
#include "Przejscie.h"

using namespace std;

Przejscie::Przejscie()
{
    skad = 0;
    dokad = 0;
}

Przejscie::~Przejscie(){}

void Przejscie::przypisz_wartosc_skad(int wartosc)
    {
        this->skad = wartosc;
    }

void Przejscie::przypisz_wartosc_dokad(int wartosc)
    {
        this->dokad = wartosc;
    }
int Przejscie::zwroc_wartosc_skad()
    {
        return skad;
    }
int Przejscie::zwroc_wartosc_dokad()
    {
        return this->dokad;
    }
