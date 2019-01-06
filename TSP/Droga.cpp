#include <iostream>
#include <vector>
#include "Wezel.h"
#include "Droga.h"


using namespace std;

Droga::Droga(){}

Droga::~Droga(){}

void Droga::dodaj(Wezel &obiekt)
{
    this->sciezka.push_back(&obiekt);
}

Wezel* Droga::zwroc(int i)
{
    return sciezka[i];
}

int Droga::zwroc_rozmiar()
{
    return  this->sciezka.size();
}

