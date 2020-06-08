cmake_minimum_required(VERSION 3.16)
project(stack)

set(CMAKE_CXX_STANDARD 14)

add_executable(stack main.cpp Stack.cpp List.cpp List.hpp ReversePolishCalculator.cpp ReversePolishCalculator.h ArithmeticExpression.cpp ArithmeticExpression.h Function.cpp Function.h Opperator.cpp Opperator.h Number.cpp Number.h)