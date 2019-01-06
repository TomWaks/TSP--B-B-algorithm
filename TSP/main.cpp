#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Wyjatek.h"
#include "Wezel.h"
#include "Krawedz.h"
#include "Macierz.h"
#include "Relacja.h"
#include "Droga.h"
#include "Przejscie.h"
#include "Ograniczenie.h"
#define N -1
#define KTORY 2

using namespace std;

int zwroc_liczbe_miast()
{
    int l=0;
    fstream plik;
    if(KTORY == 1)
        plik.open( "wspolrzedne1.txt", std::ios::in);
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
         plik >> l;
    }
    else
         throw(Wyjatek("Blad otwarcia pliku! Nie mozna odczytac liczby miast!!!"));



    plik.close();

    return l;
}

void przejdz_dalej()
{
    cout << "\n\nNacisnij ENTER, aby kontynuowac";
    getchar();
    system("cls");
}

int main()
{
try{
    cout << "WITAJ!!!\nTen program rozwiazuje problem komiwojazera za pomoca metody B&B\n\n";
    cout << "Liczba miast:\t" << zwroc_liczbe_miast() << endl << endl;
    int l = zwroc_liczbe_miast();


//*******************************wczytanie nazw oraz wspolrzednych miast*******************************************************************************//

    Wezel w[l];
    for(int i=0; i<=l; i++)
        Graf *w = new Wezel();

    for(int i=0; i<l; i++)
        {
            w[i].zmien_nazwe();
            w[i].wczytaj_wspol();
            cout << "Miasto nr " << w[i].zwroc_numer() << " :\t" << w[i].zwroc_nazwe() << "("<<w[i].zwroc_x_wspol() << "," << w[i].zwroc_y_wspol() << ")" << endl;
        }



    Krawedz k[l][l]; //**************************tworzenie obiektow klasy Krawedz
    Droga sciezka;  //***************************tworzenie obiektu klasy Droga - bedzie przechowywal droge komiwojazera
    Macierz *m = new Relacja(l); //**************tworzymy obiekt klasy Relacja - zawiera on macierz odleglosci - polimorfizm
    Ograniczenie dolne_ograniczenie; //**********tworzymy obiekt klasy Ograniczenie - jest to laczny koszt podrozy komiwojazera
    Przejscie odcinek[l]; //*********************tworzenie klasy Przejscie

//***********************************************obliczanie odleglosci miedzy dwoma wezlami(miastami) na podstawie ich wspolrzednych************************************************


    for(int i=0; i<l ; i++)
        for(int j=0; j<l ; j++)
            k[i][j].oblicz_wartosc(w[i], w[j]);



//****************************wybor miasta poczatkowego**********************************************************************************************//

    int g = 0;
    cout << "\nWybierz miasto poczatkowe(podaj nr):\t";
    cin >> g;
    cin.clear();
    cin.ignore( 1000, '\n' );
    cout << "\nMiasto poczatkowe to: ";
    for(int i=0; i<l; i++)
        if(w[i].zwroc_numer() == g)
        {
            sciezka.dodaj(w[i]);
            cout << sciezka.zwroc(0)->zwroc_nazwe();
        }


    przejdz_dalej();













    cout << "Na podstawie wspolrzednych miast generujemy macierz odleglosci ( relacji ):\n";

//***********************************tworzenie obiektu klasy Relacja, jest to macierz odleglosci miedzy wezlami******************************************************************










//*************************************ustalenie wartosci w tablicy dynamicznej*********************************************************************************
    for(int i=0; i<l; i++)
        for(int j=0; j<l; j++)
            if(i!=j)
                m->ustal_wartosc(k[i][j].zwroc_wartosc(), i, j);
            else
                m->ustal_wartosc(N,i,j);



//*****************************szukamy minimum w kazdej kolumnie i odejmuje odpowiednio********************************************************************************
    for(int q=0; q<l; q++)
    {
             m->wyswietl_macierz();


            cout << "\nRedukujemy macierz relacji\n(wyszukujemy minimum w kolumnach i wierszach i odejmujemy), otrzymujemy:" << endl;

            for(int i=0; i<l; i++)
            {
                dolne_ograniczenie.zwieksz_LB(m->min_wart_kolumna(i));
                cout << "Minimum w " << i+1 << " kolumnie:\t" << m->min_wart_kolumna(i) << endl;
            }
            cout << "Odejmujemy powyzsze wartosci od poszczegolnych kolumn. Otrzymujemy:\n" << endl;
            for(int i=0; i<l; i++)
                m->odejmij_wartosc_od_kolumny(i, m->min_wart_kolumna(i));


            m->wyswietl_macierz();
            cout << "\nNastepnie wyszukujemy minima w wierszach:" << endl ;
            for(int i=0; i<l; i++)
            {
                cout<< "Minimum w " << i+1 << " wierszu:\t" << m->min_wart_wiersza(i) <<  endl;
                dolne_ograniczenie.zwieksz_LB(m->min_wart_wiersza(i));
            }
            cout << "I odejmuje od poszczegolnych wierszy, otrzymujemy:" << endl;

            for(int i=0; i<l; i++)
                m->odejmij_wartosc_od_wiersza(i, m->min_wart_wiersza(i));
            m->wyswietl_macierz();


            cout <<"\nLB = " << dolne_ograniczenie.zwroc_LB();

            przejdz_dalej();

            cout << "Teraz bedziemy redukowac macierz,a co za tym idzie wyznaczac pierwsze polaczenia\nNasza macierz relacji:" << endl << endl;
            m->wyswietl_macierz();

            cout << "\nDla kazdej wartosci macierzy relacji rownej zero okreslamy jaka liczbe mozemy \nodjac od danego wiersza oraz kolumny. Wybieramy pare najwieksza.\n\nW tym przypadku:\n\n";

            for(int i=0; i<l; i++)
            {
                cout << "Minimum w " << i+1 << " wierszu:\t" << m->min_wart_wiersza_bez_0_pojedynczego(i) <<  endl;
            }
            cout <<endl;
            for(int i=0; i<l; i++)
            {
                cout << "Minimum w " << i+1 << " kolumnie:\t" << m->min_wart_kolumna_bez_0_pojedynczego(i) << endl;
            }
            cout << "Suma:\t\t" << m->najwieksza_suma() << endl;
            cout << "Numer wiersz:\t" << m->zwroc_numer_wiersza() << endl;
            cout << "Numer kolumny:\t" << m->zwroc_numer_kolumny() << endl;

            cout << "\nUsuwamy wiersz " << m->zwroc_numer_wiersza() << " i kolumne " << m->zwroc_numer_kolumny() << " oraz\ndodajemy do LB wartosc " << m->najwieksza_suma();
            cout << "\nLB = " << dolne_ograniczenie.zwroc_LB();
            dolne_ograniczenie.zwieksz_LB(m->najwieksza_suma());
            cout << " + " << m->najwieksza_suma() << " = " << dolne_ograniczenie.zwroc_LB() << endl;

            odcinek[q].przypisz_wartosc_skad(m->zwroc_numer_wiersza());
            odcinek[q].przypisz_wartosc_dokad(m->zwroc_numer_kolumny());

            cout << "\nKomiwojazer bedzie podrozowal z ";
            for(int i=0; i<l; i++)
                if(w[i].zwroc_numer() == odcinek[q].zwroc_wartosc_skad() +1 )
                    cout << w[i].zwroc_nazwe();
            cout << " do ";
            for(int i=0; i<l; i++)
                if(w[i].zwroc_numer() == odcinek[q].zwroc_wartosc_dokad() +1 )
                    cout << w[i].zwroc_nazwe();

            m->usuwanie_kolumny_wiersz(m->zwroc_numer_wiersza(), m->zwroc_numer_kolumny());
            cout << endl << endl;
            przejdz_dalej();

    }


    for(int j=0; j<l; j++)
        for(int i=0; i<l; i++)
            if(sciezka.zwroc(j)->zwroc_numer() - 1 == odcinek[i].zwroc_wartosc_skad())
                sciezka.dodaj(w[odcinek[i].zwroc_wartosc_dokad()]);

    cout << "\n\nOptymalna droga komiwojazera to:\n\n" ;
    for(int i=0; i<sciezka.zwroc_rozmiar(); i++)
    {
        if(i<sciezka.zwroc_rozmiar() -1)
            cout << sciezka.zwroc(i)->zwroc_nazwe() << " ---> ";
        else
            cout << sciezka.zwroc(i)->zwroc_nazwe() << endl << endl;

    }

    cout << "a jej koszt to:\t" << dolne_ograniczenie.zwroc_LB() << endl << endl;

    cout << "\n\n\n\n\nProgram wykonal: Tomasz Waksmundzki" << endl;
    cout << "Grupa:\t\t 2E3 Elektornika" << endl;
    cout << "Przedmiot:\t PROE - Programowanie Obiektowe C++" << endl << endl;
}
catch(Wyjatek &excep)
    {
        cout << "ERROR : " << excep.what();

    }



    return 0;
}
