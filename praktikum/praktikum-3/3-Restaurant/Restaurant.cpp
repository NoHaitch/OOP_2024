#include "Restaurant.hpp"

/*
    Constructor untuk membuat restaurant
    Order kosong
*/
Restaurant::Restaurant(){}

/*
    Destructor
*/
Restaurant::~Restaurant(){}

/*
    Menambahkan satu order makanan sejumlah val menu

    Contoh:
    Order = (3, 4, 5)
    val = 2

    Maka order = (2, 3, 4, 5)
*/
void Restaurant::Push(int val){
    order.push(val);
}

/*
    Memproses order makanan sebanyak val
    Apabila val lebih banyak dari jumlah order makanan yang ada, keluarkan "Proses tidak valid"
    dan tidak ada order makanan yang diproses

    Contoh:
    Order = (3, 4, 5)
    val = 2

    maka order = (5)
*/
void Restaurant::Pop(int val){
    if(val > order.size()){
        cout << "Proses tidak valid" << endl;
        return;
    }
    
    for(int i = 0; i < val; i++){
        order.pop();
    }
}

/*
    Menambahkan k order makanan paling akhir diproses sejumlah val menu
    Apabila k lebih besar dari banyaknya order makanan, tambahkan semua order makan sejumlah val menu

    Contoh:
    Order = (1, 2, 3)
    k = 2, val = 3

    maka order = (1, 5, 6)
*/
void Restaurant::AddMenu(int k, int val){
    stack<int> tempStack;
    while(order.size() > k){
        int temp = order.top();
        order.pop();
        tempStack.push(temp);
    }

    while(order.size() > 0){
        int temp = order.top() + val;
        order.pop();
        tempStack.push(temp);
    }

    order = tempStack;
    Reorder(order.size());
}


/*
    Memutar urutan pemrosesan k order makanan paling bawah
    Contoh: 
    k = 3
    order =  1 2 3 4 5 (1 merupakan order makanan paling atas untuk diproses)

    Hasil
    order = 1 2 5 4 3

    Jika k > jumlah order, putar seluruh urutan order makanan
*/
void Restaurant::Reorder(int k){
    stack<int> tempStack;
    if (k > order.size()){
        while (order.size() > 0){
            int temp = order.top();
            order.pop();
            tempStack.push(temp);
        }
        
    } else {
        stack<int>tempStack2;
        while(order.size() > k){
            int temp = order.top();
            order.pop();
            tempStack2.push(temp);
        }

        while(order.size() > 0){
            int temp = order.top();
            order.pop();
            tempStack.push(temp);
        }

        while(tempStack2.size() > 0){
            int temp = tempStack2.top();
            tempStack2.pop();
            tempStack.push(temp);
        }
    }

    order = tempStack;
}

/*
    Mencetak order makanan pada restaurant dimulai dari paling awal diproses
    Contoh = (1, 2, 3, 4, 5)
    Apabila order kosong cetak ()
*/
ostream& operator<<(ostream& stream, Restaurant R){
    int size = R.order.size();

    stream << "(";
    for(int i = 0; i < size; i++){
        stream << R.order.top();
        if(i != size - 1){
            stream << ", ";
        }
        R.order.pop();
    }
    stream << ")" << endl;

    return stream;
}