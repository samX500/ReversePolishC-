//
// Created by Proprio on 2020-05-30.
//

#ifndef STACK_FUNCTION_H
#define STACK_FUNCTION_H

#include <functional>
#include "ArithmeticExpression.h"

class Function : public ArithmeticExpression {

    std::function<double(double)> function;
    ArithmeticExpression* content;

public:
    Function(std::function<double(double)> function,
             ArithmeticExpression* content) {
        this->function= function;
        this->content = content;
    }

    double getValue() override {
        return function(content->getValue());
    }
};


#endif //STACK_FUNCTION_H
