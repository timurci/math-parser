#include <iostream>
#include "shunparser.h"

int main(){

    parserObj calc;
    std::string input;

    while((std::cin >> input) && (input != " ")){
        std::cout << calc.runParse(input) << std::endl;
        std::cout << calc.calct(input) << "\n=======\n";
    }

    // ==== EXAMPLES ===
    // std::cout << "*/" << calc.runParse("xyz") << "\\*" << std::endl; //exp. output: "xyz"
    // std::cout << "*/" << calc.runParse("4+2") << "\\*" << std::endl; //exp. output: "42+"
    // std::cout << "*/" << calc.runParse("67+12*4-8") << "\\*" << std::endl; //exp. output: "67124*+8-"
    // std::cout << "*/" << calc.runParse("6*pi-2*4/45") << "\\*" << std::endl; //exp. output: "6pi*24*45/-"

    // ==== EXAMPLES ===
    // std::cout << calc.runParse("4+2") << std::endl;
    // std::cout << calc.calct("4+2") << std::endl;
    // std::cout << calc.runParse("67+12*4-8") << std::endl;
    // std::cout << calc.calct("67+12*4-8") << std::endl;
    // std::cout << calc.runParse("xyz") << std::endl;
    // std::cout << calc.calct("xyz") << std::endl;



    std::exit(0);
}