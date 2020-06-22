//
// Created by Proprio on 2020-05-28.
//

#ifndef STACK_REVERSEPOLISHCALCULATOR_H
#define STACK_REVERSEPOLISHCALCULATOR_H


#include <string>
#include "Calculator.h"
#include "../Equation//NormalEquationFormat/NormalEquationIdentifier.h"

class ReversePolishCalculator: public Calculator {

    NormalEquationIdentifier identifier;

public: ReversePolishCalculator(){
    identifier = NormalEquationIdentifier();
}

public:
    double evaluate(std::string equation) override{
        return 0;
    }


};


#endif //STACK_REVERSEPOLISHCALCULATOR_H
