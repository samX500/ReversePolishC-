//
// Created by Proprio on 2020-06-09.
//

#ifndef STACK_EQUATIONPARSER_H
#define STACK_EQUATIONPARSER_H


#include <string>
#include "../dataStructure/Stack.hpp"

class EquationParser {
    virtual Stack<std::string> parseEquation(std::string equation)=0;
};


#endif //STACK_EQUATIONPARSER_H
