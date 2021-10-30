#include "mathprocess.h"

std::vector<std::string> operationFunctions {"sin","cos","tan","cot"};
std::vector<std::string> definedVars {"pi","eu"};
bool isRadian = true;

std::string retVariable(std::string buffer){
    if(buffer=="pi"){
        return "3.14159265359";
    }
    else if(buffer=="eu"){
        return "2.71828182845";
    }
    else{
        std::cout << "[ERROR] Indeterminate variable has been found.\n";
        std::exit(1);
    }
}

void execFunction(std::vector <float> *stackp, std::string func){
    float fItem, sItem;
    unsigned short initialSize = stackp->size();
    if(initialSize>1){
        fItem = stackp->at(stackp->size() -2);
        sItem = stackp->at(stackp->size() -1);
        stackp->pop_back();
        stackp->pop_back();
    }
    else{
        sItem = stackp->at(stackp->size() -1);
        stackp->pop_back();
    }

    if (func == "sin"){
        if(isRadian){
            if(initialSize > 1){
                stackp->push_back(fItem);
            }
            stackp->push_back(sin(sItem));
        }
        else{
            if(initialSize > 1){
                stackp->push_back(fItem);
            }
            stackp->push_back(sin(sItem*3.14159265359/180));
        }
    }

    else if (func == "cos"){
        if(isRadian){
            if(initialSize > 1){
                stackp->push_back(fItem);
            }
            stackp->push_back(cos(sItem));
        }
        else{
            if(initialSize > 1){
                stackp->push_back(fItem);
            }
            stackp->push_back(cos(sItem*3.14159265359/180));
        }
    }

    else if (func == "tan"){
        if(isRadian){
            if(initialSize > 1){
                stackp->push_back(fItem);
            }
            stackp->push_back(tan(sItem));
        }
        else{
            if(initialSize > 1){
                stackp->push_back(fItem);
            }
            stackp->push_back(tan(sItem*3.14159265359/180));
        }
    }

    else if (func == "cot"){
        if(isRadian){
            if(initialSize > 1){
                stackp->push_back(fItem);
            }
            stackp->push_back(1/(tan(sItem)));
        }
        else{
            if(initialSize > 1){
                stackp->push_back(fItem);
            }
            stackp->push_back(1/(tan(sItem*3.14159265359/180)));
        }
    }
}