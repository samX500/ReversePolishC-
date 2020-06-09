//
// Created by Proprio on 2020-05-30.
//

#ifndef STACK_OPPERATOR_H
#define STACK_OPPERATOR_H


#include <string>
#include <functional>
#include "ArithmeticExpression.h"

class Opperator : public ArithmeticExpression{

    std::function<double(double,double)> opperation;
    ArithmeticExpression* leftHandSide;
    ArithmeticExpression* rightHandSide;


public:
    explicit Opperator(std::function<double(double,double)> opperation,ArithmeticExpression* leftHandSide,ArithmeticExpression* rightHandSide){
        this->opperation= opperation;
        this->leftHandSide = leftHandSide;
        this->rightHandSide = rightHandSide;
    }

    double getValue() override{
        return opperation(leftHandSide->getValue(),rightHandSide->getValue());
    }
};


#endif //STACK_OPPERATOR_H
