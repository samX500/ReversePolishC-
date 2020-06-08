#include <iostream>
#include "Stack.hpp"
#include "List.hpp"
#include "Opperator.h"
#include "Number.h"
#include "Function.h"
#include <stdexcept>
#include <cmath>

const int A_NUMBER = 5;

void givenEmptyStack_whenPopingItem_thenShouldThrow() {
    Stack<int> stack = Stack<int>();

    try {
        stack.pop();
    } catch (const std::invalid_argument &e) {
        std::cout << "givenEmptyStack_whenPopingItem_thenShouldThrow has passed" << std::endl;
        return;
    }
    std::cout << "givenEmptyStack_whenPopingItem_thenShouldThrow HAS FAILED" << std::endl;
}

void givenEmptyStack_whenPuttingItem_thenShouldPopSameItem() {
    Stack<int> stack = Stack<int>();

    stack.put(A_NUMBER);

    if (stack.pop() == A_NUMBER)
        std::cout << "givenEmptyStack_whenPuttingItem_thenShouldAdded has passed" << std::endl;
    else
        std::cout << "givenEmptyStack_whenPuttingItem_thenShouldAdded HAS FAILED" << std::endl;
}

void givenEmptyStack_whenGettingSize_thenShouldBe0() {
    Stack<int> stack = Stack<int>();

    int size = stack.getSize();

    if (size == 0)
        std::cout << "givenEmptyStack_whenGettingSize_thenShouldBe0 has passed" << std::endl;
    else
        std::cout << "givenEmptyStack_whenGettingSize_thenShouldBe0 HAS FAILED" << std::endl;
}

void givenNonEmptyStack_whenGettingSize_thenShouldBeNumberOfItem() {
    Stack<int> stack = Stack<int>();
    int numberOfItem = 5;
    for (int i = 0; i < numberOfItem; i++) {
        stack.put(A_NUMBER);
    }

    int size = stack.getSize();

    if (size == numberOfItem)
        std::cout << "givenNonEmptyStack_whenGettingSize_thenShouldBeNumberOfItem has passed" << std::endl;
    else
        std::cout << "givenNonEmptyStack_whenGettingSize_thenShouldBeNumberOfItem HAS FAILED" << std::endl;
}

void givenNonEmptyStack_whenClearing_thenShouldBeEmpty() {
    Stack<int> stack = Stack<int>();
    int numberOfItem = 5;
    for (int i = 0; i < numberOfItem; i++)
        stack.put(A_NUMBER);

    stack.clear();

    if (stack.getSize() == 0)
        std::cout << "givenNonEmptyStack_whenClearing_thenShouldBeEmpty has passed" << std::endl;
    else
        std::cout << "givenNonEmptyStack_whenClearing_thenShouldBeEmpty HAS FAILED" << std::endl;
}

void givenEmptyList_whenAdding_thenLastItemShouldBeSameItem() {
    List<int> list = List<int>();

    list.add(A_NUMBER);

    if (list.get(-1) == A_NUMBER)
        std::cout << "givenEmptyList_whenAdding_thenLastItemShouldBeSameItem has passed" << std::endl;
    else
        std::cout << "givenEmptyList_whenAdding_thenLastItemShouldBeSameItem HAS FAILED" << std::endl;
}

void givenEmptyList_whenGetting_thenShouldThrow() {
    List<int> list = List<int>();

    try {
        list.get(0);
    } catch (const std::invalid_argument &e) {
        std::cout << "givenEmptyList_whenGetting_thenShouldThrow has passed" << std::endl;
        return;
    }
    std::cout << "givenEmptyList_whenGetting_thenShouldThrow HAS FAILED" << std::endl;
}

void givenNonEmptyList_whenGettingPositiveIndexOutOfBound_thenShouldThrow(){
    List<int> list = List<int>();
    list.add(0);
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);

    try {
        list.get(5);
    } catch (const std::invalid_argument &e) {
        std::cout << "givenNonEmptyList_whenGettingPositiveIndexOutOfBound_thenShouldThrow has passed" << std::endl;
        return;
    }
    std::cout << "givenNonEmptyList_whenGettingPositiveIndexOutOfBound_thenShouldThrow HAS FAILED" << std::endl;
}

