#include <iostream>
#include "Graf.h"
using namespace std;
Graf:: Graf()
{
    nazwa = "brak1";
    x_wspol = 0;
    y_wspol = 0;
    numer = 0;

}

Graf::~Graf(){}

int Graf::zwroc_x_wspol()
{
    return this->x_wspol;
}

int Graf::zwroc_y_wspol()
{
    return this->y_wspol;
}

int Graf::zwroc_numer()
{
    return this->numer;
}

string Graf::zwroc_nazwe()
{
    return this->nazwa;
}
