//
// Created by Proprio on 2020-06-12.
//

#ifndef STACK_EQUATIONFACTORY_H
#define STACK_EQUATIONFACTORY_H


#include "Equation.h"
#include "NormalEquationFormat/EquationNormalFormat.h"

class EquationFactory {
public :
    enum EquationType {NORMAL};

public:
    Equation* getEquation(EquationType equationType,std::string equation){
        switch (equationType) {
            case NORMAL:
                return new EquationNormalFormat(equation);

            default: throw std::invalid_argument("not an equation format");
        }
    }
};


#endif //STACK_EQUATIONFACTORY_H
