#include "Penganan.hpp"
#include <iostream>

using namespace std;

int Penganan::uang = 0;
int Penganan::n_rumah = 0;

// ctor tanpa parameter
// inisialisasi seluruh koefisien dengan nilai 0
Penganan::Penganan(){
    this->keik = 0;
    this->panekuk = 0;
}

// ctor dengan parameter
Penganan::Penganan(int keik, int panekuk){
    this->keik = keik;
    this->panekuk = panekuk;
}

//mengembalikan bagian jumlah keik
int Penganan::GetKeik() const{
    return keik;
}

// mengembalikan bagian jumlah panekuk
int Penganan::GetPanekuk() const{
    return panekuk;
}

// mengisi bagian keik
void Penganan::SetKeik(int keik){
    this->keik = keik;
}

// mengisi bagian panekuk
void Penganan::SetPanekuk(int panekuk){
    this->panekuk = panekuk;
}

// operator overloading

// operator+ 
Penganan operator+ (const Penganan& A, const Penganan& B){
    int keik = A.keik + B.keik;
    int panekuk = A.panekuk + B.panekuk;
    Penganan::n_rumah++;
    return Penganan(keik, panekuk);
}
// operator- 
Penganan operator- (const Penganan& A, const Penganan&B){
    int resKeik, resPanekuk;
    if(B.keik > A.keik){
        resKeik = 0;
        Penganan::uang += A.keik * 51;
    } else{
        resKeik = A.keik - B.keik;
        Penganan::uang += B.keik * 51;
    }

    if(B.panekuk > A.panekuk){
        resPanekuk = 0;
        Penganan::uang += A.panekuk * 37;
    } else{
        resPanekuk = A.panekuk - B.panekuk;
        Penganan::uang += B.panekuk * 37;
    }

    return Penganan(resKeik, resPanekuk);
}

// operator^ 
Penganan operator^ (const Penganan& A, const int n){
    int resKeik, resPanekuk;
    if(n > A.keik){
        resKeik = 0;
        Penganan::uang -= (n - A.keik) * 51;
    } else{
        resKeik = A.keik - n;
    }

    if(n > A.panekuk){
        resPanekuk = 0;
        Penganan::uang -= (n - A.panekuk) * 37;
    } else{
        resPanekuk = A.panekuk - n;
    }

    return Penganan(resKeik, resPanekuk);
}

// operator^ (sifat komutatif)
Penganan operator^ (const int n, const Penganan& A){
    int resKeik, resPanekuk;
    if(n > A.keik){
        resKeik = 0;
        Penganan::uang -= (n - A.keik) * 51;
    } else{
        resKeik = A.keik - n;
    }

    if(n > A.panekuk){
        resPanekuk = 0;
        Penganan::uang -= (n - A.panekuk) * 37;
    } else{
        resPanekuk = A.panekuk - n;
    }

    return Penganan(resKeik, resPanekuk);
}

// mengembalikan jumlah uang yang diperoleh
int Penganan::JumlahUang(){
    return uang;
}

// mengembalikan jumlah kunjungan ke rumah
int Penganan::HitungNRumah(){
    return n_rumah;
}

// mencetak isi kantong
// Jangan lupa tambahkan endline di akhir print
// Contoh:
// 0keik-0panekuk
// 111keik-122panekuk
void Penganan::Print(){
    cout << this->keik << "keik-" << this->panekuk << "panekuk" << endl;
}