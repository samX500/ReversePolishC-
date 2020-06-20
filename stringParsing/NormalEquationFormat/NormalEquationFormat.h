//
// Created by Proprio on 2020-06-08.
//

#ifndef STACK_NORMALEQUATIONFORMAT_H
#define STACK_NORMALEQUATIONFORMAT_H


#include <string>
#include "../EquationParser.h"
#include "EquationNormalFormat.h"

class NormalEquationFormat : public EquationParser {
    NormalEquationIdentifier identifier;

public:
    NormalEquationFormat() {
        identifier = NormalEquationIdentifier();
    }

public:
    Stack<std::string> parseEquation(std::string equation) override {

        return parseEquation(EquationNormalFormat(equation), new Stack<std::string>());
    }

private:
    Stack<std::string> parseEquation(EquationNormalFormat equation, Stack<std::string> *stack) {

        if (equation.hasLowPriorityOpperator()) {
            addToStack(equation.getLowestPriorityOpperator(), stack);
            TwoSidedEquationAsString cuttedEquation = equation.cutOnLowestPriorityOpperator();
            parseEquation(EquationNormalFormat(cuttedEquation.getLeftHandSide()), stack);
            parseEquation(EquationNormalFormat(cuttedEquation.getRightHandSide()), stack);
        } else {
            if (equation.isAFunction()) {
                addToStack(equation.getFunction(),stack);
                parseEquation(EquationNormalFormat(equation.getFunctionInside()), stack);
            } else {
                addToStack(equation.getAsString(), stack);
            }
        }
    }

private:
    void addToStack(std::string equation, Stack<std::string> *stack) {
        stack->put(equation);
    }


};


#endif //STACK_NORMALEQUATIONFORMAT_H
