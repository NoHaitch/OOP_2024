#include "Expression.hpp"

#ifndef _NEGATIVEEXPRESSION_HPP_
#define _NEGATIVEEXPRESSION_HPP_

class NegativeExpression : public UnaryExpression {
    public:
        NegativeExpression(Expression* x);
        int solve();
};

#endif