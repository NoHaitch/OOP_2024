#include "Bangunan.hpp"

/*
    Membuat objek Bangunan dengan nama "Bangunan Kosong"
*/
Bangunan::Bangunan(){
    namaBangunan = "Bangunan Kosong";
}

/*
    Membuat objek Bangunan dengan nama "namaBangunan"
*/
Bangunan::Bangunan(string namaBangunan){
    this->namaBangunan = namaBangunan;
}

/*
    Mendapatkan nama Bangunan
*/
string Bangunan::getNamaBangunan(){
    return namaBangunan;
}