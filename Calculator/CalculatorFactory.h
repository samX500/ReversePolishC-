//
// Created by Proprio on 2020-06-09.
//

#ifndef STACK_CALCULATORFACTORY_H
#define STACK_CALCULATORFACTORY_H


#include <stdexcept>
#include "Calculator.h"
#include "ReversePolishCalculator.h"

class CalculatorFactory {
public:
    enum CalculatorType {REVERSE_POLISH};

public:
    Calculator* getCalculator(CalculatorType wantedCalculator){
        switch (wantedCalculator) {
            case REVERSE_POLISH:
                return new ReversePolishCalculator();

            default: throw std::invalid_argument("cute little anime girl");
        }
    }

};


#endif //STACK_CALCULATORFACTORY_H
