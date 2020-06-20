#include <iostream>
#include "../dataStructure/Stack.hpp"
#include "../dataStructure/List.hpp"
#include "../arithmeticExpression/Opperator.h"
#include "../arithmeticExpression/Number.h"
#include "../arithmeticExpression/Function.h"
#include "../stringParsing/NormalEquationFormat/NormalEquationFormat.h"
#include "../stringParsing/EquationParserFactory.h"
#include "../stringParsing/NormalEquationFormat/EquationNormalFormat.h"
#include <stdexcept>
#include <cmath>

const int A_NUMBER = 5;

//STACK TEST

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

//LIST TEST

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

void givenNonEmptyList_whenGettingPositiveIndexOutOfBound_thenShouldThrow() {
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

void givenNonEmptyList_whenGettingNegativeIndexOutOfBound_thenShouldThrow() {
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

    if (itemAtIndex == A_NUMBER)
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

    if (itemAtIndex == A_NUMBER)
        std::cout << "givenNonEmptyList_whenGettingNegativeIndex_thenShouldGetItemFromEnd has passed" << std::endl;
    else
        std::cout << "givenNonEmptyList_whenGettingNegativeIndex_thenShouldGetItemFromEnd HAS FAILED" << std::endl;
}

void givenEmptyStack_whenCheckingIsEmpty_thenShouldBeTrue() {
    List<int> list = List<int>();

    bool isEmpty = list.isEmpty();

    if (isEmpty)
        std::cout << "givenEmptyStack_whenCheckingIsEmpty_thenShouldBeTrue has passed" << std::endl;
    else
        std::cout << "givenEmptyStack_whenCheckingIsEmpty_thenShouldBeTrue HAS FAILED" << std::endl;
}

void givenNonEmptyStack_whenCheckingIsEmpty_thenShouldBeFalse() {
    List<int> list = List<int>();
    list.add(0);

    bool isEmpty = list.isEmpty();

    if (!isEmpty)
        std::cout << "givenEmptyStack_whenCheckingIsEmpty_thenShouldBeTrue has passed" << std::endl;
    else
        std::cout << "givenEmptyStack_whenCheckingIsEmpty_thenShouldBeTrue HAS FAILED" << std::endl;
}

void givenEmptyList_whenGettingSize_thenShouldBe0() {
    List<int> list = List<int>();

    int size = list.getSize();

    if (size == 0)
        std::cout << "givenEmptyList_whenGettingSize_thenShouldBe0 has passed" << std::endl;
    else
        std::cout << "givenEmptyList_whenGettingSize_thenShouldBe0 HAS FAILED" << std::endl;
}

void givenNonEmptyList_whenGettingSize_thenShouldBeNumberOfItem() {
    List<int> list = List<int>();
    int numberOfItem = 5;
    for (int i = 0; i < numberOfItem; i++)
        list.add(A_NUMBER);

    int size = list.getSize();

    if (size == numberOfItem)
        std::cout << "givenNonEmptyList_whenGettingSize_thenShouldBeNumberOfItem has passed" << std::endl;
    else
        std::cout << "givenNonEmptyList_whenGettingSize_thenShouldBeNumberOfItem HAS FAILED" << std::endl;
}

void givenEmptyList_whenRemoving_thenShouldThrow() {
    List<int> list = List<int>();

    try {
        list.remove(0);
    } catch (const std::invalid_argument &e) {
        std::cout << "givenEmptyList_whenRemoving_thenShouldThrow has passed" << std::endl;
        return;
    }
    std::cout << "givenEmptyList_whenRemoving_thenShouldThrow HAS FAILED" << std::endl;
}

void givenNonEmptyList_whenRemovingPositiveIndexOutOfBound_thenShouldThrow() {
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

void givenNonEmptyList_whenRemovingNegativeIndexOutOfBound_thenShouldThrow() {
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

void givenNonEmptyList_whenRemovingPositiveIndex_thenShouldGetItemFromStart() {
    List<int> list = List<int>();
    list.add(0);
    list.add(1);
    list.add(2);
    list.add(A_NUMBER);
    list.add(4);

    int itemAtIndex = list.remove(3);

    if (itemAtIndex == A_NUMBER && list.getSize() == 4)
        std::cout << "givenNonEmptyList_whenRemovingPositiveIndex_thenShouldGetItemFromStart has passed" << std::endl;
    else
        std::cout << "givenNonEmptyList_whenRemovingPositiveIndex_thenShouldGetItemFromStart HAS FAILED" << std::endl;
}

void givenNonEmptyList_whenRemovingNegativeIndex_thenShouldGetItemFromEnd() {
    List<int> list = List<int>();
    list.add(0);
    list.add(1);
    list.add(A_NUMBER);
    list.add(3);
    list.add(4);

    int itemAtIndex = list.remove(-3);

    if (itemAtIndex == A_NUMBER && list.getSize() == 4)
        std::cout << "givenNonEmptyList_whenRemovingNegativeIndex_thenShouldGetItemFromEnd has passed" << std::endl;
    else
        std::cout << "givenNonEmptyList_whenRemovingNegativeIndex_thenShouldGetItemFromEnd HAS FAILED" << std::endl;
}

void givenListContainingAnItem_whenCheckingIfListContainsAnItem_thenShouldBeTrue() {
    List<int> list = List<int>();
    int AN_ITEM = A_NUMBER;
    list.add(0);
    list.add(1);
    list.add(3);
    list.add(4);
    list.add(AN_ITEM);

    bool doesContain = list.contains(A_NUMBER);

    if (doesContain)
        std::cout << "givenListContainingAnItem_whenCheckingIfListContainsAnItem_thenShouldBeTrue has passed"
                  << std::endl;
    else
        std::cout << "givenListContainingAnItem_whenCheckingIfListContainsAnItem_thenShouldBeTrue HAS FAILED"
                  << std::endl;
}

void givenListNotContainingAnItem_whenCheckingIfListContainsAnItem_thenShouldBeTrue() {
    List<int> list = List<int>();
    list.add(0);
    list.add(1);
    list.add(3);
    list.add(4);

    bool doesContain = list.contains(A_NUMBER);

    if (!doesContain)
        std::cout << "givenListContainingAnItem_whenCheckingIfListContainsAnItem_thenShouldBeTrue has passed"
                  << std::endl;
    else
        std::cout << "givenListContainingAnItem_whenCheckingIfListContainsAnItem_thenShouldBeTrue HAS FAILED"
                  << std::endl;
}
//ARITHEMETIC EXPPRESSION TEST

void givenANumber_whenGettingValue_thenShouldGetSameNumber() {
    ArithmeticExpression *ANumber = new Number(A_NUMBER);

    double number = ANumber->getValue();

    if (number == A_NUMBER)
        std::cout << "givenANumber_whenGettingValue_thenShouldGetSameNumber has passed" << std::endl;
    else
        std::cout << "givenANumber_whenGettingValue_thenShouldGetSameNumber HAS FAILED" << std::endl;
}

void givenAFunctionWithNumberParameter_whenGettingValue_thenShouldEvaluateNumberWithGivenFunction() {
    double CONST_NUMBER = 0;
    ArithmeticExpression *ANumber = new Number(CONST_NUMBER);
    ArithmeticExpression *cosFunction = new Function([](double inside) { return cos(inside); }, ANumber);

    double number = cosFunction->getValue();

    if (number == cos(CONST_NUMBER))
        std::cout
                << "givenAFunctionWithNumberParameter_whenGettingValue_thenShouldEvaluateNumberWithGivenFunction has passed"
                << std::endl;
    else
        std::cout
                << "givenAFunctionWithNumberParameter_whenGettingValue_thenShouldEvaluateNumberWithGivenFunction HAS FAILED"
                << std::endl;
}

void givenAFunctionWithFunctionParameter_whenGettingValue_thenShouldRecursivelyEvaluateAllGivenFunction() {
    double CONST_NUMBER = 0;
    ArithmeticExpression *ANumber = new Number(CONST_NUMBER);
    ArithmeticExpression *cosFunction = new Function([](double inside) { return cos(inside); }, ANumber);
    ArithmeticExpression *logFunction = new Function([](double inside) { return log(inside); }, cosFunction);

    double number = logFunction->getValue();

    if (number == log(cos(CONST_NUMBER)))
        std::cout
                << "givenAFunctionWithNumberParameter_whenGettingValue_thenShouldEvaluateNumberWithGivenFunction has passed"
                << std::endl;
    else
        std::cout
                << "givenAFunctionWithNumberParameter_whenGettingValue_thenShouldEvaluateNumberWithGivenFunction HAS FAILED"
                << std::endl;
}

void givenAnOpperatorWithNumberParameter_whenGettingValue_thenShouldApplyGivenOpperatorToNumbers() {
    ArithmeticExpression *firstNumber = new Number(A_NUMBER);
    ArithmeticExpression *secondNumber = new Number(A_NUMBER);
    ArithmeticExpression *addOpperator = new Opperator([](double lhs, double rhs) { return lhs + rhs; }, firstNumber,
                                                       secondNumber);

    double number = addOpperator->getValue();

    if (number == A_NUMBER + A_NUMBER)
        std::cout
                << "givenAnOpperatorWithNumberParameter_whenGettingValue_thenShouldApplyGivenOpperatorToNumbers has passed"
                << std::endl;
    else
        std::cout
                << "givenAnOpperatorWithNumberParameter_whenGettingValue_thenShouldApplyGivenOpperatorToNumbers HAS FAILED"
                << std::endl;

}

void givenAnOpperatorWithOpperatorParameter_whenGettingValue_thenShouldRecursivalyApplyAllGivenOpperatorToNumbers() {
    ArithmeticExpression *number5 = new Number(5);
    ArithmeticExpression *number3 = new Number(3);
    ArithmeticExpression *minusOpperator = new Opperator([](int lhs, int rhs) { return lhs - rhs; }, number5, number3);
    ArithmeticExpression *addOpperator = new Opperator([](int lhs, int rhs) { return lhs + rhs; }, number5, number3);
    ArithmeticExpression *timesOpperator = new Opperator([](int lhs, int rhs) { return lhs * rhs; }, minusOpperator,
                                                         addOpperator);

    double number = timesOpperator->getValue();

    if (number == (5 - 3) * (5 + 3))
        std::cout
                << "givenAnOpperatorWithOpperatorParameter_whenGettingValue_thenShouldRecursivalyApplyAllGivenOpperatorToNumbers has passed"
                << std::endl;
    else
        std::cout
                << "givenAnOpperatorWithOpperatorParameter_whenGettingValue_thenShouldRecursivalyApplyAllGivenOpperatorToNumbers HAS FAILED"
                << std::endl;

}

//PARSING TEST

void givenOneAddition_whenGettingLowestPriorityOpperator_thenShouldGetIndexOfOpperator() {
    std::string equationString = "3+5";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    int indexOfOpperator = equation.getLowestPriorityOpperatorIndex();

    if (indexOfOpperator == 1)
        std::cout << "givenOneAddition_whenGettingLowestPriorityOpperator_thenShouldGetIndexOfOpperator has passed"
                  << std::endl;
    else
        std::cout << "givenOneAddition_whenGettingLowestPriorityOpperator_thenShouldGetIndexOfOpperator HAS FAILED"
                  << std::endl;

}

void givenMultipleAddition_whenGettingLowestPriorityOpperator_thenShouldGetIndexOfFirstOpperator() {
    std::string equationString = "3+5+8";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    int indexOfOpperator = equation.getLowestPriorityOpperatorIndex();

    if (indexOfOpperator == 1)
        std::cout
                << "givenMultipleAddition_whenGettingLowestPriorityOpperator_thenShouldGetIndexOfFirstOpperator has passed"
                << std::endl;
    else
        std::cout
                << "givenMultipleAddition_whenGettingLowestPriorityOpperator_thenShouldGetIndexOfFirstOpperator HAS FAILED"
                << std::endl;

}

void
givenOpperatorOfDifferentPriority_whenGettingLowestPriorityOpperator_thenShouldGetIndexOfLowestPriorityOpperator() {
    std::string equationString = "3*5+8";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    int indexOfOpperator = equation.getLowestPriorityOpperatorIndex();

    if (indexOfOpperator == 3)
        std::cout
                << "givenOpperatorOfDifferentPriority_whenGettingLowestPriorityOpperator_thenShouldGetIndexOfLowestPriorityOpperator has passed"
                << std::endl;
    else
        std::cout
                << "givenOpperatorOfDifferentPriority_whenGettingLowestPriorityOpperator_thenShouldGetIndexOfLowestPriorityOpperator HAS FAILED"
                << std::endl;

}

void givenEquationWithFunction_whenGettingLowestPriorityOpperator_thenShouldGetIndexOfOpperatorOutsideOfFunction() {
    std::string equationString = "sin(5+3)*6";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    int indexOfOpperator = equation.getLowestPriorityOpperatorIndex();

    if (indexOfOpperator == 8)
        std::cout
                << "givenEquationWithFunction_whenGettingLowestPriorityOpperator_thenShouldGetIndexOfOpperatorOutsideOfFunction has passed"
                << std::endl;
    else
        std::cout
                << "givenEquationWithFunction_whenGettingLowestPriorityOpperator_thenShouldGetIndexOfOpperatorOutsideOfFunction HAS FAILED"
                << std::endl;

}

void givenEquationWithNoOpperatorOutsideFunction_whenGettingLowestPriorityOpperator_thenShouldGetNegative1() {
    std::string equationString = "(sin(5+3)*6)";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    int indexOfOpperator = equation.getLowestPriorityOpperatorIndex();

    if (indexOfOpperator == -1)
        std::cout
                << "givenEquationWithFunction_whenGettingLowestPriorityOpperator_thenShouldGetIndexOfOpperatorOutsideOfFunction has passed"
                << std::endl;
    else
        std::cout
                << "givenEquationWithFunction_whenGettingLowestPriorityOpperator_thenShouldGetIndexOfOpperatorOutsideOfFunction HAS FAILED"
                << std::endl;

}

void givenNoOpperator_whenGettingLowestPriorityOpperator_thenShouldGetNegative1() {
    std::string equationString = "sin(50)3";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    int indexOfOpperator = equation.getLowestPriorityOpperatorIndex();

    if (indexOfOpperator == -1)
        std::cout << "givenNoOpperator_whenGettingLowestPriorityOpperator_thenShouldGetNegative1 has passed"
                  << std::endl;
    else
        std::cout << "givenNoOpperator_whenGettingLowestPriorityOpperator_thenShouldGetNegative1 HAS FAILED"
                  << std::endl;

}

void givenAnOpperator_whenCheckingHasLowPriorityOpperator_thenShouldBeTrue() {
    std::string equationString = "3+5";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    bool hasLowPriorityOpperator = equation.hasLowPriorityOpperator();

    if (hasLowPriorityOpperator)
        std::cout << "givenAnOpperator_whenCheckingHasLowPriorityOpperator_thenShouldBeTrue has passed" << std::endl;
    else
        std::cout << "givenAnOpperator_whenCheckingHasLowPriorityOpperator_thenShouldBeTrue HAS FAILED" << std::endl;

}

void givenManyOpperator_whenCheckingHasLowPriorityOpperator_thenShouldBeTrue() {
    std::string equationString = "3+5*8/3-5";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    bool hasLowPriorityOpperator = equation.hasLowPriorityOpperator();

    if (hasLowPriorityOpperator)
        std::cout << "givenManyOpperator_whenCheckingHasLowPriorityOpperator_thenShouldBeTrue has passed" << std::endl;
    else
        std::cout << "givenManyOpperator_whenCheckingHasLowPriorityOpperator_thenShouldBeTrue HAS FAILED" << std::endl;

}

void givenAnOpperatorInFunction_whenCheckingHasLowPriorityOpperator_thenShouldBeFalse() {
    std::string equationString = "sin(3+5)";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    bool hasLowPriorityOpperator = equation.hasLowPriorityOpperator();

    if (!hasLowPriorityOpperator)
        std::cout << "givenAnOpperatorInFunction_whenCheckingHasLowPriorityOpperator_thenShouldBeFalse has passed" << std::endl;
    else
        std::cout << "givenAnOpperatorInFunction_whenCheckingHasLowPriorityOpperator_thenShouldBeFalse HAS FAILED" << std::endl;

}

void givenNoOpperator_whenCheckingHasLowPriorityOpperator_thenShouldBeFalse() {
    std::string equationString = "90";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    bool hasLowPriorityOpperator = equation.hasLowPriorityOpperator();

    if (!hasLowPriorityOpperator)
        std::cout << "givenNoOpperator_whenCheckingHasLowPriorityOpperator_thenShouldBeFalse has passed" << std::endl;
    else
        std::cout << "givenNoOpperator_whenCheckingHasLowPriorityOpperator_thenShouldBeFalse HAS FAILED" << std::endl;
}

void givenAnOpperator_whenCuttingOnLowestPriorityOpperator_thenShouldGetBothSideOfOpperator(){
    std::string equationString = "3+5";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    TwoSidedEquationAsString bothSides = equation.cutOnLowestPriorityOpperator();

    if (bothSides.getLeftHandSide()=="3"&&bothSides.getRightHandSide()=="5")
        std::cout << "givenAnOpperator_whenCuttingOnLowestPriorityOpperator_thenShouldGetBothSideOfOpperator has passed" << std::endl;
    else
        std::cout << "givenAnOpperator_whenCuttingOnLowestPriorityOpperator_thenShouldGetBothSideOfOpperator HAS FAILED" << std::endl;
}

void givenManyOpperator_whenCuttingOnLowestPriorityOpperator_thenShouldGetBothSideOfOpperator(){
    std::string equationString = "sin(90*180)+5*log(2-1)";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    TwoSidedEquationAsString bothSides = equation.cutOnLowestPriorityOpperator();

    if (bothSides.getLeftHandSide()=="sin(90*180)"&&bothSides.getRightHandSide()=="5*log(2-1)")
        std::cout << "givenAnOpperator_whenCuttingOnLowestPriorityOpperator_thenShouldGetBothSideOfOpperator has passed" << std::endl;
    else
        std::cout << "givenAnOpperator_whenCuttingOnLowestPriorityOpperator_thenShouldGetBothSideOfOpperator HAS FAILED" << std::endl;

}

void givenAnOpperatorInFunction_whenCuttingOnLowestPriorityOpperator_thenShouldRaise(){
    std::string equationString = "sin(90*180)";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    try {
        equation.cutOnLowestPriorityOpperator();
    } catch (const std::invalid_argument &e) {
        std::cout << "givenAnOpperatorInFunction_whenCuttingOnLowestPriorityOpperator_thenShouldRaise has passed" << std::endl;
        return;
    }
    std::cout << "givenAnOpperator_whenCuttingOnLowestPriorityOpperator_thenShouldGetBothSideOfOpperator HAS FAILED" << std::endl;
}

void givenNoOpperator_whenCuttingOnLowestPriorityOpperator_thenShouldRaise(){
    std::string equationString = "sin(90)";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    try {
        equation.cutOnLowestPriorityOpperator();
    } catch (const std::invalid_argument &e) {
        std::cout << "givenNoOpperator_whenCuttingOnLowestPriorityOpperator_thenShouldRaise has passed" << std::endl;
        return;
    }
    std::cout << "givenNoOpperator_whenCuttingOnLowestPriorityOpperator_thenShouldRaise HAS FAILED" << std::endl;
}

void givenAnOpperator_whenGettingLowestPriorityOpperator_thenShouldGetThatOpperator(){
    std::string equationString = "3+5";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    std::string lowestPriorityOpperator = equation.getLowestPriorityOpperator();

    if (lowestPriorityOpperator=="+")
        std::cout << "givenAnOpperator_whenGettingLowestPriorityOpperator_thenShouldGetThatOpperator has passed" << std::endl;
    else
        std::cout << "givenAnOpperator_whenGettingLowestPriorityOpperator_thenShouldGetThatOpperator HAS FAILED" << std::endl;

}

void givenManyOpperator_whenGettingLowestPriorityOpperator_thenShouldGetLowestPriorityOpperator(){
    std::string equationString = "5-3*6+5/5";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    std::string lowestPriorityOpperator = equation.getLowestPriorityOpperator();

    if (lowestPriorityOpperator=="-")
        std::cout << "givenManyOpperator_whenGettingLowestPriorityOpperator_thenShouldGetLowestPriorityOpperator has passed" << std::endl;
    else
        std::cout << "givenManyOpperator_whenGettingLowestPriorityOpperator_thenShouldGetLowestPriorityOpperator HAS FAILED" << std::endl;

}

void givenAnOpperatorInFunction_whenGettingLowestPriorityOpperator_thenShouldGetEmptyString(){
    std::string equationString = "sin(5+5)";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    std::string lowestPriorityOpperator = equation.getLowestPriorityOpperator();

    if (lowestPriorityOpperator.empty())
        std::cout << "givenAnOpperatorInFunction_whenGettingLowestPriorityOpperator_thenShouldGetEmptyString has passed" << std::endl;
    else
        std::cout << "givenAnOpperatorInFunction_whenGettingLowestPriorityOpperator_thenShouldGetEmptyString HAS FAILED" << std::endl;

}

void givenNoOpperator_whenGettingLowestPriorityOpperator_thenShouldGetEmptyString(){
    std::string equationString = "sin(55)";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    std::string lowestPriorityOpperator = equation.getLowestPriorityOpperator();

    if (lowestPriorityOpperator.empty())
        std::cout << "givenNoOpperator_whenGettingLowestPriorityOpperator_thenShouldGetEmptyString has passed" << std::endl;
    else
        std::cout << "givenNoOpperator_whenGettingLowestPriorityOpperator_thenShouldGetEmptyString HAS FAILED" << std::endl;

}

void givenAnEquationFunction_whenCheckingIsAFunction_thenShouldBeTrue(){
    std::string equationString = "sin(90)";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    bool isAFunction = equation.isAFunction();

    if (isAFunction)
        std::cout << "givenAnEquationFunction_whenCheckingIsAFunction_thenShouldBeTrue has passed" << std::endl;
    else
        std::cout << "givenAnEquationFunction_whenCheckingIsAFunction_thenShouldBeTrue HAS FAILED" << std::endl;

}

void givenNotAnEquationFunction_whenCheckingIsAFunction_thenShouldBeFalse(){
    std::string equationString = "sin(90)+5";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    bool isAFunction = equation.isAFunction();

    if (!isAFunction)
        std::cout << "givenNotAnEquationFunction_whenCheckingIsAFunction_thenShouldBeFalse has passed" << std::endl;
    else
        std::cout << "givenNotAnEquationFunction_whenCheckingIsAFunction_thenShouldBeFalse HAS FAILED" << std::endl;

}

void givenASinFunction_whenGettingFunction_thenShouldGetSin(){
    std::string equationString = "sin(90)";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    std::string function = equation.getFunction();

    if (function=="sin")
        std::cout << "givenASinFunction_whenGettingFunction_thenShouldGetSin has passed" << std::endl;
    else
        std::cout << "givenASinFunction_whenGettingFunction_thenShouldGetSin HAS FAILED" << std::endl;

}

void givenParentheseFunction_whenGettingFunction_thenSouldGetEmptyString(){
    std::string equationString = "(90)";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    std::string function = equation.getFunction();

    if (function=="")
        std::cout << "givenParentheseFunction_whenGettingFunction_thenSouldGetEmptyString has passed" << std::endl;
    else
        std::cout << "givenParentheseFunction_whenGettingFunction_thenSouldGetEmptyString HAS FAILED" << std::endl;

}

void givenManyFunction_whenGettingFunction_thenShouldRaise(){
    std::string equationString = "sin(90)+log(1)";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    try{
        std::string function = equation.getFunction();
    }
    catch(std::invalid_argument &e){
        std::cout << "givenManyFunction_whenGettingFunction_thenShouldRaise has passed" << std::endl;
        return;
    }

    std::cout << "givenManyFunction_whenGettingFunction_thenShouldRaise HAS FAILED" << std::endl;
}

void givenOneFunction_whenGettingFunctionInside_thenShouldGetSubstringBetweenBracket(){
    std::string equationString = "sin(90+90)";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    std::string functionInside = equation.getFunctionInside();
    std::cout << functionInside<<std::endl;
    if (functionInside=="90+90")
        std::cout << "givenOneFunction_whenGettingFunctionInside_thenShouldGetSubstringBetweenBracket has passed" << std::endl;
    else
        std::cout << "givenOneFunction_whenGettingFunctionInside_thenShouldGetSubstringBetweenBracket HAS FAILED" << std::endl;
}

void givenManyFunction_whenGettingFunctionInside_thenShouldRaise(){
    std::string equationString = "sin(90)+log(1)";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    try{
        std::string functionInside = equation.getFunctionInside();
    }
    catch(std::invalid_argument &e){
        std::cout << "givenManyFunction_whenGettingFunctionInside_thenShouldRaise has passed" << std::endl;
        return;
    }

    std::cout << "givenManyFunction_whenGettingFunctionInside_thenShouldRaise HAS FAILED" << std::endl;
}

void givenNotAFunction_whenGettingFunctionInside_thenShouldRaise(){
    std::string equationString = "5+5";
    EquationNormalFormat equation = EquationNormalFormat(equationString);

    try{
        std::string functionInside = equation.getFunctionInside();
    }
    catch(std::invalid_argument &e){
        std::cout << "givenNotAFunction_whenGettingFunctionInside_thenShouldRaise has passed" << std::endl;
        return;
    }

    std::cout << "givenNotAFunction_whenGettingFunctionInside_thenShouldRaise HAS FAILED" << std::endl;
}

void runAllTest() {
    std::cout << "\nStack Test" << std::endl;
    givenEmptyStack_whenPopingItem_thenShouldThrow();
    givenEmptyStack_whenPuttingItem_thenShouldPopSameItem();
    givenEmptyStack_whenGettingSize_thenShouldBe0();
    givenNonEmptyStack_whenGettingSize_thenShouldBeNumberOfItem();
    givenNonEmptyStack_whenClearing_thenShouldBeEmpty();

    std::cout << "\nList Test" << std::endl;
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
    givenListContainingAnItem_whenCheckingIfListContainsAnItem_thenShouldBeTrue();
    givenListNotContainingAnItem_whenCheckingIfListContainsAnItem_thenShouldBeTrue();

    std::cout << "\nArithmeticExpression Test" << std::endl;
    givenANumber_whenGettingValue_thenShouldGetSameNumber();
    givenAFunctionWithNumberParameter_whenGettingValue_thenShouldEvaluateNumberWithGivenFunction();
    givenAFunctionWithFunctionParameter_whenGettingValue_thenShouldRecursivelyEvaluateAllGivenFunction();
    givenAnOpperatorWithNumberParameter_whenGettingValue_thenShouldApplyGivenOpperatorToNumbers();
    givenAnOpperatorWithOpperatorParameter_whenGettingValue_thenShouldRecursivalyApplyAllGivenOpperatorToNumbers();

    std::cout << "\nNormalEquationParser Test" << std::endl;
    givenOneAddition_whenGettingLowestPriorityOpperator_thenShouldGetIndexOfOpperator();
    givenMultipleAddition_whenGettingLowestPriorityOpperator_thenShouldGetIndexOfFirstOpperator();
    givenOpperatorOfDifferentPriority_whenGettingLowestPriorityOpperator_thenShouldGetIndexOfLowestPriorityOpperator();
    givenEquationWithFunction_whenGettingLowestPriorityOpperator_thenShouldGetIndexOfOpperatorOutsideOfFunction();
    givenEquationWithNoOpperatorOutsideFunction_whenGettingLowestPriorityOpperator_thenShouldGetNegative1();
    givenNoOpperator_whenGettingLowestPriorityOpperator_thenShouldGetNegative1();
    givenAnOpperatorInFunction_whenCheckingHasLowPriorityOpperator_thenShouldBeFalse();
    givenManyOpperator_whenCheckingHasLowPriorityOpperator_thenShouldBeTrue();
    givenAnOpperatorInFunction_whenCheckingHasLowPriorityOpperator_thenShouldBeFalse();
    givenNoOpperator_whenCheckingHasLowPriorityOpperator_thenShouldBeFalse();
    givenAnOpperator_whenCuttingOnLowestPriorityOpperator_thenShouldGetBothSideOfOpperator();
    givenManyOpperator_whenCuttingOnLowestPriorityOpperator_thenShouldGetBothSideOfOpperator();
    givenAnOpperatorInFunction_whenCuttingOnLowestPriorityOpperator_thenShouldRaise();
    givenNoOpperator_whenCuttingOnLowestPriorityOpperator_thenShouldRaise();
    givenAnOpperator_whenGettingLowestPriorityOpperator_thenShouldGetThatOpperator();
    givenManyOpperator_whenGettingLowestPriorityOpperator_thenShouldGetLowestPriorityOpperator();
    givenAnOpperatorInFunction_whenGettingLowestPriorityOpperator_thenShouldGetEmptyString();
    givenNoOpperator_whenGettingLowestPriorityOpperator_thenShouldGetEmptyString();
    givenAnEquationFunction_whenCheckingIsAFunction_thenShouldBeTrue();
    givenNotAnEquationFunction_whenCheckingIsAFunction_thenShouldBeFalse();
    givenASinFunction_whenGettingFunction_thenShouldGetSin();
    givenParentheseFunction_whenGettingFunction_thenSouldGetEmptyString();
    givenManyFunction_whenGettingFunction_thenShouldRaise();
    givenOneFunction_whenGettingFunctionInside_thenShouldGetSubstringBetweenBracket();
    givenManyFunction_whenGettingFunctionInside_thenShouldRaise();
    givenNotAFunction_whenGettingFunctionInside_thenShouldRaise();
}


int main() {
    runAllTest();

    return 0;
}
