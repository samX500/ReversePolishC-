//
// Created by Proprio on 2020-06-09.
//

#ifndef STACK_CALCULATOR_H
#define STACK_CALCULATOR_H


#include <string>

class Calculator {
public:
    virtual double evaluate(std::string equation)=0;
};


#endif //STACK_CALCULATOR_H
