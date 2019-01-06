#include <iostream>
#ifndef OGRANICZENIE_H
#define OGRANICZENIE_H

using namespace std;

class Ograniczenie{
private:
    int LB;
public:
    Ograniczenie();
    ~Ograniczenie();
    void zwieksz_LB(int wartosc);
    int zwroc_LB();


};

#endif // OGRANICZENIE_H
