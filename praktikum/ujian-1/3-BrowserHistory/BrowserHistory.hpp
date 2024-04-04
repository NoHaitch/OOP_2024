#ifndef BROWSER_HISTORY_HPP
#define BROWSER_HISTORY_HPP 

#include <iostream>
#include <stack>
#include <string>
#include "StackException.hpp"

using namespace std;


class BrowserHistory{
    private:
        /*
        Menyimpan history url yang telah dikunjungi sebelumnya dan url yang dikunjungi saat ini
        Elemen top dari stack merupakan url yang sedang dikunjungi
        */
        stack<string>historyBack;

        /*
        Menyimpan history url yang sebelumnya pernah dilakukan operasi back
        Elemen top dari stack merupakan url yang sedang dikunjungi pada saat sebelum tombol back ditekan
        Stack historyForward perlu dikosongkan ketika browser visit url baru    
        */
        stack<string>historyForward;
    
    public:
        /*
        ctor
        */
        BrowserHistory();

        /*
        Dtor
        */
        ~BrowserHistory();

        /*
        Masuk ke sebuah halaman url
        kosongkan stack history forward
        Tambahkan url terbaru ke stack history back
        */
        void visit(string url);

        /*
        Kembali ke url sebelumnya berdasarkan data pada stack history back
        Hapus elemen top pada stack history back dan pindahkan ke stack history forward 
        Bila sesaat sebelum operasi stack history back kosong maka throw HistoryBackStackEmptyException()
        */
        void back();

        /*
        Masuk ke url sebelumnya yang sebelumnya pernah dilakukan operasi back berdasarkan data pada stack history forward
        Hapus elemen top pada stack history forward dan pindahkan ke stack history back 
        Bila sesaat sebelum operasi stack history forward kosong maka throw HistoryForwardStackEmptyException()
        */
        void forward();

        /*
        Reverse urutan stack history back pada posisi genap/ganjil (sesuai masukan), top dari stack berada di posisi ke-1 (ganjil)
        Misalkan keadaan sebelum operasi : [google1.com,google2.com,google3.com,google4.com,google5.com,google6.com,google7.com] dan isOdd = True
        Hasil reverse urutan stack pada posisi ganjil adalah : [google7.com,google2.com,google5.com,google4.com,google3.com,google6.com,google1.com]
        */
        void reverseOddEven(bool isOdd);

        /*
        Tambahkan seluruh data stack history forward ke stack history back
        Misal, stack history forward : [google3.com,google2.com,google5.com] dan stack history back : [google9.com,google6.com,google4.com,google6.com]
        Top dari stack history back adalah google3.com sedangkan top dari stack history forward adalah google9.com
        Setelah operasi maka stack history back : [google3.com,google2.com,google5.com,google9.com,google6.com,google4.com,google6.com] dan stack history forward tidak berubah
        */
        void mergeStack();

        /*
        Swap elemen stack history back pada posisi idxBack dan elemen stack history forward pada posisi idxForward
        Posisi dihitung dari top dan dimulai dari 1
        Misal stack history back : [google3.com,google2.com,google5.com], idxBack = 3 dan stack history forward : [google9.com,google6.com,google4.com,google6.com], idxForward = 2
        Top dari stack history back adalah google3.com sedangkan top dari stack history forward adalah google9.com
        Hasil akhirnya meliputi  stack history back : [google3.com,google2.com,google6.com] dan stack history forward : [google9.com,google5.com,google4.com,google6.com]
        Bila index tidak valid atau berada di luar stack maka throw IndexNotValidException()
        */
        void swapBetweenStack(int idxBack,int idxForward);

        /*
        Rotasi stack history back sebanyak k pergeseran ke kanan (ke indeks yang lebih besar)
        k merupakan bilangan bulat non negatif dan tidak ada batasan dari nilai k
        Misalkan stack history back : [google1.com,google2.com,google3.com,google4.com,google5.com,google6.com,google7.com] dan k = 2
        Top dari stack history back adalah google1.com
        Hasil stack history back setelah operasi : [google6.com,google7.com,google1.com,google2.com,google3.com,google4.com,google5.com]
        */
        void rotateStack(int k);

        /*
        Mencetak stack history back dan forward
        Stack history back dicetak pada line pertama
        Stack history forward dicetak pada line kedua
        Setiap line diakhiri dengan endline
        Contoh keluaran:
        (google3.com,google2.com,google5.com)
        (google9.com,google6.com,google4.com,google6.com)
        */
        friend ostream& operator<<(ostream&,BrowserHistory);
};

#endif