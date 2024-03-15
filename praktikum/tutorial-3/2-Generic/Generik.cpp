#include <iostream>
using namespace std;

template <class T>
void func (T a, T b) {
    cout << "Masukan Anda: " << a << " dan " << b << ", memiliki tipe yang sama" << endl;
}

template <class T, class U>
void func (T a, U b) {
    cout << "Masukan Anda: " << a << " dan " << b << ", mungkin memiliki tipe yang berbeda" << endl;
}

template <>
void func (char a, int b) {
    for (int i = 0; i < b; i++) {
        cout << a << endl;
    }
}