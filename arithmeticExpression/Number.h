//
// Created by Proprio on 2020-05-30.
//

#ifndef STACK_NUMBER_H
#define STACK_NUMBER_H


#include <string>
#include "ArithmeticExpression.h"

class Number:public ArithmeticExpression {
    double number;

public:
    explicit Number(double number){
        this->number = number;
    }

public:
    double getValue() override{
        return number;
    }


};


#endif //STACK_NUMBER_H
