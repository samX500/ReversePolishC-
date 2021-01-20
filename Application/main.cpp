#include <iostream>
#include "../test/test.h"


int main() {
    //runAllTest();
    while(true) {
        std::cout << "Enter your equation here" << std::endl;
        std::string equation;
        std::cin >> equation;

        CalculatorFactory factory = CalculatorFactory();
        Calculator *calculator = factory.getCalculator(CalculatorFactory::REVERSE_POLISH);
        double result = calculator->evaluate(equation);
        std::cout << "The result is" << std::endl;
        std::cout << result << std::endl;
    }
    return 0;
}
