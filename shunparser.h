#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include "mathprocess.h"

struct parserObj{

    enum operatorPrecedence {min = 2, plus = 2, div = 3, mult = 3, pow = 4};


    std::vector<std::string> operators; //stack for storing operators and functions during execution of algorithm
    std::string runParse(std::string input); //returns postfix expression of the input. convinient to call externally.
    float calct(std::string); //returns result of the input. convinient to call externally.
    std::queue<std::string> toShun(std::string input); //returns postfix exp. as queue
    std::string printShun(std::queue <std::string>); //returns postfix exp. by converting queue to string.
    float readShun(std::queue <std::string>); //returns result from queue input. refer to "calct" function in order to pass string input

};

extern std::vector<char> operatorList;

unsigned short retPrecedence(char); //returns precedence value of an operator

bool isFunction(std::string); //checks if string is a function
bool isDefined(std::string); //checks if string is a defined variable
bool isOperator(char); //checks if char is an operator

void execOperation(std::vector<float> *, std::string); 
//"execOperation" executes operation when an operator is found while iterating through postfix queue and executes it on the values stored in variables stack.
