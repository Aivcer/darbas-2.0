#include "funkcijos.h"



/*double mediana (vector<int> &X)
{
  int a, b;
  sort(X.begin(), X.end());
  if (X.size()%2==0)
  {
    a=X.size()/2;
    b=X.size()/2-1;
    return (X[a]+X[b])*1.0/2;
  }
  else
  {
    a=X.size()/2;
    return X[a];
  }
}

double vidurkis (vector<int> &A)
{
  int visi=0;
  for(int i=0; i<A.size(); i++)
  {
    visi+=A[i];
  }
  return visi*1.0/A.size();
}*/

bool rusiavimasV(const duomenys &a, const duomenys &b)
{
    return a.getv() < b.getv();
}

bool rusiavimasP(const duomenys &a, const duomenys &b)
{
    return a.getp() < b.getp();
}

void generavimas(int q, int k)
{
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(1, 10);
    ofstream fq( "stud" + to_string(k) + ".txt" );
    fq << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde";
    for (int i=0; i<q; i++)
        fq << setw(5) << left << ( "ND" + to_string(i+1) );
    fq << setw(5) << left << "Egz." << endl;
    for (int i=0; i<k; i++)
    {
        fq << setw(20) << left << ( "Vardas" + to_string(i+1) ) << setw(20) << ( "Pavarde" + to_string(i+1) );
        for (int j=0; j<q; j++)
            fq << setw(5) << left  << dist(mt);
        fq << setw(5) << left << dist(mt) << endl;
    }
    fq.close();
}

void nuskaitymas(int &k, vector <duomenys> &d)
{
    auto start = std::chrono::high_resolution_clock::now();
    ifstream in( "stud" + to_string(k) + ".txt" );
    in.ignore(INT_MAX,'\n');
    double h, a;
    string t;
    vector <int> temp;
    d.reserve(k);
    k=0;
    while( !in.eof() )
    {
        d.push_back(duomenys());
        d[k].setn(0);
        in >> t;
        d[k].setv(t);
        in >> t;
        d[k].setp(t);
        while ( !in.fail() )
        {
            in >> h;
            if( h > 0 && h < 11 )
            {
                temp.push_back(h);
                a+=temp.back();
                d[k].setn(d[k].getn()+1);
            }
            if (in.eof()) break;
        }
        d[k].setn(d[k].getn()-1);
        d[k].seter(temp.back());
        a-=temp.back();
        temp.pop_back();
        d[k].setnd(temp);
        d[k].setvisi(a);
        //cout << d[k].getvisi() << endl;
        a=0;
        k++;
        temp.clear();
        if (in.eof())
        {
            in.ignore();
            break;
        }
        in.clear();
    }
    d.shrink_to_fit();
    in.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    cout << k << " elementu nuskaitymas uztruko: "<< diff.count() << " s\n";
}

/*void rasymas(int k, vector <duomenys>& d)
{
    ofstream out1("Nuskriaustukai" + to_string(k) + ".txt");
    ofstream out2("Protuoliai" + to_string(k) + ".txt");
    out1 << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(10) << left << "Galutinis" << endl;
    out2 << setw(20) << left << "Vardas" << setw(20) << left << "Pavarde" << setw(10) << left << "Galutinis" << endl;
    for( int i=0; i<k; i++)
    {
        if( 0.4* vidurkis(d[i].C) + 0.6*d[i].er < 5 ) out1 << setw(20) << left << d[i].v << setw(20) << d[i].p << setw(10) << fixed << setprecision(2) << 0.4* vidurkis(d[i].C) + 0.6*d[i].er << endl;
        if( 0.4* vidurkis(d[i].C) + 0.6*d[i].er >= 5 ) out2 << setw(20) << left << d[i].v << setw(20) << d[i].p << setw(10) << fixed << setprecision(2) << 0.4* vidurkis(d[i].C) + 0.6*d[i].er << endl;
    }
    out1.close();
    out2.close();
}*/

void rusiavimas(int k, vector <duomenys> &d)
{
    auto start = std::chrono::high_resolution_clock::now();
    vector <duomenys> nus;
    nus.reserve(k/3);
    vector <duomenys> pro;
    pro.reserve(k/3);
    for (vector<duomenys>::iterator i=d.begin(); i!=d.end(); ++i)
    {
        (*i).setgalv(0.4*(*i).getvisi()/(*i).getn()+ 0.4*(*i).geter());
        if ( (*i).getgalv() < 5 )
            nus.push_back((*i));
        else if( (*i).getgalv() >= 5 )
            pro.push_back((*i));
    }
    d.clear();
    nus.shrink_to_fit();
    pro.shrink_to_fit();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    cout << k << " elementu rusiavimas uztruko: "<< diff.count() << " s\n";
    //irasymas
    ofstream out1("Nuskriaustukai" + to_string(k) + ".txt");
    ofstream out2("Protuoliai" + to_string(k) + ".txt");
    for (vector<duomenys>::iterator i=nus.begin(); i!=nus.end(); ++i)
        out1 << setw(20) << left << (*i).getv() << setw(20) << (*i).getp() << setw(10) << fixed << setprecision(2) << (*i).getgalv() << endl;
    for (vector<duomenys>::iterator i=pro.begin(); i!=pro.end(); ++i)
        out2 << setw(20) << left << (*i).getv() << setw(20) << (*i).getp() << setw(10) << fixed << setprecision(2) << (*i).getgalv() << endl;
    out1.close();
    out2.close();
    nus.clear();
    pro.clear();
}
