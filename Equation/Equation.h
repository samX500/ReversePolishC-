//
// Created by Proprio on 2020-06-09.
//

#ifndef STACK_EQUATION_H
#define STACK_EQUATION_H


#include <string>
#include "../dataStructure/Stack.hpp"
#include "../Utility/TwoSidedEquationAsString.h"

class Equation {
    virtual int getLowestPriorityOpperatorIndex()=0;
    virtual bool hasLowPriorityOpperator()=0;
    virtual TwoSidedEquationAsString cutOnLowestPriorityOpperator()=0;
    virtual std::string getLowestPriorityOpperator()=0;
    virtual bool isAFunction()=0;
    virtual std::string getFunction()=0;
    virtual std::string getFunctionInside()=0;
    virtual bool isANumber()=0;
    virtual int getNumber()=0;
};


#endif //STACK_EQUATION_H
