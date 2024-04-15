#include <iostream>
#include <vector>
#include "Kendaraan.hpp"

using namespace std;

/* CTOR */
Kendaraan::Kendaraan(){
    nomor = 0;
    tahunKeluaran = 0;
    merk = "XXX";
    kategori = "mobil";
}

/* CTOR */
Kendaraan::Kendaraan(int nomor, int tahunKeluaran, string merk, string kategori){
    this->nomor = nomor;
    this->tahunKeluaran = tahunKeluaran;
    this->merk = merk;
    this->kategori = kategori;
}

/* CCTOR */
Kendaraan::Kendaraan(Kendaraan &other){
    this->nomor = other.nomor;
    this->tahunKeluaran = other.tahunKeluaran;
    this->merk = other.merk;
    this->kategori = other.kategori;
}

/* Copy Asignment */
Kendaraan Kendaraan::operator=(Kendaraan &other){
    return Kendaraan(other);
}

/* DTOR */
Kendaraan::~Kendaraan(){}

void Kendaraan::printInfo(){
    cout << "Nomor: " << nomor << endl;
    cout << "Merk: " << merk << endl;
    cout << "Kategori: " << kategori << endl;
    cout << "Tahun Keluaran: " << tahunKeluaran << endl;
}

int Kendaraan::biayaSewa(int lamaSewa){
    if(kategori == "bus"){
        return 1000000 * lamaSewa;
    } else if(kategori == "minibus"){
        if(lamaSewa <= 5){
            return 5000000;
        } else{
            return 5000000 + 500000*(lamaSewa-5);
        }
    } else if(kategori == "mobil"){
        return 500000 * lamaSewa;
    } else {
        cout << "Kategori mobil salah!" << endl;
        return 0;
    }
}

void Kendaraan::setData(int nomor, int tahunKeluaran, string kategori, string merk){
    this->nomor = nomor;
    this->tahunKeluaran = tahunKeluaran;
    this->merk = merk;
    this->kategori = kategori;
}