void givenNonEmptyList_whenGettingNegativeIndexOutOfBound_thenShouldThrow(){
    List<int> list = List<int>();
    list.add(0);
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);

    try {
        list.get(-6);
    } catch (const std::invalid_argument &e) {
        std::cout << "givenNonEmptyList_whenGettingNegativeIndexOutOfBound_thenShouldThrow has passed" << std::endl;
        return;
    }
    std::cout << "givenNonEmptyList_whenGettingNegativeIndexOutOfBound_thenShouldThrow HAS FAILED" << std::endl;
}

void givenNonEmptyList_whenGettingPositiveIndex_thenShouldGetItemFromStart() {
    List<int> list = List<int>();
    list.add(0);
    list.add(1);
    list.add(2);
    list.add(A_NUMBER);
    list.add(4);

    int itemAtIndex = list.get(3);

    if(itemAtIndex == A_NUMBER)
        std::cout << "givenNonEmptyList_whenGettingPositiveIndex_thenShouldGetItemFromStart has passed" << std::endl;
    else
        std::cout << "givenNonEmptyList_whenGettingPositiveIndex_thenShouldGetItemFromStart HAS FAILED" << std::endl;
}

void givenNonEmptyList_whenGettingNegativeIndex_thenShouldGetItemFromEnd() {
    List<int> list = List<int>();
    list.add(0);
    list.add(A_NUMBER);
    list.add(2);
    list.add(3);
    list.add(4);

    int itemAtIndex = list.get(-4);

    if(itemAtIndex == A_NUMBER)
        std::cout << "givenNonEmptyList_whenGettingNegativeIndex_thenShouldGetItemFromEnd has passed" << std::endl;
    else
        std::cout << "givenNonEmptyList_whenGettingNegativeIndex_thenShouldGetItemFromEnd HAS FAILED" << std::endl;
}

void givenEmptyStack_whenCheckingIsEmpty_thenShouldBeTrue(){
    List<int> list = List<int>();

    bool isEmpty = list.isEmpty();

    if(isEmpty)
        std::cout << "givenEmptyStack_whenCheckingIsEmpty_thenShouldBeTrue has passed" << std::endl;
    else
        std::cout << "givenEmptyStack_whenCheckingIsEmpty_thenShouldBeTrue HAS FAILED" << std::endl;
}

void givenNonEmptyStack_whenCheckingIsEmpty_thenShouldBeFalse(){
    List<int> list = List<int>();
    list.add(0);

    bool isEmpty = list.isEmpty();

    if(!isEmpty)
        std::cout << "givenEmptyStack_whenCheckingIsEmpty_thenShouldBeTrue has passed" << std::endl;
    else
        std::cout << "givenEmptyStack_whenCheckingIsEmpty_thenShouldBeTrue HAS FAILED" << std::endl;
}

void givenEmptyList_whenGettingSize_thenShouldBe0(){
    List<int> list = List<int>();

    int size = list.getSize();

    if(size == 0)
        std::cout << "givenEmptyList_whenGettingSize_thenShouldBe0 has passed" << std::endl;
    else
        std::cout << "givenEmptyList_whenGettingSize_thenShouldBe0 HAS FAILED" << std::endl;
}

void givenNonEmptyList_whenGettingSize_thenShouldBeNumberOfItem(){
    List<int> list = List<int>();
    int numberOfItem = 5;
    for (int i = 0; i < numberOfItem; i++)
        list.add(A_NUMBER);

    int size = list.getSize();

    if(size == numberOfItem)
        std::cout << "givenNonEmptyList_whenGettingSize_thenShouldBeNumberOfItem has passed" << std::endl;
    else
        std::cout << "givenNonEmptyList_whenGettingSize_thenShouldBeNumberOfItem HAS FAILED" << std::endl;
}

void givenEmptyList_whenRemoving_thenShouldThrow(){
    List<int> list = List<int>();

    try {
        list.remove(0);
    } catch (const std::invalid_argument &e) {
        std::cout << "givenEmptyList_whenRemoving_thenShouldThrow has passed" << std::endl;
        return;
    }
    std::cout << "givenEmptyList_whenRemoving_thenShouldThrow HAS FAILED" << std::endl;
}

