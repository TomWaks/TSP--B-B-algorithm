#include <iostream>
#include <string>
#include <math.h>
#include "Krawedz.h"

using namespace std;


Krawedz::Krawedz(): Graf()
{
    wartosc = 0;
}

Krawedz::~Krawedz(){}

void Krawedz::oblicz_wartosc(Wezel &w1, Wezel &w2)
{
    this->wartosc = sqrt(pow((w1.zwroc_x_wspol() - w2.zwroc_x_wspol()) , 2) + pow((w1.zwroc_y_wspol() - w2.zwroc_y_wspol()) , 2));
}

int Krawedz::zwroc_wartosc()
{
    return this->wartosc;
}
