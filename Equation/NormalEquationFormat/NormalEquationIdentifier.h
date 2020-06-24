//
// Created by Proprio on 2020-06-14.
//

#ifndef STACK_NORMALEQUATIONIDENTIFIER_H
#define STACK_NORMALEQUATIONIDENTIFIER_H


#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <functional>
#include <cmath>

class NormalEquationIdentifier {
public:
    int HIGHEST_PRIORITY = 10000;

private:
    std::vector<std::string> OPENING_BRACKET = {"(","["};
    std::vector<std::string> CLOSING_BRACKET = {")","]"};
    std::map<std::string,int> OPPERATOR_PRIORITY;
    std::map<std::string,std::function<double(double)>> FUNCTION;
    std::map<std::string,std::function<double(double,double)>> OPPERATOR;

public:NormalEquationIdentifier(){
        instantializeOpperatorPriority();
        instantializeFunction();
        instantializeOpperator();
    }


private:
    void instantializeOpperatorPriority(){
        OPPERATOR_PRIORITY.insert(std::pair<std::string,int>("+",1));
        OPPERATOR_PRIORITY.insert(std::pair<std::string,int>("-",1));
        OPPERATOR_PRIORITY.insert(std::pair<std::string,int>("*",2));
        OPPERATOR_PRIORITY.insert(std::pair<std::string,int>("/",2));
    }

private:
    void instantializeFunction(){
        FUNCTION.insert(std::pair<std::string,std::function<double(double)>>("sin",[](double x){return sin(x);}));
        FUNCTION.insert(std::pair<std::string,std::function<double(double)>>("cos",[](double x){return cos(x);}));
        FUNCTION.insert(std::pair<std::string,std::function<double(double)>>("tan",[](double x){return tan(x);}));
        FUNCTION.insert(std::pair<std::string,std::function<double(double)>>("asin",[](double x){return asin(x);}));
        FUNCTION.insert(std::pair<std::string,std::function<double(double)>>("acos",[](double x){return acos(x);}));
        FUNCTION.insert(std::pair<std::string,std::function<double(double)>>("atan",[](double x){return atan(x);}));
        FUNCTION.insert(std::pair<std::string,std::function<double(double)>>("log",[](double x){return log10(x);}));
        FUNCTION.insert(std::pair<std::string,std::function<double(double)>>("ln",[](double x){return log(x);}));
        FUNCTION.insert(std::pair<std::string,std::function<double(double)>>("sqrt",[](double x){return sqrt(x);}));
        FUNCTION.insert(std::pair<std::string,std::function<double(double)>>("sqr",[](double x){return pow(x,2);}));
    }
private:
    void instantializeOpperator(){
        OPPERATOR.insert(std::pair<std::string,std::function<double(double,double)>>("+",[](double x,double y){return x+y;}));
        OPPERATOR.insert(std::pair<std::string,std::function<double(double,double)>>("-",[](double x,double y){return x-y;}));
        OPPERATOR.insert(std::pair<std::string,std::function<double(double,double)>>("*",[](double x,double y){return x*y;}));
        OPPERATOR.insert(std::pair<std::string,std::function<double(double,double)>>("/",[](double x,double y){return x/y;}));
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

public:
    std::function<double(double)> getFunction(const std::basic_string<char>& functionAsString){
        return FUNCTION.at(functionAsString);
    }

public:
    std::function<double(double,double)> getOpperator(const std::string& functionAsString){
        return OPPERATOR.at(functionAsString);
    }
};


#endif //STACK_NORMALEQUATIONIDENTIFIER_H
