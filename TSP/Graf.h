#include <iostream>
#ifndef GRAF_H
#define GRAF_H

using namespace std;
class Graf
{   protected:
        int x_wspol, y_wspol, numer;
        string nazwa;

    public:
        Graf();
        virtual ~Graf();
        virtual int zwroc_x_wspol();
        virtual int zwroc_y_wspol();
        virtual int zwroc_numer();
        virtual string zwroc_nazwe();
};

#endif // GRAF_H
