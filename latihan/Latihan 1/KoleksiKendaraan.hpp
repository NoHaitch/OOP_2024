#ifndef __KOLEKSI_KENDARAAN_HPP__
#define __KOLEKSI_KENDARAAN_HPP__

#include <vector>
#include "Kendaraan.hpp"

using namespace std;

class KoleksiKendaraan{
    public:
        /* CTOR - Default */
        KoleksiKendaraan();
        /* CTOR - User Defined */
        KoleksiKendaraan(int size, int nEff);
        /* CCTOR */
        KoleksiKendaraan(KoleksiKendaraan &other);
        /* Copy Asignment */
        KoleksiKendaraan operator=(KoleksiKendaraan &other);
        /* DTOR */
        ~KoleksiKendaraan();

        void printAll();
        void operator<<(const Kendaraan &kendaraan);
        void operator<<(const KoleksiKendaraan &kendaraan);

    private:
        int size;
        int nEff;
        vector<Kendaraan> koleksi;
};

#endif