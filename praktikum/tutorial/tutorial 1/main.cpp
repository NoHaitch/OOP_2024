#include "A.cpp"

int main() {
    A a('1');
    A b('2');
    A c(a);
    b.~A();
    return 0;
}