void givenNonEmptyList_whenRemovingPositiveIndexOutOfBound_thenShouldThrow(){
    List<int> list = List<int>();
    list.add(0);
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);

    try {
        list.remove(5);
    } catch (const std::invalid_argument &e) {
        std::cout << "givenNonEmptyList_whenRemovingPositiveIndexOutOfBound_thenShouldThrow has passed" << std::endl;
        return;
    }
    std::cout << "givenNonEmptyList_whenRemovingPositiveIndexOutOfBound_thenShouldThrow HAS FAILED" << std::endl;
}
void givenNonEmptyList_whenRemovingNegativeIndexOutOfBound_thenShouldThrow(){
    List<int> list = List<int>();
    list.add(0);
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);

    try {
        list.remove(-6);
    } catch (const std::invalid_argument &e) {
        std::cout << "givenNonEmptyList_whenRemovingNegativeIndexOutOfBound_thenShouldThrow has passed" << std::endl;
        return;
    }
    std::cout << "givenNonEmptyList_whenRemovingNegativeIndexOutOfBound_thenShouldThrow HAS FAILED" << std::endl;
}
void givenNonEmptyList_whenRemovingPositiveIndex_thenShouldGetItemFromStart(){
    List<int> list = List<int>();
    list.add(0);
    list.add(1);
    list.add(2);
    list.add(A_NUMBER);
    list.add(4);

    int itemAtIndex = list.remove(3);

    if(itemAtIndex == A_NUMBER&&list.getSize()==4)
        std::cout << "givenNonEmptyList_whenRemovingPositiveIndex_thenShouldGetItemFromStart has passed" << std::endl;
    else
        std::cout << "givenNonEmptyList_whenRemovingPositiveIndex_thenShouldGetItemFromStart HAS FAILED" << std::endl;
}
void givenNonEmptyList_whenRemovingNegativeIndex_thenShouldGetItemFromEnd(){
    List<int> list = List<int>();
    list.add(0);
    list.add(1);
    list.add(A_NUMBER);
    list.add(3);
    list.add(4);

    int itemAtIndex = list.remove(-3);

    if(itemAtIndex == A_NUMBER&&list.getSize()==4)
        std::cout << "givenNonEmptyList_whenRemovingNegativeIndex_thenShouldGetItemFromEnd has passed" << std::endl;
    else
        std::cout << "givenNonEmptyList_whenRemovingNegativeIndex_thenShouldGetItemFromEnd HAS FAILED" << std::endl;
}

void givenANumber_whenGettingValue_thenShouldGetSameNumber(){
    ArithmeticExpression* ANumber = new Number(A_NUMBER);

    double number = ANumber->getValue();

    if(number == A_NUMBER)
        std::cout << "givenANumber_whenGettingValue_thenShouldGetSameNumber has passed" << std::endl;
    else
        std::cout << "givenANumber_whenGettingValue_thenShouldGetSameNumber HAS FAILED" << std::endl;
}

void givenAFunctionWithNumberParameter_whenGettingValue_thenShouldEvaluateNumberWithGivenFunction(){
    double CONST_NUMBER = 0;
    ArithmeticExpression* ANumber = new Number(CONST_NUMBER);
    ArithmeticExpression* cosFunction = new Function([](double inside){return cos(inside);},ANumber);

    double number = cosFunction->getValue();

    if(number == cos(CONST_NUMBER))
        std::cout << "givenAFunctionWithNumberParameter_whenGettingValue_thenShouldEvaluateNumberWithGivenFunction has passed" << std::endl;
    else
        std::cout << "givenAFunctionWithNumberParameter_whenGettingValue_thenShouldEvaluateNumberWithGivenFunction HAS FAILED" << std::endl;
}

void givenAFunctionWithFunctionParameter_whenGettingValue_thenShouldRecursivelyEvaluateAllGivenFunction(){
    double CONST_NUMBER = 0;
    ArithmeticExpression* ANumber = new Number(CONST_NUMBER);
    ArithmeticExpression* cosFunction = new Function([](double inside){return cos(inside);},ANumber);
    ArithmeticExpression* logFunction = new Function([](double inside){return log(inside);},cosFunction);

    double number = logFunction->getValue();

    if(number == log(cos(CONST_NUMBER)))
        std::cout << "givenAFunctionWithNumberParameter_whenGettingValue_thenShouldEvaluateNumberWithGivenFunction has passed" << std::endl;
    else
        std::cout << "givenAFunctionWithNumberParameter_whenGettingValue_thenShouldEvaluateNumberWithGivenFunction HAS FAILED" << std::endl;
}

