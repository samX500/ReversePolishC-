//
// Created by Proprio on 2020-06-20.
//

#ifndef STACK_TWOSIDEDEQUATIONASSTRING_H
#define STACK_TWOSIDEDEQUATIONASSTRING_H


#include <string>

class TwoSidedEquationAsString {

    std::string leftHandSide;
    std::string rightHandSide;

public: TwoSidedEquationAsString(std::string leftHandSide, std::string rightHandSide){
        this->leftHandSide = leftHandSide;
        this->rightHandSide = rightHandSide;
    }

public:
    std::string getLeftHandSide(){
        return leftHandSide;
    }

public:
    std::string getRightHandSide(){
        return rightHandSide;
    }
};


#endif //STACK_TWOSIDEDEQUATIONASSTRING_H
