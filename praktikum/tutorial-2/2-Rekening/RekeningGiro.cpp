#include "RekeningGiro.h"

// Konstruktor menginisialisi saldo (parameter 1) dan suku bunga (parameter 2)
// Set suku bunga 0.0 apabila suku bunga bernilai negatif
RekeningGiro::RekeningGiro(double saldo, double sukuBunga) : Rekening(saldo) {
    this->sukuBunga = sukuBunga;
}

// Getter, Setter
void RekeningGiro::setSukuBunga(double sukuBunga){
    this->sukuBunga = sukuBunga;
}
double RekeningGiro::getSukuBunga() const{
    return sukuBunga;
}

// Member Function
// Bunga dihitung dari saldo dikali suku bunga
double RekeningGiro::hitungBunga(){
    return getSaldo() * sukuBunga;
}