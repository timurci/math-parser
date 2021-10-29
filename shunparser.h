#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>

struct parserObj{

    enum operatorPrecedence {min = 2, plus = 2, div = 3, mult = 3, pow = 4};


    std::vector<std::string> operators;
    std::string runParse(std::string input); //prints shun
    float calct(std::string); //returns calculation
    std::queue<std::string> toShun(std::string input); //converts expression according to shunning-yard algorithm
    std::string printShun(std::queue <std::string>); //should print converted result
    float readShun(std::queue <std::string>); //should calculate result, maybe diff ret val. later

};

extern std::vector<char> operatorList;
extern std::vector<std::string> operationFunctions;
extern std::vector<std::string> definedVars;
extern bool isRadian;

unsigned short retPrecedence(char);
std::string retVariable(std::string);

bool isFunction(std::string);
bool isDefined(std::string);
bool isOperator(char);

void execOperation(std::vector<float> *, std::string);
void execFunction(std::vector<float> *, std::string);
