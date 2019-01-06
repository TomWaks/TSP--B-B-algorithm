#include <iostream>
#include <limits>
#include "Macierz.h"
#define INFTY INT_MAX

using namespace std;


Macierz:: Macierz(int rozmiar_tablicy): rozmiar(rozmiar_tablicy)
{
    tab_2D = new int *[this->rozmiar]; //alokacja pamieci
    for(int i=0; i<this->rozmiar; ++i)
    {
        this->tab_2D[i] = new int [rozmiar]; //alokacja pamieci
        for(int j=0; j < this->rozmiar; ++j) //wpisanie wartosci do tablicy
            this->tab_2D[i][j] = 0;
    }
}

Macierz::~Macierz()
{
    for(int i=0; i<rozmiar; i++)
        delete [] tab_2D[i];
}

int Macierz::min_wart_kolumna(int nr_kolumny)
{
    int tmp = INFTY;
    for(int i=0 ; i<this->rozmiar; i++)
        {
          if(tab_2D[i][nr_kolumny] >= 0)
            if(tmp>tab_2D[i][nr_kolumny])
                tmp = tab_2D[i][nr_kolumny];
        }
    if(tmp == INFTY)
        tmp =0;

    return tmp;
}

int Macierz::min_wart_wiersza(int nr_wiersza)
{
    int tmp = INFTY;
    for(int i=0 ; i<this->rozmiar; i++)
        {
            if(tab_2D[nr_wiersza][i] >= 0)
                if(tmp > this->tab_2D[nr_wiersza][i])
                    tmp = this->tab_2D[nr_wiersza][i];
        }
    if(tmp == INFTY)
        tmp =0;


    return tmp;
}

int Macierz::min_wart_kolumna_bez_0_pojedynczego(int nr_kolumny)
{
    int tmp = INFTY;
    int z = 0;
    for(int i=0; i<this->rozmiar; i++)
    {
        if(this->tab_2D[i][nr_kolumny]==0)
            z++;
    }

    if(z<2)
    {
        for(int i=0 ; i<this->rozmiar; i++)
            {
                if(this->tab_2D[i][nr_kolumny] > 0)
                    if(tmp > this->tab_2D[i][nr_kolumny])
                        tmp = this->tab_2D[i][nr_kolumny];
            }
    }
    else
        tmp = 0;
    if(tmp == INFTY)
        tmp =0;

    return tmp;
}

int Macierz::min_wart_wiersza_bez_0_pojedynczego(int nr_wiersza)
{
    int z=0;
    int tmp = INFTY;
    for(int i=0; i<this->rozmiar; i++)
    {
        if(this->tab_2D[nr_wiersza][i] == 0)
            z++ ;
    }
    if(z<2)
    {
        for(int i=0 ; i<this->rozmiar; i++)
        {
            if(this->tab_2D[nr_wiersza][i] > 0)
                if(tmp>this->tab_2D[nr_wiersza][i])
                    tmp = this->tab_2D[nr_wiersza][i];
        }
    }
    else
        tmp = 0;

    if(tmp == INFTY)
        tmp =0;
    return tmp;
}

void Macierz::odejmij_wartosc_od_kolumny(int nr_kolumny, int wartosc)
{
    for(int i=0; i<this->rozmiar; i++)
        if(nr_kolumny!=i && this->tab_2D[i][nr_kolumny] != -1)
            this->tab_2D[i][nr_kolumny] -= wartosc;
}

void Macierz::odejmij_wartosc_od_wiersza(int nr_wiersza, int wartosc)
{
    for(int i=0; i<this->rozmiar; i++)
        if(nr_wiersza!=i && this->tab_2D[nr_wiersza][i] != -1)
            this->tab_2D[nr_wiersza][i] -= wartosc;
}

void Macierz::wyswietl_macierz()
{
    cout << endl;
    for(int i=0; i<this->rozmiar; i++)
    {
        for(int j=0; j<this->rozmiar; j++)
            cout << this->tab_2D[i][j] << "\t";
        cout << endl;
    }
}

void Macierz::ustal_wartosc(int wartosc, int nr_wiersza, int nr_kolumny)
{
    this->tab_2D[nr_wiersza][nr_kolumny] = wartosc;
}

int Macierz::zwroc_wartosc(int nr_wiersza, int nr_kolumny)
{
    return this->tab_2D[nr_wiersza][nr_kolumny];
}
