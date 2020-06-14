//
// Created by Proprio on 2020-06-14.
//

#ifndef STACK_NORMALEQUATIONFORMATPARSER_H
#define STACK_NORMALEQUATIONFORMATPARSER_H


#include <string>
#include "../../dataStructure/List.hpp"
#include "NormalEquationIdentifier.h"

class NormalEquationFormatParser {

    NormalEquationIdentifier identifier;

public: NormalEquationFormatParser(){
    identifier = NormalEquationIdentifier();
}

public:
    int getLowestPriorityOpperator(std::string equation){
        List<int> indexOfElementInsideFunction = getIndexOfOpperatorInsideFunction(equation);
        int currentLowestPriorityOpperator = -1;
        int currentPriority = identifier.HIGHEST_PRIORITY;

        for (std::string::size_type i = 0; i < equation.size(); i++){
            if(identifier.isOpperator((std::string)&equation[i]) && !indexOfElementInsideFunction.contains(i)){
                if(identifier.getOpperatorPriority((std::string)&equation[i])<currentPriority)
                {
                    currentLowestPriorityOpperator = i;
                    currentPriority = identifier.getOpperatorPriority((std::string)&equation[i]);
                }
            }
        }

        return currentLowestPriorityOpperator;
    }

private:
    List<int> getIndexOfOpperatorInsideFunction(std::string equation){
        List<int> indexOfOpperatorInsideFunction = List<int>();
        int depthOfFunction = 0;

        for (std::string::size_type i = 0; i < equation.size(); i++){
            if(identifier.isOpeningBracket((std::string)&equation[i]))
                depthOfFunction++;
            else if(identifier.isClosingBracket((std::string)&equation[i]))
                depthOfFunction--;
            else if(depthOfFunction > 0 && identifier.isOpperator((std::string)&equation[i]))
                indexOfOpperatorInsideFunction.add(i);
        }

        return indexOfOpperatorInsideFunction;
    }
};


#endif //STACK_NORMALEQUATIONFORMATPARSER_H
