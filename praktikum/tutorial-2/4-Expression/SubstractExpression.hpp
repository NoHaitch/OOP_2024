#include "Expression.hpp"

#ifndef _SUBSTRACTEXPRESSION_HPP_
#define _SUBSTRACTEXPRESSION_HPP_

class SubstractExpression : public BinaryExpression {
    public:
        SubstractExpression(Expression* x, Expression* y);
        int solve();
};

#endif