#include <iostream>
#include "NegativeExpression.hpp"

using namespace std;

NegativeExpression::NegativeExpression(Expression* x) : UnaryExpression(x) {}

int NegativeExpression::solve() {
    return x->solve() * -1;
}