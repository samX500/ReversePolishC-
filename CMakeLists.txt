cmake_minimum_required(VERSION 3.16)
project(stack)

set(CMAKE_CXX_STANDARD 14)

add_executable(stack main.cpp dataStructure/Stack.cpp dataStructure/List.cpp dataStructure/List.hpp ReversePolishCalculator.cpp ReversePolishCalculator.h arithmeticExpression/ArithmeticExpression.cpp arithmeticExpression/ArithmeticExpression.h arithmeticExpression/Function.cpp arithmeticExpression/Function.h arithmeticExpression/Opperator.cpp arithmeticExpression/Opperator.h arithmeticExpression/Number.cpp arithmeticExpression/Number.h stringParsing/StringToEquation.cpp stringParsing/StringToEquation.h)