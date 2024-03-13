#include "Hero.hpp"
#include "Axe.hpp"
#include "Invoker.hpp"

int main() {
    Invoker A(10, 1000);
    A.useSkill();
    Hero *B = new Invoker(A);
    (*B).heal(1);
    Invoker *C = new Invoker(50, 200);
    (*C).move(10, 25);
    (*C) = A;

    Axe (*E) = new Axe(200, 10);
    E->move(2, 20);
    E->heal(10);
    Axe *F = new Axe(*E);
    Axe H(*E + *E);

    E->useSkill();
    (H).useSkill();
    E->~Axe();
    return 0;
}
