#include "Tambahan.hpp"
#include <string>

using namespace std;


Bus::Bus() : Kendaraan(0, 0, "XXX", "bus"){
    kapasitas = 0;
}

Bus::Bus(int kapasitas) : Kendaraan(0, 0, "XXX", "bus"){
    this->kapasitas = kapasitas;
}

Bus::Bus(const Bus &other) : Kendaraan(0, 0, "XXX", "bus"){
    this->kapasitas = other.kapasitas;
}

Bus Bus::operator=(const Bus &other){
    return Bus(other);
}

Bus::~Bus(){}

int Bus::diskon(int lamaSewa){
    return this->biayaSewa(lamaSewa) / 10;
}


Minibus::Minibus() : Kendaraan(0, 0, "XXX", "minibus"){}

Minibus::Minibus(const Minibus &other) : Kendaraan(){
    
}

Minibus Minibus::operator=(const Minibus &other){
    return Minibus(other);
}

Minibus::~Minibus(){}


Mobil::Mobil() : Kendaraan(){
    supir = "XXXX";
}

Mobil::Mobil(string supir) : Kendaraan(){
    this->supir = supir;
}

Mobil::Mobil(const Mobil &other) : Kendaraan(){
    this->supir = other.supir;
}

Mobil Mobil::operator=(const Mobil &other){
    return Mobil(other);
}

Mobil::~Mobil(){}