#ifndef __KENDARAAN_HPP__
#define __KENDARAAN_HPP__

class Kendaraan {
    public:
        /* CTOR - Default */
        Kendaraan();
        /* CTOR - User Defined */
        Kendaraan(int nomor, int tahunKeluaran, string merk, string kategori);
        /* CCTOR */
        Kendaraan(Kendaraan &other);
        /* Copy Asignment */
        Kendaraan operator=(Kendaraan &other);
        /* DTOR */
        ~Kendaraan();

        void printInfo();
        virtual int biayaSewa(int lamaSewa);

    private:
        int nomor;
        int tahunKeluaran;
        string kategori;
        string merk;

};

#endif