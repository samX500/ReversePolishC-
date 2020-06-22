//
// Created by Proprio on 2020-06-14.
//

#ifndef STACK_NORMALEQUATIONIDENTIFIER_H
#define STACK_NORMALEQUATIONIDENTIFIER_H


#include <vector>
#include <string>
#include <algorithm>
#include <map>

class NormalEquationIdentifier {
public:
    int HIGHEST_PRIORITY = 10000;

private:
    std::vector<std::string> OPENING_BRACKET = {"(","["};
    std::vector<std::string> CLOSING_BRACKET = {")","]"};
    std::map<std::string,int> OPPERATOR_PRIORITY;

public:NormalEquationIdentifier(){
        instantializeOpperatorPriority();
    }


private:
    void instantializeOpperatorPriority(){
        OPPERATOR_PRIORITY.insert(std::pair<std::string,int>("+",1));
        OPPERATOR_PRIORITY.insert(std::pair<std::string,int>("-",1));
        OPPERATOR_PRIORITY.insert(std::pair<std::string,int>("*",2));
        OPPERATOR_PRIORITY.insert(std::pair<std::string,int>("/",2));
    }

public:
    bool isOpeningBracket(std::string character){
        return std::find(std::begin(OPENING_BRACKET), std::end(OPENING_BRACKET), character) != std::end(OPENING_BRACKET);;
    }

public:
    bool isClosingBracket(std::string character){
         return std::find(std::begin(CLOSING_BRACKET), std::end(CLOSING_BRACKET), character) != std::end(CLOSING_BRACKET);
    }

public:
    bool isOpperator(std::string character){
        return OPPERATOR_PRIORITY.find(character)!=OPPERATOR_PRIORITY.end();
    }

public:
    int getOpperatorPriority(std::string opperator){
        return OPPERATOR_PRIORITY.at(opperator);
    }
};


#endif //STACK_NORMALEQUATIONIDENTIFIER_H
