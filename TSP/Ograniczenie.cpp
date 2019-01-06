#include <iostream>
#include "Ograniczenie.h"

using namespace std;

Ograniczenie::Ograniczenie()
{
    LB = 0;
}

Ograniczenie::~Ograniczenie(){}

void Ograniczenie::zwieksz_LB(int wartosc)
{
    LB += wartosc;

}

int Ograniczenie::zwroc_LB()
{
    return LB;
}
