//
// Created by Proprio on 2020-05-28.
//

#ifndef STACK_REVERSEPOLISHCALCULATOR_H
#define STACK_REVERSEPOLISHCALCULATOR_H


#include <string>
#include <functional>
#include "Calculator.h"
#include "../Equation//NormalEquationFormat/NormalEquationIdentifier.h"
#include "../Equation/NormalEquationFormat/EquationNormalFormat.h"
#include "../Equation/EquationFactory.h"

class ReversePolishCalculator: public Calculator {

    NormalEquationIdentifier identifier;

public: ReversePolishCalculator(){
    identifier = NormalEquationIdentifier();
}

public:
    double evaluate(std::string equationAsString) override{
        EquationFactory factory = EquationFactory();
        Equation* equation = factory.getEquation(EquationFactory::NORMAL,equationAsString);
        return solve(equation);
    }

private:


    double solve(Equation* equation){
        if(equation->hasLowPriorityOpperator())
            return solveOpperator(equation);
        else if(equation->isAFunction())
            return solveFunction(equation);
        else if(equation->isANumber())
            return solveNumber(equation);
    }

    double solveOpperator(Equation* equation) {
        std::function<double(double,double)> opperator = identifier.getOpperator(equation->getLowestPriorityOpperator());
        TwoSidedEquationAsString bothSide = equation->cutOnLowestPriorityOpperator();
        EquationFactory factory = EquationFactory();
        Equation* leftHandSide = factory.getEquation(EquationFactory::NORMAL,bothSide.getLeftHandSide());
        Equation* rightHandSide = factory.getEquation(EquationFactory::NORMAL,bothSide.getRightHandSide());
        return opperator(solve(leftHandSide),solve(rightHandSide));
    }

    double solveFunction(Equation* equation) {
        std::function<double(double)> function = identifier.getFunction(equation->getFunction());
        EquationFactory factory = EquationFactory();
        Equation* functionInside = factory.getEquation(EquationFactory::NORMAL,equation->getFunctionInside());
        return function(solve(functionInside));
    }

    double solveNumber(Equation* equation) {
        return equation->getNumber();
    }
};


#endif //STACK_REVERSEPOLISHCALCULATOR_H
