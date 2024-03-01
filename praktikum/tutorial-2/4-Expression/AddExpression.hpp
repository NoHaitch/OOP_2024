#include "Expression.hpp"

#ifndef _ADDEXPRESSION_HPP_
#define _ADDEXPRESSION_HPP_

class AddExpression : public BinaryExpression {
    public:
        AddExpression(Expression* x, Expression* y);
        int solve();
};

#endif