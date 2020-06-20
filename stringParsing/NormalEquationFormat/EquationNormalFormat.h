//
// Created by Proprio on 2020-06-14.
//

#ifndef STACK_EQUATIONNORMALFORMAT_H
#define STACK_EQUATIONNORMALFORMAT_H


#include <string>
#include "../../dataStructure/List.hpp"
#include "NormalEquationIdentifier.h"
#include "../../Utility/TwoSidedEquationAsString.h"

class EquationNormalFormat {

    std::string equation;
    NormalEquationIdentifier identifier;

public:
    EquationNormalFormat(std::string equation) {
        this->equation = equation;
        identifier = NormalEquationIdentifier();

    }

public:
    std::string getCharAt(int index) {
        return std::string(1, equation[index]);
    }

public:
    int getLowestPriorityOpperatorIndex() {
        List<int> indexOfElementInsideFunction = getIndexOfOpperatorInsideFunction();
        int currentLowestPriorityOpperator = -1;
        int currentPriority = identifier.HIGHEST_PRIORITY;

        for (std::string::size_type i = 0; i < equation.size(); i++) {
            std::string currentCharacter(1, equation[i]);
            if (identifier.isOpperator(currentCharacter) && !indexOfElementInsideFunction.contains(i)) {
                if (identifier.getOpperatorPriority(currentCharacter) < currentPriority) {
                    currentLowestPriorityOpperator = i;
                    currentPriority = identifier.getOpperatorPriority(currentCharacter);
                }
            }
        }

        return currentLowestPriorityOpperator;
    }

private:
    List<int> getIndexOfOpperatorInsideFunction() {
        List<int> indexOfOpperatorInsideFunction = List<int>();
        int depthOfFunction = 0;

        for (std::string::size_type i = 0; i < equation.size(); i++) {
            std::string currentCharacter(1, equation[i]);
            if (identifier.isOpeningBracket(currentCharacter))
                depthOfFunction++;
            else if (identifier.isClosingBracket(currentCharacter))
                depthOfFunction--;
            else if (depthOfFunction > 0 && identifier.isOpperator(currentCharacter))
                indexOfOpperatorInsideFunction.add(i);
        }

        return indexOfOpperatorInsideFunction;
    }

public:
    bool hasLowPriorityOpperator() {
        return getLowestPriorityOpperatorIndex() >= 0;
    }

public:
    TwoSidedEquationAsString cutOnLowestPriorityOpperator() {
        int indexOfLowestPriorityOpperator = getLowestPriorityOpperatorIndex();
        if (indexOfLowestPriorityOpperator < 0)
            throw std::invalid_argument("Equation has no low priority opperator to cut on");
        std::string leftHandSide = equation.substr(0, indexOfLowestPriorityOpperator);
        std::string rightHandSide = equation.substr(indexOfLowestPriorityOpperator + 1, equation.size());
        return TwoSidedEquationAsString(leftHandSide, rightHandSide);
    }

public:
    std::string getLowestPriorityOpperator() {
        int indexOfLowestPriorityOpperator = getLowestPriorityOpperatorIndex();
        if (indexOfLowestPriorityOpperator < 0)
            return "";
        return getCharAt(indexOfLowestPriorityOpperator);
    }


public:
    bool isAFunction() {
        return !hasLowPriorityOpperator() && identifier.isClosingBracket(getCharAt(equation.size() - 1));
    }

public:
    std::string getFunction() {
        if (!isAFunction())
            throw std::invalid_argument("Cannot call getFunction on an equation that is not a function");

        std::string function = "";
        for (std::string::size_type i = 0; i < equation.size(); i++) {
            if (identifier.isOpeningBracket(getCharAt(i)))
                break;
            else
                function += getCharAt(i);
        }

        return function;
    }

public:
    std::string getFunctionInside() {
        if (!isAFunction())
            throw std::invalid_argument("Cannot call getFunction on an equation that is not a function");

        int functionStart = getFirstOpeningBracketIndex();
        return equation.substr(functionStart+1,equation.size()-functionStart-2);
    }

private:
    int getFirstOpeningBracketIndex() {
        for (std::string::size_type i = 0; i < equation.size(); i++) {
            if (identifier.isOpeningBracket(getCharAt(i)))
                return i;
        }
        throw std::invalid_argument("Cannot call getFunction on an equation that is not a function");
    }

public:
    std::string getAsString() {
        return equation;
    }
};


#endif //STACK_EQUATIONNORMALFORMAT_H
