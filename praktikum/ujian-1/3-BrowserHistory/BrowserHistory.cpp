#include "BrowserHistory.hpp"
#include <iostream>

using namespace std;

/*
ctor
*/
BrowserHistory::BrowserHistory(){
    historyBack = stack<string> ();
    historyForward = stack<string> ();
}

/*
Dtor
*/
BrowserHistory::~BrowserHistory(){

}

/*
Masuk ke sebuah halaman url
kosongkan stack history forward
Tambahkan url terbaru ke stack history back
*/
void BrowserHistory::visit(string url){
    while(historyForward.size() > 0){
        historyForward.pop();
    }

    historyBack.push(url);
}

/*
Kembali ke url sebelumnya berdasarkan data pada stack history back
Hapus elemen top pada stack history back dan pindahkan ke stack history forward 
Bila sesaat sebelum operasi stack history back kosong maka throw HistoryBackStackEmptyException()
*/
void BrowserHistory::back(){
    if(historyBack.size() == 0){
        throw HistoryBackStackEmptyException();
    }

    historyForward.push(historyBack.top());
    historyBack.pop();
}

/*
Masuk ke url sebelumnya yang sebelumnya pernah dilakukan operasi back berdasarkan data pada stack history forward
Hapus elemen top pada stack history forward dan pindahkan ke stack history back 
Bila sesaat sebelum operasi stack history forward kosong maka throw HistoryForwardStackEmptyException()
*/
void BrowserHistory::forward(){
    if(historyForward.size() == 0){
        throw HistoryForwardStackEmptyException();
    }

    historyBack.push(historyForward.top());
    historyForward.pop();
}

/*
Reverse urutan stack history back pada posisi genap/ganjil (sesuai masukan), top dari stack berada di posisi ke-1 (ganjil)
Misalkan keadaan sebelum operasi : [google1.com,google2.com,google3.com,google4.com,google5.com,google6.com,google7.com] dan isOdd = True
Hasil reverse urutan stack pada posisi ganjil adalah : [google7.com,google2.com,google5.com,google4.com,google3.com,google6.com,google1.com]
*/
void BrowserHistory::reverseOddEven(bool isOdd){
    if(isOdd){
        int size = historyBack.size();
        stack<string> even;
        string odd[int(size / 2) + 1];
        
        int currIdx = 0;

        for(int i = 0; i < size; i++){
            if(i % 2 == 0){
                // odd elements
                odd[currIdx] = historyBack.top();
                currIdx++;
            } else{
                // even elements
                even.push(historyBack.top());
            }

            historyBack.pop();
        }

        currIdx = 0;

        for(int i = 0; i < size; i++){
            if(i % 2 == 1){
                historyBack.push(odd[currIdx]);
                currIdx++;
            } else{
                historyBack.push(even.top());
                even.pop();
            }
        }
    } else{
        int size = historyBack.size();
        stack<string> odd;
        string even[int(size / 2) + 1];
        
        int currIdx = 0;

        for(int i = 0; i < size; i++){
            if(i % 2 == 0){
                // odd elements
                odd.push(historyBack.top());
                
            } else{
                // even elements
                even[currIdx] = historyBack.top();
                currIdx++;
            }

            historyBack.pop();
        }

        currIdx = 0;

        for(int i = 0; i < size; i++){
            if(i % 2 == 1){
                historyBack.push(odd.top());
                odd.pop();
            } else{
                historyBack.push(even[currIdx]);
                currIdx++;
            }
        }
    }

}

