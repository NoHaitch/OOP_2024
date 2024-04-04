#ifndef _VEKTOR_HPP_
#define _VEKTOR_HPP_

#include <iostream>
#include "vector"

using namespace std;

class Vektor {
private:
    int n;
    vector<int>vektor;
public:
    /*
    set n = 0 dan vektor tetap kosong
    */
    Vektor();

    /*
    set n = _n dan vektor berisi _n elemen dengan setiap elemennya bernilai 0
    */
    Vektor(int _n);

    // cctor
    Vektor(const Vektor &v);

    // dtor
    ~Vektor();

    /*
    Set elemen ke-idx (0<=idx<n) dari vektor menjadi x
    idx dijamin valid
    */
    void setElmt(int idx,int x);

    int getN(); // menghasilkan n (ukuran vektor)

    /*
    operasi penjumlahan 2 vektor yang menghasilkan sebuah objek vektor baru, ukuran kedua vektor dijamin sama
    misal
    v1 = [1,2,3]
    v2 = [3,7,9]
    v1 + v2 = [4,9,12]
    */
    friend Vektor operator+(const Vektor &v1,const Vektor &v2);

    /*
    operasi pengurangan 2 vektor yang menghasilkan sebuah objek vektor baru, ukuran kedua vektor dijamin sama
    misal
    v1 = [1,2,3]
    v2 = [3,7,9]
    v1 - v2 = [-2,-5,-6]
    */
    friend Vektor operator-(const Vektor &v1,const Vektor &v2);

    /*
    operasi dot product 2 vektor, ukuran kedua vektor dijamin sama
    misal
    v1 = [1,2,3]
    v2 = [3,7,9]
    v1 * v2 = 1*3+2*7+3*9 = 44
    */
    friend int operator*(const Vektor &v1,const Vektor &v2);

    // mengecek apakah kedua vektor memiliki ukuran yang sama dan setiap elemennya bernilai sama
    friend bool operator==(const Vektor &v1,const Vektor &v2);

    /*
    menampilkan vektor dalam format <v[0],v[1],...,v[n-1]> dan diakhiri dengan newline
    misal v1 = [1,3,5]
    hasil print = <1,3,5>
    */
    void printVektor();
};
#endif