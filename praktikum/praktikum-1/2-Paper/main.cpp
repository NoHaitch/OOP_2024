#include "Paper.hpp"

int main() {
    Paper *a = new Paper('A');
    Paper *b = new Paper('B');
    Paper *c = new Paper('C');
    Paper *d = new Paper(*c);
    (*a).fold();
    (*b).fold();
    (*c).fold();
    (*c).glue();
    (*a).~Paper();
    (*c).setName('X');
    (*d).fold();
    (*d).glue();
    (*d).~Paper();
    (*c).~Paper();
    (*b).~Paper();

    return 0;
}

// ctor A
// ctor B
// ctor C
// cctor C
// fold A(1)
// fold B(1)
// fold C(1)
// glue C
// fold C(2)
// dtor A
// setName C => X
// fold C(1)
// glue C
// fold C(2)
// dtor C
// dtor X
// dtor B