void givenAnOpperatorWithNumberParameter_whenGettingValue_thenShouldApplyGivenOpperatorToNumbers(){
    ArithmeticExpression* firstNumber = new Number(A_NUMBER);
    ArithmeticExpression* secondNumber = new Number(A_NUMBER);
    ArithmeticExpression* addOpperator = new Opperator([](double lhs,double rhs){return lhs + rhs;},firstNumber,secondNumber);

    double number = addOpperator->getValue();

    if(number == A_NUMBER+A_NUMBER)
        std::cout << "givenAnOpperatorWithNumberParameter_whenGettingValue_thenShouldApplyGivenOpperatorToNumbers has passed" << std::endl;
    else
        std::cout << "givenAnOpperatorWithNumberParameter_whenGettingValue_thenShouldApplyGivenOpperatorToNumbers HAS FAILED" << std::endl;

}

void givenAnOpperatorWithOpperatorParameter_whenGettingValue_thenShouldRecursivalyApplyAllGivenOpperatorToNumbers(){
    ArithmeticExpression* number5 = new Number(5);
    ArithmeticExpression* number3 = new Number(3);
    ArithmeticExpression* minusOpperator = new Opperator([](int lhs,int rhs){return lhs - rhs;},number5,number3);
    ArithmeticExpression* addOpperator = new Opperator([](int lhs,int rhs){return lhs + rhs;},number5,number3);
    ArithmeticExpression* timesOpperator = new Opperator([](int lhs,int rhs){return lhs * rhs;},minusOpperator,addOpperator);

    double number = timesOpperator->getValue();

    if(number == (5-3)*(5+3))
        std::cout << "givenAnOpperatorWithOpperatorParameter_whenGettingValue_thenShouldRecursivalyApplyAllGivenOpperatorToNumbers has passed" << std::endl;
    else
        std::cout << "givenAnOpperatorWithOpperatorParameter_whenGettingValue_thenShouldRecursivalyApplyAllGivenOpperatorToNumbers HAS FAILED" << std::endl;

}
//Lambda exemple: [](int lhs,int rhs){return lhs + rhs;}



void runAllTest() {
    std::cout<<"Stack Test"<<std::endl;
    givenEmptyStack_whenPopingItem_thenShouldThrow();
    givenEmptyStack_whenPuttingItem_thenShouldPopSameItem();
    givenEmptyStack_whenGettingSize_thenShouldBe0();
    givenNonEmptyStack_whenGettingSize_thenShouldBeNumberOfItem();
    givenNonEmptyStack_whenClearing_thenShouldBeEmpty();

    std::cout<<"List Test"<<std::endl;
    givenEmptyList_whenAdding_thenLastItemShouldBeSameItem();
    givenEmptyList_whenGetting_thenShouldThrow();
    givenNonEmptyList_whenGettingPositiveIndexOutOfBound_thenShouldThrow();
    givenNonEmptyList_whenGettingNegativeIndexOutOfBound_thenShouldThrow();
    givenNonEmptyList_whenGettingPositiveIndex_thenShouldGetItemFromStart();
    givenNonEmptyList_whenGettingNegativeIndex_thenShouldGetItemFromEnd();
    givenEmptyStack_whenCheckingIsEmpty_thenShouldBeTrue();
    givenNonEmptyStack_whenCheckingIsEmpty_thenShouldBeFalse();
    givenEmptyList_whenGettingSize_thenShouldBe0();
    givenNonEmptyList_whenGettingSize_thenShouldBeNumberOfItem();
    givenEmptyList_whenRemoving_thenShouldThrow();
    givenNonEmptyList_whenRemovingPositiveIndexOutOfBound_thenShouldThrow();
    givenNonEmptyList_whenRemovingNegativeIndexOutOfBound_thenShouldThrow();
    givenNonEmptyList_whenRemovingPositiveIndex_thenShouldGetItemFromStart();
    givenNonEmptyList_whenRemovingNegativeIndex_thenShouldGetItemFromEnd();
    givenNonEmptyList_whenRemovingNegativeIndex_thenShouldGetItemFromEnd();

    std::cout<<"ArithmeticExpression Test"<<std::endl;
    givenANumber_whenGettingValue_thenShouldGetSameNumber();
    givenAFunctionWithNumberParameter_whenGettingValue_thenShouldEvaluateNumberWithGivenFunction();
    givenAFunctionWithFunctionParameter_whenGettingValue_thenShouldRecursivelyEvaluateAllGivenFunction();
    givenAnOpperatorWithNumberParameter_whenGettingValue_thenShouldApplyGivenOpperatorToNumbers();
    givenAnOpperatorWithOpperatorParameter_whenGettingValue_thenShouldRecursivalyApplyAllGivenOpperatorToNumbers();
}


int main() {
    runAllTest();

    return 0;
}