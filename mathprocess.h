#pragma once
#include <iostream>
#include <vector>
#include <math.h>

extern std::vector<std::string> operationFunctions;
extern std::vector<std::string> definedVars;
extern bool isRadian;

std::string retVariable(std::string);
void execFunction(std::vector<float> *, std::string);