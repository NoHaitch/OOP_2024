#include "KoleksiKendaraan.hpp"
#include <iostream>

using namespace std;

/* CTOR - Default */
KoleksiKendaraan::KoleksiKendaraan(){
    size = 100;
    nEff = 0;
}

/* CTOR - User Defined */
KoleksiKendaraan::KoleksiKendaraan(int size, int nEff){
    this->size = size;
    this->nEff = nEff;
}

/* CCTOR */
KoleksiKendaraan::KoleksiKendaraan(KoleksiKendaraan &other){
    this->size = other.size;
    this->nEff = other.nEff;
}

/* Copy Asignment */
KoleksiKendaraan KoleksiKendaraan::operator=(KoleksiKendaraan &other){
    return KoleksiKendaraan(other);
}


/* DTOR */
KoleksiKendaraan::~KoleksiKendaraan(){}

void KoleksiKendaraan::printAll(){
    cout << "Ukuran Koleksi: " << size << endl;
    cout << "Jumlah Kendaraan: " << nEff << endl;
    for(int i = 0; i < nEff; i++){
        koleksi[i].printInfo();
    }
}

void KoleksiKendaraan::operator<<(const Kendaraan &kendaraan){
    if(nEff < size){
        nEff++;
        koleksi.push_back(kendaraan);
    }
}


void KoleksiKendaraan::operator<<(const KoleksiKendaraan &koleksiKendaraan){
    for(int i = 0; i < koleksiKendaraan.nEff; i++){
        if(nEff < size){
            nEff++;
            koleksi.push_back(koleksiKendaraan.koleksi[i]);
        } else{
            break;
        }
    }
}