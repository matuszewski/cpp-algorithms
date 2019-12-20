#include <iostream>
#include <fstream>
#include "matrix_functions.cpp"
using namespace std;
// y    x (czyli inaczej niz w matematyce)

float **utworzTablice(int, int);
void wypiszTablice(float **t, int, int);
void wczytajDane(const char *nazwa, float **t, int r1, int r2);
float wyznacznik2D(float **t, int);
void usunTablice(float **&t, int);
void transponujTablice(float **wejsciowa, float **wyjsciowa, int r1, int r2);

void zapiszTablice(float **t, int r1, int r2, const char *nazwa);

void zapiszTablice(float **t, int r1, int r2, const char *nazwa)
{
    ofstream zapis;
    zapis.open(nazwa, ios::app);
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < r2; j++)
        {
            zapis << t[i][j] << " ";
            if (j == r2 - 1)
            {
                zapis << "\n";
            }
        }
    }
    zapis.close();
}

void sumujTablice(float **t, float **u, float **w, int r1, int r2)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            w[i][j] = t[i][j] + u[i][j];
        }
    }
}

int main()
{
    // tablica 1
    float **tab1 = utworzTablice(5, 5);
    wczytajDane("dane.txt", tab1, 5, 5);
    cout << endl;
    cout << "tablica tab1:" << endl;

    wypiszTablice(tab1, 5, 5);
    cout << endl;
    inkrementujTablice(tab1, 5, 5);
    cout << "tablica tab1 + 1:" << endl;

    wypiszTablice(tab1, 5, 5);

    cout << endl;

    cout << "tablica tab2 transponowana z tab1:" << endl;
    float **tab2 = utworzTablice(5, 5);
    transponujTablice(tab1, tab2, 5, 5);
    wypiszTablice(tab2, 5, 5);

    //float w = wyznacznik2D(tab1, 2);

    //tablica3
    float **tab3 = utworzTablice(4, 7);
    wczytajDane("dane3.txt", tab3, 4, 7);
    cout << endl;
    cout << "tab3 o wymiarach 4x7:" << endl;
    wypiszTablice(tab3, 4, 7);

    float **sumowana = utworzTablice(5, 5);
    sumujTablice(tab1, tab2, sumowana, 5, 5);

    cout << endl
         << "SUMOWANIE TABLIC:" << endl;

    wypiszTablice(sumowana, 5, 5);

    zapiszTablice(sumowana, 5, 5, "tablica_sumowana_wyjscie.txt");
    return 0;
}

float **utworzTablice(int r1, int r2)
{
    //tworzymy tablice 2x2 dynamicznie
    float **t = new float *[r1];
    for (int i = 0; i < r1; i++)
    {
        t[i] = new float[r2];
    }

    //ustawiamy wartosci poczatkowe
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < r2; j++)
        {
            t[i][j] = 0.0;
        }
    }
    return t;
}

void wypiszTablice(float **t, int r1, int r2)
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < r2; j++)
        {
            //cout << t[i][j] << " ";   //wypisanie wszystiego w linii
            cout.width(4);
            cout << t[i][j] << " ";
            if (j == r2 - 1)
            {

                cout << endl;
            }
        }
    }
}

void wczytajDane(const char *nazwa, float **t, int r1, int r2) // do funkcji podajemy wskaznik na tablice wiec funkcja dziala na oryginalnym elemencie
{
    ifstream plik;
    plik.open(nazwa);
    if (plik.good())
    {
        for (int i = 0; i < r1; i++)
        {
            for (int j = 0; j < r2; j++)
            {
                plik >> t[i][j]; // tutaj modyfikujemy tablice
            }
        }
        plik.close();
    }
    else
    {
        cout << "nie udalo sie znalezc pliku" << endl;
    }
}

void usunTablice(float **&t, int r1)
{
    // usuwanie tablicy NxN

    for (int i = 0; i < r1; i++)
    {
        delete[] t[i];
    }

    delete[] t;
}
