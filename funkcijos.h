#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include <iostream>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <time.h>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <random>
#include <chrono>
#include <iterator>

using namespace std;

class Person {
protected:
    string v; // vardas
    string p; // pavarde
public:
    inline string getv() const {return v;}
    inline string getp() const {return p;}
    inline void setv (string v) {this->v=v;}
    inline void setp (string p) {this->p=p;}
};

class duomenys: public Person {
private:
    vector<int> C; // namu darbu pazymiu vektorius
    int er; // egzamino rezultatas
    double visi; //visu pazymiu suma
    double galv; // galutinis pazymys su vidurkiais
    double galm; // galutinis pazymys su mediana
    int n; // namu darbu sk
public:
    duomenys() : er(0), visi(0.0), galv(0.0), galm(0.0), n(0) {}
    ~duomenys() {}

    //string getv() const {return v;}
    //string getp() const {return p;}
    double getgalv() const {return galv;}
    int geter() const {return er;}
    int getn() const {return n;}
    int getvisi() const {return visi;}
    vector<int> getnd() {return C;}
    //void setv(string v) {this->v = v;}
    //void setp(string p) {this->p = p;}
    void setnd(vector<int> X) { C=X;}
    void seter(int er) {this->er = er;}
    void setn(int n) {this->n = n;}
    void setvisi(double visi) {this->visi = visi;}
    void setgalv(double galv) {this->galv = galv;}
};

double mediana (vector<int> &X);
double vidurkis (vector<int> &A);
bool rusiavimasV(const duomenys &a, const duomenys &b);
bool rusiavimasP(const duomenys &a, const duomenys &b);
void generavimas(int q, int k);
void nuskaitymas(int &k, vector <duomenys> &d);
void rasymas(int k, vector <duomenys> &d);
void rusiavimas(int k, vector <duomenys> &d);

#endif // FUNKCIJOS_H
