#include "A.hpp"

int main(){
    A* x = new A('1');
    A* y = new A('2');
    A* z = new A(*x);

    *x = *y;

    x->show();

    x->~A();
    y->~A();
    z->~A();

    return 0;
}

// dont know why but without using pointers it exited at operator=