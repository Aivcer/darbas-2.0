#include "funkcijos.h"

using namespace std;

int main()
{
    vector <duomenys> d;
    srand( time (NULL) );
    int k=0, r;   // r- papildomu mokiniu irasymui,  k- mokiniu skaicius
    double h;
    cout << "Jei norite atlikti testa, rasykite 2, jei duomenys vesite patys rasykite 1, o jei bus nuskaitomi is failo, rasykite 0" << endl;
    for(;;)
        {
            cin >> r;
            if( r == 1 || r == 0 || r == 2) break;
            else cout << "Irasykite tik 2, 1 arba 0" << endl;
        }
    if( r == 2)
    {
        auto start = std::chrono::high_resolution_clock::now();
        int k=100000;
        int q=5; // namu darbu sk.
        for(int i=1; i<=2; i++)
        {
            d.clear();
            cout << endl;
            cout << "Pradedamas skaiciavimas su " << k << " elementais" << endl;
            generavimas( q, k );
            nuskaitymas( k, d );
            sort(d.begin(), d.end(), rusiavimasV);
            rusiavimas(k, d);
            k=k*10;
        }
        cout<<endl;
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        cout << "Programos vykdymo laikas: "<< diff.count() << " s\n";
    }
    /*if( r == 0)
    {
        try
        {
            ifstream faila ( "studentai10000.txt" );
            if (!faila.good()) throw runtime_error("Failas neegzistuoja \n");
            faila.ignore(INT_MAX,'\n');
            while( !faila.eof() )
            {
                d.push_back(duomenys());
                d[k].n = 0;
                faila >> d[k].v;
                faila >> d[k].p;
                while ( !faila.fail() )
                {
                    faila >> h;
                    if( h > 0 && h < 11 )
                    {
                        d[k].C.push_back(h);
                        d[k].n++;
                    }
                    if (faila.eof()) break;
                }
                d[k].n--;
                d[k].er = d[k].C.back();
                d[k].C.pop_back();
                k++;
                if (faila.eof())
                {
                    faila.ignore();
                    break;
                }
                faila.clear();
            }
            d.shrink_to_fit();
            faila.close();
            k--;
        }
        catch(exception &e)
        {
            system("cls");
            cout << e.what() << endl;
            return 0;
        }
    }
    while( r == 1)
    {
        d.push_back(duomenys());
        d[k].n = 0;
        cout << "Koks jusu vardas?"<<endl;
        cin >> d[k].v;
        cout << "Kokia jusu pavarde?"<<endl;
        cin >> d[k].p;
        int s;
        cout << "Jei norite namu darbu pazymius generuoti atsitiktinai irasykite 1, o jei vesite patys, rasykite 0" << endl;
        cin >> s;
        if ( s == 1)
        {
            d[k].n=rand()%10+1;
            for (int j=0; j<d[k].n; j++)
            {
                d[k].C.push_back(rand()%10+1);
            }
        }
        else
        {
        cout << "Kokie jusu namu darbu rezultatai? Nuo 1 iki 10. Kai suvesite visus, irasykite bet koki simboli, kuris nera nuo 1 iki 10"<<endl;
        for(;;)
        {
            d[k].n++;
            cin >> h;
            if( h > 0 && h < 11 )
                d[k].C.push_back(h);
            else if( h < 1 || h > 10 )
            {
                d[k].n--;
                int x;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Turit vesti tik skaicius nuo 1 iki 10, ar noresit pridet kita pazymi? Jei taip, veskite 1, jei ne - 0" << endl;
                cin >> x;
                if( x == 1)
                    cout << "Veskite tik skaicius nuo 1 iki 10" << endl;
                else if( x == 0) break;
                else cout << "Ar noresit pridet kita pazymi? Jei taip, veskite 1, jei ne - 0" << endl;
            }
        }
        }
        cout << "Jei norite egzamino pazymi generuoti atsitiktinai irasykite 1, o jei vesite patys, rasykite 0" << endl;
        for(;;)
        {
            cin >> s;
            if( s == 1 || s == 0) break;
            else cout << "Irasykite tik 1 arba 0" << endl;
        }
        if ( s == 1 )
            d[k].er = rand()%10+1;
        if ( s == 0 )
        {
            cout << "Koks jusu egzamino rezultatas? Nuo 1 iki 10." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> d[k].er;
            while( d[k].er < 1 || d[k].er > 10 )
            {
                cout << "Veskite tik skaicius nuo 1 iki 10" << endl;
                cin >> d[k].er;
            }
        }
        cout << "Ar norite prideti dar mokiniu? Irasykite 1, kad pridet, 0, jei tai paskutinis mokinys" << endl;
        for(;;)
        {
            cin >> r;
            if( r == 1 || r == 0) break;
            else cout << "Irasykite tik 1 arba 0" << endl;
        }
        if( r == 1)
        {
            k++;
        }
    }
    if ( r == 0)
    {
        cout << "Jei norite duomenis rusiuoti pagal varda irasykite 1. Jei norite rusiuoti pagal pavarde irasykite 0" <<endl;
        for(;;)
        {
            cin >> r;
            if( r == 1 || r == 0) break;
            else cout << "Irasykite tik 1 arba 0" << endl;
        }
        if( r == 1)  sort(d.begin(), d.end(), rusiavimasV);
        if( r == 0)  sort(d.begin(), d.end(), rusiavimasP);
        cout << "Jei norite naudoti vidurki galutinio balo apskaiciavimui irasykite 1. Jei norite naudoti mediana irasykite 0" <<endl;
        for(;;)
        {
            cin >> r;
            if( r == 1 || r == 0) break;
            else cout << "Irasykite tik 1 arba 0" << endl;
        }
        if( r == 1)
        {
            cout << "Pavarde             Vardas              Galutinis(Vid.)" << endl;
            cout << "-------------------------------------------------------" << endl;
            for( int i=0; i<=k; i++)
                cout << setw(20) << left << d[i].p << setw(20) << d[i].v << setw(5) << fixed << setprecision(2) << 0.4* vidurkis(d[i].C) + 0.6*d[i].er << endl;
        }
        if( r == 0 )
        {
            cout << "Pavarde             Vardas              Galutinis(Med.)" << endl;
            cout << "-------------------------------------------------------" << endl;
            for( int i=0; i<=k; i++)
                cout << setw(20) << left << d[i].p << setw(20) << d[i].v << setw(5) << fixed << setprecision(2) << 0.4* mediana(d[i].C) + 0.6*d[i].er << endl;
        }
    }*/
    return 0;
}
