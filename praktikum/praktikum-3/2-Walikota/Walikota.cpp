#include <iostream>
#include "Walikota.hpp"

/*
    Membuat objek Walikota dengan jumlah default kayu, gulden, dan pekerja
*/
Walikota::Walikota(){
    kayu = DEFAULT_KAYU;
    gulden = DEFAULT_GULDEN;
    pekerja = DEFAULT_PEKERJA;
}

/*
    Membuat objek Walikota dengan jumlah kayu, gulden, dan pekerja sesuai argumen.
*/
Walikota::Walikota(int kayu, int gulden, int pekerja){
    this->kayu = kayu;
    this->gulden = gulden;
    this->pekerja = pekerja;
}

/*
    Menghancurkan objek walikota
*/
Walikota::~Walikota(){}

/*
    Membangun bangunan baru sesuai nama yang diberikan. Metode ini menggunakan metode pakaiKayu, pakaiGulden, perkejakanPekerja secara urut. 
    Untuk membuat satu bangunan, akan menghabiskan kayu dan gulden sesuai input dan akan dialokasikan 1 pekerja.

    Bangunan gagal dibangun apabila:
    1. Kayu habis. Keluarkan pesan dari exception ditambah dengan ", beli kayu dulu."
    2. Gulden habis. Keluarkan pesan dari exception ditambah dengan ", tagih pajak dulu."
    3. Tidak ada pekerja. Keluarkan pesan dari exception ditambah dengan ", rekrut pekerja dulu."

    Jika gagal dibangun, jumlah kayu, gulden, dan pekerja tidak berkurang. Gunakan metode batalPakaiKayu, batalPakaiGulden, dan batalkanPekerja.

    Jika berhasil, masukkan bangunan ke daftar bangunan dengan metode push_back(Bangunan b) dari vector. Selain itu, tampilkan 
    pesan "Bangunan [<nomor_bangunan>] <nama_bangunan> berhasil dibangun". Untuk mengetahui panjang list saat ini gunakan metode size()

    (semua output ditambah newline)
*/
void Walikota::bangunBangunan(string namaBangunan, int kayu, int gulden){
    try{
        pakaiKayu(kayu);
        pakaiGulden(gulden);
        pekerjakanPekerja();

        bangunan.push_back(Bangunan(namaBangunan));
        std::cout << "Bangunan [" << bangunan.size() << "] " << namaBangunan << " berhasil dibangun" << endl;
    
    } catch(KayuTidakCukupException e){
        std::cout << e.what() << ", beli kayu dulu." << endl; 
        
    } catch(GuldenTidakCukupException e){
        batalPakaiKayu(kayu); 
        std::cout << e.what() << ", tagih pajak dulu." << endl; 

    } catch(PekerjaTidakCukupException e){ 
        batalPakaiKayu(kayu);
        batalPakaiGulden(gulden); 
        std::cout << e.what() << ", rekrut pekerja dulu." << endl; 
    }
}

/*
    Menambahkan kayu sesuai num
*/
void Walikota::tambahKayu(int num){
    kayu += num;
}

/*
    Menambahkan gulden sesuai num
*/
void Walikota::tambahGulden(int num){
    gulden += num;
}

/*
    Menambahkan pekerja sesuai num
*/
void Walikota::tambahPekerja(int num){
    pekerja += num;
}

/*
    Menggunakan kayu sesuai num

    Lemparkan exception KayuTidakCukupException jika kayu tidak cukup. Kayu tidak digunakan.
*/
void Walikota::pakaiKayu(int num){
    if(kayu < num){
        throw KayuTidakCukupException();
    } else{
        kayu -= num;
    }
}

/*
    Menggunakan gulden sesuai num

    Lemparkan exception GuldenTidakCukupException jika gulden tidak cukup. Gulden tidak digunakan.
*/
void Walikota::pakaiGulden(int num){
    if(gulden < num){
        throw GuldenTidakCukupException();
    } else{
        gulden -= num;
    }
}

/*
    Mempekerjakan 1 pekerja

    Lemparkan exception PekerjaTidakCukupException jika pekerja tidak cukup. Pekerja batal bekerja.
*/
void Walikota::pekerjakanPekerja(){
    if(pekerja < 1){
        throw PekerjaTidakCukupException();
    } else{
        pekerja --;
    }
}

/*
    Membatalkan penggunaan kayu sesuai num
*/
void Walikota::batalPakaiKayu(int num){
    kayu += num;
}

/*
    Membatalkan penggunaan gulden sesuai num
*/
void Walikota::batalPakaiGulden(int num){
    gulden += num;
}

/*
    Membatalkan 1 pekerja
*/
void Walikota::batalkanPekerja(){
    pekerja++;
}

/*
    Menyebut bangunan pada index idx. Gunakan metode at(int idx) untuk mengakses bangunan. Tampilkan "<nama_bangunan>" jika idx valid.

    Tampilkan exception yang dilemparkan c++ ketika idx tidak valid. Akhiri dengan newline.
*/
void Walikota::sebutBangunan(int idx){
    try{
        std::cout << bangunan.at(idx).getNamaBangunan() << endl;
    } catch(exception e){
        std::cout << e.what() << endl;
    }
}

/*
    Menampilkan status kota dengan format:
    
    Status
      Kayu: <jumlah_kayu>
      Gulden: <jumlah_gulden>
      Pekerja: <jumlah_pekerja>
      Bangunan:
        Bangunan[i]: <nama_bangunan>
*/
void Walikota::statusKota(){
    cout << "Status" << endl;
    cout << "  Kayu: " << kayu << endl;
    cout << "  Gulden: " << gulden << endl;
    cout << "  Pekerja: " << pekerja << endl;
    cout << "  Bangunan:" << endl;
    for (int i = 0; i < bangunan.size(); i++){
        cout << "    Bangunan[" << i + 1 << "]: " << bangunan[i].getNamaBangunan() << endl;
    }
    
}