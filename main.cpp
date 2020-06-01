#include "funkcijos.h"

using namespace std;

int main()
{
    vector <duomenys> d;
    srand( time (NULL) );
    int k=0, r;   // r- papildomu mokiniu irasymui,  k- mokiniu skaicius
    double h, a;
    string b;
    vector <int> temp;
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
    if( r == 0)
    {
        try
        {
            ifstream faila ( "studentai10000.txt" );
            if (!faila.good()) throw runtime_error("Failas neegzistuoja \n");
            faila.ignore(INT_MAX,'\n');
            while( !faila.eof() )
            {
                d.push_back(duomenys());
                d[k].setn(0);
                faila >> b;
                d[k].setv(b);
                faila >> b;
                d[k].setp(b);
                while ( !faila.fail() )
                {
                    faila >> h;
                    if( h > 0 && h < 11 )
                    {
                        temp.push_back(h);
                        a+=temp.back();
                        d[k].setn(d[k].getn()+1);
                    }
                    if (faila.eof()) break;
                }
                d[k].setn(d[k].getn()-1);
                d[k].seter(temp.back());
                a-=temp.back();
                temp.pop_back();
                d[k].setnd(temp);
                d[k].setvisi(a);
                a=0;
                k++;
                temp.erase(temp.begin(),temp.end());
                if (faila.eof())
                {
                    faila.ignore();
                    break;
                }
                faila.clear();
            }
            d.shrink_to_fit();
            faila.close();
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
        d[k].setn(0);
        cout << "Koks jusu vardas?"<<endl;
        cin >> b;
        d[k].setv(b);
        cout << "Kokia jusu pavarde?"<<endl;
        cin >> b;
        d[k].setp(b);
        int s;
        cout << "Jei norite namu darbu pazymius generuoti atsitiktinai irasykite 1, o jei vesite patys, rasykite 0" << endl;
        cin >> s;
        if ( s == 1)
        {
            d[k].setn(rand()%10+1);
            for (int j=0; j<d[k].getn(); j++)
            {
                temp.push_back(rand()%10+1);
            }
            d[k].setnd(temp);
            temp.erase(temp.begin(),temp.end());
        }
        else
        {
        cout << "Kokie jusu namu darbu rezultatai? Nuo 1 iki 10. Kai suvesite visus, irasykite 0"<<endl;
        for(;;)
        {
            cin >> h;
            if( h > 0 && h < 11 )
            {
                temp.push_back(h);
                d[k].setn(d[k].getn()+1);
            }
            else if( h < 0 || h > 10 )
            {
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
            d[k].setnd(temp);
            temp.erase(temp.begin(),temp.end());
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
            d[k].seter(rand()%10+1);
        if ( s == 0 )
        {
            cout << "Koks jusu egzamino rezultatas? Nuo 1 iki 10." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> h;
            while( h < 1 || h > 10 )
            {
                cout << "Veskite tik skaicius nuo 1 iki 10" << endl;
                cin >> h;
                d[k].seter(h);
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
        cout << "Pavarde             Vardas              Galutinis(Vid.)" << endl;
        cout << "-------------------------------------------------------" << endl;
        for( int i=0; i<=k; i++)
            cout << setw(20) << left << d[i].getp() << setw(20) << d[i].getv() << setw(5) << fixed << setprecision(2) << 0.4* d[i].getvisi()/d[i].getn() + 0.6*d[i].geter() << endl;
    }
    return 0;
}
