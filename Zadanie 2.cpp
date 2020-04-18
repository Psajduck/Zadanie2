// Jakub Maksajda 209976 Zadanie 2 (Generowanie siatki)
//

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <math.h>
#define _USE_MATH_DEFINES

using namespace std;
int zlicz_linie(string);
void wczytaj_dane(string, float*);
void siatka_jednorodna(float*,int);
void siatka_niejednorodna(float*, int);

int main()
{
   /* string nazwa_pliku = "siatka.txt";
    int ile=zlicz_linie(nazwa_pliku);
    float* Tablica = new float[ile];
    wczytaj_dane(nazwa_pliku, Tablica);
    siatka_jednorodna(Tablica,ile);
    siatka_niejednorodna(Tablica, ile);
    delete[] Tablica;*/
    string nazwa_pliku;
    int wybor;
    cout << "Witaj w programie do generowania siatki\n";
    cout << "Wprowadz najpierw nazwe pliku z danymi: ";
    getline(cin, nazwa_pliku);
    nazwa_pliku = nazwa_pliku + ".txt";
    int ile = zlicz_linie(nazwa_pliku);
    float* Tablica = new float[ile];
    wczytaj_dane(nazwa_pliku, Tablica);
   
   
    do 
    {
        system("cls");
        cout << "Jaka siatke chcesz stworzyc?\n";
        cout << "(1) Siatka jednorodna\n";
        cout << "(2) Siatka niejednorodna\n";
        cout << "(0) Zamkniecie programu\n";
        cout << "Twoj wybor: ";
        cin >> wybor;
        switch (wybor)
        {
        case 0:
            cout << "Dziekuje, do widzenia\n";
            return false;
            break;
        case 1:
            siatka_jednorodna(Tablica, ile);
            cout << "Siatka zostala zapisana do pliku\n";
            system("pause");
            break;
        case 2:
            siatka_niejednorodna(Tablica, ile);
            cout << "Siatka zostala zapisana do pliku\n";
            system("pause");
            break;
        default:
            cout << "Dokonano nieprawidlowego wyboru\n";
            system("pause");
            break;
        }
    } while (true);

    delete[] Tablica; 
    return 0;
}

int zlicz_linie(string name)
{
    string linia;
    fstream plik;
    int i = 0;

    plik.open(name, ios::in);
    if (plik.good() == true)
    {
        while (!plik.eof())
        {
            getline(plik, linia);
            i++;
        }
    }
    else
    {
        cout << "Blad otwarcia pliku\n";
        system("pause");
        exit(0);
    }
    plik.close();
    return i;
}
void wczytaj_dane(string name, float *Tab)
{
    fstream plik;
    string linia;
    int a;
    float b;
    int i = 1;
    Tab[0] = 0;
    plik.open(name, ios::in);
    getline(plik, linia);
    while (!plik.eof())
    {
        plik >> a >> b;
        Tab[i] = b+Tab[i-1];
        i++;
    }
    plik.close();
}
void siatka_jednorodna(float *Tab,int ilosc)
{
    string nazwa;
    double odleglosc;
    cout << "Podaj nazwe pliku do zapisu: ";
    cin >> nazwa;
    cout << "Podaj odleglosc miedzy kolejnymi wezlami: ";
    cin >> odleglosc;
    ofstream plik(nazwa + ".txt");
    plik << "Nr" << "\t" << "Polozenie" << "\n";
    int nr = 1;
    for (int k = 0; k < ilosc; k++)
    {
        for (double i = Tab[k]; i < Tab[k+1]; i = i + odleglosc)    
        {
            plik <<nr<<"\t"<< i << "\n";
            nr++;
        }
    }
    plik << nr << "\t" << Tab[ilosc - 1] << "\n";
    plik.close();
}
void siatka_niejednorodna(float* Tab, int ilosc)
{
    string nazwa;
    double odleglosc,i,srednia;
    cout << "Podaj nazwe pliku do zapisu: ";
    cin >> nazwa;
    cout << "Podaj poczatkowa odleglosc: ";
    cin >> odleglosc;
    ofstream plik(nazwa + ".txt");
    plik << "Nr" << "\t" << "Polozenie" << "\n";
    int nr = 1;
    int n;
    for (int k = 0; k < ilosc-1; k++)
    {
        i = Tab[k];
        n = 0;
        srednia=(Tab[k]+Tab[k+1])/2;
        do
        {
            plik << nr << "\t" << i << "\n";
            nr++;
            i = Tab[k] + odleglosc * pow(2, n);
            n++;
        } while (i < srednia);
        if (n > 1)
        {
            n--;
        }
        do
        {
            n--;
            i = Tab[k + 1] - odleglosc * pow(2, n);
            plik << nr << "\t" << i << "\n";
            nr++; 
        } while (n > 0);
    }
    plik << nr << "\t" << Tab[ilosc - 1] << "\n";
    plik.close();
  
}