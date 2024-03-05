#ifndef __TAMBAHAN_HPP__
#define __TAMBAHAN_HPP__

#include "Kendaraan.hpp"
#include <string>

using namespace std;

class Bus : public Kendaraan{
    public:
        Bus();
        Bus(int kapasitas);
        Bus(const Bus &other);
        Bus operator=(const Bus &other);
        ~Bus();

        int diskon(int lamaSewa);
    private:
        int kapasitas;
};

class Minibus : public Kendaraan{
    public:
        Minibus();
        Minibus(const Minibus &other);
        Minibus operator=(const Minibus &other);
        ~Minibus();

};

class Mobil : public Kendaraan{
    public:
        Mobil();
        Mobil(string supir);
        Mobil(const Mobil &other);
        Mobil operator=(const Mobil &other);
        ~Mobil();

    private:
        string supir;
};

#endif