/*
Tambahkan seluruh data stack history forward ke stack history back
Misal, stack history forward : [google3.com,google2.com,google5.com] dan stack history back : [google9.com,google6.com,google4.com,google6.com]
Top dari stack history back adalah google3.com sedangkan top dari stack history forward adalah google9.com
Setelah operasi maka stack history back : [google3.com,google2.com,google5.com,google9.com,google6.com,google4.com,google6.com] dan stack history forward tidak berubah
*/
void BrowserHistory::mergeStack(){
    stack<string> temp;
    while(historyBack.size() > 0){
        temp.push(historyBack.top());
        historyBack.pop();
    }

    while(historyForward.size() > 0){
        historyBack.push(historyForward.top());
        historyForward.pop();
    }

    while(temp.size() > 0){
        historyBack.push(temp.top());
        temp.pop();
    }
}

/*
Swap elemen stack history back pada posisi idxBack dan elemen stack history forward pada posisi idxForward
Posisi dihitung dari top dan dimulai dari 1
Misal stack history back : [google3.com,google2.com,google5.com], idxBack = 3 dan stack history forward : [google9.com,google6.com,google4.com,google6.com], idxForward = 2
Top dari stack history back adalah google3.com sedangkan top dari stack history forward adalah google9.com
Hasil akhirnya meliputi  stack history back : [google3.com,google2.com,google6.com] dan stack history forward : [google9.com,google5.com,google4.com,google6.com]
Bila index tidak valid atau berada di luar stack maka throw IndexNotValidException()
*/
void BrowserHistory::swapBetweenStack(int idxBack,int idxForward){
    if(idxBack > historyBack.size() || idxForward > historyForward.size() || idxBack < 1 || idxForward < 1){
        throw IndexNotValidException();
    }

    stack<string> back;
    stack<string> forward;

    while(idxBack > 1){
        back.push(historyBack.top());
        historyBack.pop();
        idxBack--;
    }

    while(idxForward > 1){
        forward.push(historyForward.top());
        historyForward.pop();
        idxForward--;
    }

    //Swap
    string temp = historyBack.top();
    historyBack.pop();
    historyBack.push(historyForward.top());
    historyForward.pop();
    historyForward.push(temp);

    while(back.size() > 0){
        historyBack.push(back.top());
        back.pop();
    }

    while(forward.size() > 0){
        historyForward.push(forward.top());
        forward.pop();
    }
}

/*
Rotasi stack history back sebanyak k pergeseran ke kanan (ke indeks yang lebih besar)
k merupakan bilangan bulat non negatif dan tidak ada batasan dari nilai k
Misalkan stack history back : [google1.com,google2.com,google3.com,google4.com,google5.com,google6.com,google7.com] dan k = 2
Top dari stack history back adalah google1.com
Hasil stack history back setelah operasi : [google6.com,google7.com,google1.com,google2.com,google3.com,google4.com,google5.com]
*/
void BrowserHistory::rotateStack(int k){
    k = k % historyBack.size();
    stack<string> normal;
    stack<string> rotated;

    while(historyBack.size() > k){
        normal.push(historyBack.top());
        historyBack.pop();
    }

    for(int i = 0; i < k; i++){
        rotated.push(historyBack.top());
        historyBack.pop();
    }

    while(normal.size() > 0){
        historyBack.push(normal.top());
        normal.pop();
    }

    while(rotated.size() > 0){
        historyBack.push(rotated.top());
        rotated.pop();
    }
}

/*
Mencetak stack history back dan forward
Stack history back dicetak pada line pertama
Stack history forward dicetak pada line kedua
Setiap line diakhiri dengan endline
Contoh keluaran:
(google3.com,google2.com,google5.com)
(google9.com,google6.com,google4.com,google6.com)
*/
ostream& operator<<(ostream& os,BrowserHistory b){
    os << "(";
    while(b.historyBack.size() != 0){
        os << b.historyBack.top();
        if(b.historyBack.size() != 1){
            os << ",";
        }
        b.historyBack.pop();
    }
    os << ")" << endl;
    
    os << "(";
    while(b.historyForward.size() != 0){
        os << b.historyForward.top();
        if(b.historyForward.size() != 1){
            os << ",";
        }
        b.historyForward.pop();
    }
    os << ")" << endl;

    return os;
}