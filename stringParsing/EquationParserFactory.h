//
// Created by Proprio on 2020-06-12.
//

#ifndef STACK_EQUATIONPARSERFACTORY_H
#define STACK_EQUATIONPARSERFACTORY_H


#include "EquationParser.h"
#include "NormalEquationFormat/NormalEquationFormat.h"

class EquationParserFactory {
public :
    enum EquationParserType {NORMAL};

public:
    EquationParser* getEquationParser(EquationParserType parserType){
        switch (parserType) {
            case NORMAL:
                return new NormalEquationFormat();

            default: throw std::invalid_argument("cute little anime girl");
        }
    }
};


#endif //STACK_EQUATIONPARSERFACTORY_H
