// File: main.cpp

#include "Pakaian.hpp"

int BajuPolo::jumlah = 5;
int Baju::defaultTahun = 1991;
int Baju::defaultUkuran = 69;

int main() {
    Pakaian *arrPakaian[5];
    Baju baju1 = Baju();
    Baju baju2("Skywalker", 30, 2020);
    baju2.pakai();
    baju2.printStatus();
    Baju baju3("Harkonen", 40, 2021);
    baju3.pakai();

    Baju* baju4 = new BajuPolo("Kate", 2022);
    Baju *baju5 = new BajuPolo("Muadib", 2023);
    baju5->pakai();

    arrPakaian[0] = &baju1;
    arrPakaian[1] = &baju2;
    arrPakaian[2] = baju4;

    for (int i = 0; i < 3; i++) {
        arrPakaian[i]->pakai();
        arrPakaian[i]->printStatus();
    }

    Baju::defaultUkuran = 11;
    Baju::defaultTahun = 476;
    baju1.printStatus();

    BajuPolo *baju6 = new BajuPolo("Roosevelt", 2024, 0.7);
    BajuPolo baju7(*baju6);
    BajuPolo baju8 = baju7;
    baju6->pakai();
    baju7.printStatus();
    baju8.printStatus();
    baju8.pakai();

    delete baju5;
    delete baju6;
    delete baju4;

    arrPakaian[0] = &baju3;
    arrPakaian[2] = &baju7;
    for (int i = 0; i < 3; i++) {
        arrPakaian[i]->pakai();
        arrPakaian[i]->printStatus();
    }

    Celana celana1 = Celana("Aki Hayakawa", 50, true);
    Celana celana2(celana1, "Tifa");
    Celana celana3 = Celana("Yoseph", 23, false);

    arrPakaian[3] = &celana1;
    arrPakaian[4] = &celana3;
    for (int i = 3; i < 5; i++) {
        arrPakaian[i]->pakai();
        arrPakaian[i]->printStatus();
    }

    arrPakaian[2] = &celana2;
    for (int i = 0; i < 5; i++) {
        arrPakaian[i]->pakai();
        arrPakaian[i]->printStatus();
    }


  return 0;
}

/* EXPECTED OUTPUT 
Skywalker pake baju dari atas

[Status] Pakaian milik 'Skywalker' dengan ukuran 30 tahun 2020

Harkonen pake baju dari atas

Muadib pake baju dari atas

anonim pake baju dari atas

[Status] Pakaian milik 'anonim' dengan ukuran 69 tahun 1991

Skywalker pake baju dari atas

[Status] Pakaian milik 'Skywalker' dengan ukuran 30 tahun 2020

Kate pake baju dari atas

[Status] Pakaian milik 'Kate' dengan ukuran 69 tahun 2022 dengan panjang kerah 0.5 keluaran ke-6

[Status] Pakaian milik 'anonim' dengan ukuran 69 tahun 1991

Roosevelt pake baju dari atas

[Status] Pakaian milik 'Roosevelt' dengan ukuran 11 tahun 2024 dengan panjang kerah 0.7 keluaran ke-9

[Status] Pakaian milik 'Roosevelt' dengan ukuran 11 tahun 2024 dengan panjang kerah 0.7 keluaran ke-10

Roosevelt pake baju dari atas

[D] Baju Polo milik 'Muadib' hancur

[D] Baju milik 'Muadib' hancur

[D] Pakaian milik 'Muadib' hancur

[D] Baju Polo milik 'Roosevelt' hancur

[D] Baju milik 'Roosevelt' hancur

[D] Pakaian milik 'Roosevelt' hancur

[D] Baju Polo milik 'Kate' hancur

[D] Baju milik 'Kate' hancur

[D] Pakaian milik 'Kate' hancur

Harkonen pake baju dari atas

[Status] Pakaian milik 'Harkonen' dengan ukuran 40 tahun 2021

Skywalker pake baju dari atas

[Status] Pakaian milik 'Skywalker' dengan ukuran 30 tahun 2020

Roosevelt pake baju dari atas

[Status] Pakaian milik 'Roosevelt' dengan ukuran 11 tahun 2024 dengan panjang kerah 0.7 keluaran ke-9

Aki Hayakawa pake celana dari bawah dengan sabuk

[Status] Pakaian milik 'Aki Hayakawa' dengan ukuran 50 dengan sabuk

Yoseph pake celana dari bawah

[Status] Pakaian milik 'Yoseph' dengan ukuran 23

Harkonen pake baju dari atas

[Status] Pakaian milik 'Harkonen' dengan ukuran 40 tahun 2021

Skywalker pake baju dari atas

[Status] Pakaian milik 'Skywalker' dengan ukuran 30 tahun 2020

Tifa pake celana dari bawah dengan sabuk

[Status] Pakaian milik 'Tifa' dengan ukuran 50 dengan sabuk

Aki Hayakawa pake celana dari bawah dengan sabuk

[Status] Pakaian milik 'Aki Hayakawa' dengan ukuran 50 dengan sabuk

Yoseph pake celana dari bawah

[Status] Pakaian milik 'Yoseph' dengan ukuran 23

[D] Celana milik 'Yoseph' hancur

[D] Pakaian milik 'Yoseph' hancur

[D] Celana milik 'Tifa' hancur

[D] Pakaian milik 'Tifa' hancur

[D] Celana milik 'Aki Hayakawa' hancur

[D] Pakaian milik 'Aki Hayakawa' hancur

[D] Baju Polo milik 'Roosevelt' hancur

[D] Baju milik 'Roosevelt' hancur

[D] Pakaian milik 'Roosevelt' hancur

[D] Baju Polo milik 'Roosevelt' hancur

[D] Baju milik 'Roosevelt' hancur

[D] Pakaian milik 'Roosevelt' hancur

[D] Baju milik 'Harkonen' hancur

[D] Pakaian milik 'Harkonen' hancur

[D] Baju milik 'Skywalker' hancur

[D] Pakaian milik 'Skywalker' hancur

[D] Baju milik 'anonim' hancur

[D] Pakaian milik 'anonim' hancur
*/