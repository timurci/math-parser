#include <iostream>
#include "shunparser.h"

int main(){

    parserObj calc;
    std::string input;

    while((std::cin >> input) && (input != "exit")){

        if(input == "deg"){
            isRadian = false;
        }
        else if(input == "rad"){
            isRadian = true;
        }
        else{
        std::cout << "Result:\n";
        //std::cout << calc.runParse(input) << std::endl; //uncomment to see postfix expression of the input
        std::cout << calc.calct(input); //print result of the input
        }
        std::cout << "\n=======\n";
    }

    // ==== EXAMPLES ===
    // std::cout << "*/" << calc.runParse("4+2") << "\\*" << std::endl; //exp. output: "42+"
    // std::cout << "*/" << calc.runParse("67+12*4-8") << "\\*" << std::endl; //exp. output: "67124*+8-"
    // std::cout << "*/" << calc.runParse("6*pi-2*4/45") << "\\*" << std::endl; //exp. output: "6pi*24*45/-"

    // ==== EXAMPLES ===
    // std::cout << calc.runParse("4+2") << std::endl;
    // std::cout << calc.calct("4+2") << std::endl;
    // std::cout << calc.runParse("67+12*4-8") << std::endl;
    // std::cout << calc.calct("67+12*4-8") << std::endl;



    std::exit(0);
}