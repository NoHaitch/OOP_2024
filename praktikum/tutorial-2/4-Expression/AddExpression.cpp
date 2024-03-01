#include <iostream>
#include "AddExpression.hpp"

using namespace std;

AddExpression::AddExpression(Expression* x, Expression* y) : BinaryExpression(x, y) {}

int AddExpression::solve() {
    return x->solve() + y->solve();
}