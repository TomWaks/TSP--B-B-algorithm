#include <iostream>
#include <limits>
#include "Relacja.h"

using namespace std;

Relacja::Relacja(int rozmiar_tablicy=0): Macierz(rozmiar_tablicy), numer_wiersza(0), numer_kolumny(0) {}

Relacja::~Relacja()
{
    for(int i=0; i<rozmiar; i++)
        delete [] tab_2D[i];
}

int Relacja::najwieksza_suma()
{
    int tmp = -1;
    for(int i=0; i<this->rozmiar; i++)
    {
        for(int j=0; j<this->rozmiar; j++)
        {
            if(tab_2D[i][j] == 0)
            {
                if(tmp < this->min_wart_kolumna_bez_0_pojedynczego(j) + this->min_wart_wiersza_bez_0_pojedynczego(i))
                {

                    tmp = this->min_wart_kolumna_bez_0_pojedynczego(j) + this->min_wart_wiersza_bez_0_pojedynczego(i);
                    this->numer_wiersza = i;
                    this->numer_kolumny = j;
                }


            }
        }
    }
    return tmp;
}

void Relacja::usuwanie_kolumny_wiersz(int nr_wiersza, int nr_kolumny)
{
    for(int i=0; i< this->rozmiar; i++)
        for(int j=0; j< this->rozmiar; j++)
            if(i == nr_wiersza || j == nr_kolumny || (j == nr_wiersza && i == nr_kolumny ))
                this->ustal_wartosc(-1, i, j);
}

int Relacja::zwroc_numer_kolumny()
{
    return this->numer_kolumny;
}

int Relacja::zwroc_numer_wiersza()
{
    return this->numer_wiersza;
}

int Relacja::ilosc_liczb_wiekszych_kolumna(int n_kolumny)
{
    int q = 0;
    for(int i=0; i<this->rozmiar; i++)
    {
        if(this->tab_2D[i][n_kolumny] > -1 )
            q++;
    }

    return q;

}

int Relacja::ilosc_liczb_wiekszych_wiersz(int n_wiersza)
{
    int q = 0;
    for(int i=0; i<this->rozmiar; i++)
    {
        if(this->tab_2D[n_wiersza][i] > -1 )
            q++;
    }

    return q;
}

int Relacja::ktora_kolumna()
{
        int y = 0;
        for(int i=0; i<this->rozmiar; i++)
        {
            if(this->ilosc_liczb_wiekszych_kolumna(i) == 2 )
            {
                y = i ;
                break;
            }
        }

        return y;
}

int Relacja::ktory_wiersz()
{
        int y = 0;
        for(int i=0; i<this->rozmiar; i++)
        {
            if(this->ilosc_liczb_wiekszych_wiersz(i) == 2 )
            {
                y = i ;
                break;
            }
        }

        return y;
}
