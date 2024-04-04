#include "Vektor.hpp"
#include <iostream>

using namespace std;

/*
set n = 0 dan vektor tetap kosong
*/
Vektor::Vektor(){
    n = 0;
    this->vektor = vector<int> ();
}

/*
set n = _n dan vektor berisi _n elemen dengan setiap elemennya bernilai 0
*/
Vektor::Vektor(int _n){
    n = _n;
    this->vektor = vector<int> ();
    for(int i = 0; i < n; i++){
        this->vektor.push_back(0);
    }
}

// cctor
Vektor::Vektor(const Vektor &v){
    n = v.n;
    this->vektor = v.vektor;
}

// dtor
Vektor::~Vektor(){

}

/*
Set elemen ke-idx (0<=idx<n) dari vektor menjadi x
idx dijamin valid
*/
void Vektor::setElmt(int idx,int x){
    this->vektor[idx] = x;
}

 // menghasilkan n (ukuran vektor)
int Vektor::getN(){
    return n;
}

/*
operasi penjumlahan 2 vektor yang menghasilkan sebuah objek vektor baru, ukuran kedua vektor dijamin sama
misal
v1 = [1,2,3]
v2 = [3,7,9]
v1 + v2 = [4,9,12]
*/
Vektor operator+(const Vektor &v1,const Vektor &v2){
    Vektor res(v1.n);
    for(int i = 0; i < v1.n; i++){
        res.vektor[i] = v1.vektor[i] + v2.vektor[i];
    }
    return res;
}

/*
operasi pengurangan 2 vektor yang menghasilkan sebuah objek vektor baru, ukuran kedua vektor dijamin sama
misal
v1 = [1,2,3]
v2 = [3,7,9]
v1 - v2 = [-2,-5,-6]
*/
Vektor operator-(const Vektor &v1,const Vektor &v2){
    Vektor res(v1.n);
    for(int i = 0; i < v1.n; i++){
        res.vektor[i] = v1.vektor[i] - v2.vektor[i];
    }
    return res;
}

/*
operasi dot product 2 vektor, ukuran kedua vektor dijamin sama
misal
v1 = [1,2,3]
v2 = [3,7,9]
v1 * v2 = 1*3+2*7+3*9 = 44
*/
int operator*(const Vektor &v1,const Vektor &v2){
    int res = 0;
    for(int i = 0; i < v1.n; i++){
        res += v1.vektor[i] * v2.vektor[i];
    }
    return res;
}

// mengecek apakah kedua vektor memiliki ukuran yang sama dan setiap elemennya bernilai sama
bool operator==(const Vektor &v1,const Vektor &v2){
    if(v1.n != v2.n){
        return false;
    } else{
        for(int i = 0; i < v1.n; i++){
            if(v1.vektor[i] != v2.vektor[i]){
                return false;
            }
        }
        return true;
    }
}

/*
menampilkan vektor dalam format <v[0],v[1],...,v[n-1]> dan diakhiri dengan newline
misal v1 = [1,3,5]
hasil print = <1,3,5>
*/
void Vektor::printVektor(){
    cout << "<";
    for(int i = 0; i < n; i++){
        cout << this->vektor[i];
        if(i != n - 1){
            cout << ",";
        }
    }
    cout << ">" << endl;
}