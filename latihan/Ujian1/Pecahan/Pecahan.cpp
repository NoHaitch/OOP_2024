#include <iostream>
#include "Pecahan.hpp"

using namespace std;

// ctor: set n = 0 dan d = 1
pecahan::pecahan(){
    n = 0;
    d = 1;
}

// ctor: set n = _n dan d = _d
pecahan::pecahan(int _n, int _d){
    n = _n;
    d = _d;
}

// cctor:
pecahan::pecahan(const pecahan &P){
    n = P.n;
    d = P.d;
}

// dtor
pecahan::~pecahan(){

}

// Menghasillkan pembilang n
int pecahan::getPemb(){
    return n;
}

// Menghasilkan penyebut d
int pecahan::getPeny(){
    return d;
} 

// Mengubah nilai n menjadi _n
void pecahan::setPemb(int _n){
    if(_n >= 0){
        n = _n;
    }
}

// Mengubah nilai d menjadi _d
void pecahan::setPeny(int _d){
    if(_d > 0){
        d = _d;
    }
} 

// Menambahkan pecahan dengan P
// Rumus = n1/d1 + n2/d2 = (n1*d2 + n2*d1)/d1*d2
pecahan pecahan::operator+(const pecahan &P){
    pecahan res;
    res.setPemb(n * P.d + P.n * d);
    res.setPeny(d * P.d);
    return res;
}

// Menambahkan pecahan dengan P
// Rumus = n1/d1 - n2/d2 = (n1*d2 - n2*d1)/d1*d2
pecahan pecahan::operator-(const pecahan &P){
    pecahan res;
    res.setPemb(n * P.d - P.n * d);
    res.setPeny(d * P.d);
    return res;
}

// Mengalikan pembilang P dengan x dan penyebut P dengan x
// Syarat: x > 0
// Rumus = n1/d1 = (n1*x)/(d1*x)
pecahan pecahan::operator*(int x){
    if(x > 0){
        pecahan res;
        res.setPemb(n * x);
        res.setPeny(d * x);
        return res;
    }
    return *this;
}

int gcd(int a, int b){
    if(a == 0){
        return b;
    } 
    return gcd( b % a, a);
}

// Mengecek apakah kedua pecahan memiliki nilai yang sama
// Hint: bandingkan dengan gcd, tidak boleh dibandingkan dengan RealP()!
bool pecahan::operator==(const pecahan &P){
    int gcd1 = gcd(n, d);
    int gcd2 = gcd(P.n, P.d);

    int n1 = n/gcd1;
    int n2 = P.n/gcd2;
    int d1 = d/gcd1;
    int d2 = P.d/gcd2;

    return n1 == n2 && d1 == d2;
}

// Menghasilkan bentuk desimal dari pecahan
float pecahan::RealP(){
    return float(n/d);
}

// Mencetak pecahan dalam format: n/d (tanpa tambahan karakter apa pun
// di depan, tengah, atau belakang)
void pecahan::Print(){
    cout << n << "/" << d << endl;
}