#include "shunparser.h"

std::vector<char> operatorList {'+','-','*','/','%','^'};

std::string parserObj::runParse(std::string input){
    std::cout << "Result:\n";
    return printShun(toShun(input));
}

float parserObj::calct(std::string input){
    return readShun(toShun(input));
}

std::queue<std::string> parserObj::toShun(std::string input){
    std::string strBuffer; //add to process numbers more than one digits
    std::queue<std::string> output;
    for(unsigned short i = 0; i < input.length(); i++){
        //check if token is number
        if(isdigit(input[i])){
            //std::cout << "isdigit: " << input[i] << std::endl; //remove
            //check if buffer empty
            if(strBuffer.length()==0){
                strBuffer+=input[i];                
            }
            //check if buffer is number
            else if(isdigit(strBuffer[0]) || strBuffer[0]=='.' || strBuffer[0]=='+' || strBuffer[0]=='-'){
                strBuffer+=input[i];
            }
            //if buffer not empty and not number
            else{
                if(isFunction(strBuffer)){
                    operators.push_back(strBuffer);
                }
                else if(isDefined(strBuffer)){
                    output.push(retVariable(strBuffer));
                }
                strBuffer = input[i];
            }
        }
        //check if is an operator
        else if(isOperator(input[i])){

            if(strBuffer.length() == 0 && (input[i]=='+' || input[i]=='-')){
                strBuffer += input[i];
                continue;
            }
            //push buffer
            else{

                if(isFunction(strBuffer)){
                    operators.push_back(strBuffer);
                }
                else if(isDefined(strBuffer)){
                    output.push(retVariable(strBuffer));
                }
                else{
                    output.push(strBuffer);
                }
                strBuffer = "";
            }

            while(operators.size()!=0 && operators.back() != "(" && !isFunction(operators.back()) && (retPrecedence(input[i]) <= retPrecedence(operators.back()[0])) && input[i] != '^'){
                output.push(operators.back());
                operators.pop_back();
            }
            operators.push_back(std::string(1,input[i]));
        }
        else if(input[i] == '('){
            operators.push_back(std::string(1,input[i]));
        }
        else if(input[i] == ')'){
            while(operators.size() != 0 && operators.back()!="("){
                if(strBuffer.length() != 0){
                    if(isFunction(strBuffer)){
                        operators.push_back(strBuffer);
                    }
                    else if(isDefined(strBuffer)){
                        output.push(retVariable(strBuffer));
                    }
                    else{
                        output.push(strBuffer);
                    }
                    strBuffer = "";
                }

                output.push(operators.back());
                operators.pop_back();

            }
                if(operators.size() != 0 && operators.back() == "("){
                    operators.pop_back();
                }
                else{
                    std::cout << "[ERROR] Incomplete right paranthesis at position " << (i + 1) << std::endl;
                    std::exit(1);
                }

            if(operators.size() !=0 && isFunction(operators.back())){
                output.push(operators.back());
                operators.pop_back();
            }
        }
        
        else{
            if(strBuffer.length()!=0 && (isdigit(strBuffer[0]) || strBuffer[0]=='.' || strBuffer[0]=='+' || strBuffer[0]=='-') ){
                if(input[i] == '.'){
                    strBuffer+=input[i];
                }
                else{
                    output.push(strBuffer);
                    strBuffer = input[i];
                }
            }

            else if(isFunction(strBuffer)){
                operators.push_back(strBuffer);
                strBuffer = input[i];
            }

            else{
                strBuffer+=input[i];
            }
        }

    }

    //check if strbuffer empty
    if(strBuffer.length()!=0){
        if(isDefined(strBuffer)){
            output.push(retVariable(strBuffer));
        }
        else{
            output.push(strBuffer);
        }
    }

    //check if operator stack empty
    while(operators.size()!=0){
        if(operators.back() == "(" ){
            std::cout << "[ERROR] You have mismatched paranthesis.\n";
            std::exit(1);
        }
        output.push(operators.back());
        operators.pop_back();
        //std::cout << "buffer at " << "is: " << strBuffer << std::endl; //remove

    }

    return output;

} //shunning-yard algorithm

std::string parserObj::printShun(std::queue <std::string> outputList){
    std::string output = "";
    std::queue <std::string> bufferq = outputList; //maybe unnecessary duplication
    while(bufferq.size()>0){
        output += bufferq.front();
        bufferq.pop();
    }
    return output;
}

float parserObj::readShun(std::queue <std::string> outputList){
    float result = 0.0;
    std::vector <float> varStack;
    while(outputList.size()>0){
        //if token is an operator
        if(outputList.front().length() == 1 && isOperator(outputList.front()[0])){
            execOperation(&varStack,outputList.front());
        }

        else if(isFunction(outputList.front())){
            //execute function
            execFunction(&varStack,outputList.front());
        }

        else{
            varStack.push_back(strtof(outputList.front().c_str(),nullptr));
        }

        outputList.pop();
    }
    if(varStack.size() == 1){
        return varStack[0];
    }
    else{
        std::cout << "[ERROR] Operations incomplete.\n";
        std::exit(1);
    }
}


void execOperation(std::vector <float> *stackp, std::string optr){
    float fItem = stackp->at(stackp->size() -2);
    float sItem = stackp->at(stackp->size() -1);
    stackp->pop_back();
    stackp->pop_back();
    switch (optr[0])
    {
    case '+':
        stackp->push_back(fItem+sItem);
        break;
    case '-':
        stackp->push_back(fItem-sItem);
        break;
    case '*':
        stackp->push_back(fItem*sItem);
        break;
    case '/':
        stackp->push_back(fItem/sItem);
        break;
    case '^':
        stackp->push_back(powf(fItem,sItem)); //apply function for finding power of floats
        break;
    case '%':
        stackp->push_back(fmod(fItem,sItem)); //apply function for finding modulo of floats
        break;

    
    default:
        std::cout << "[ERROR] Undefined operator.\n";
        std::exit(1);
    }

}


unsigned short retPrecedence(char operatorToken){
    switch (operatorToken)
    {
    case '+':
        return 2;    
    case '-':
        return 2;
    case '*':
        return 3;
    case '/':
        return 3;
    case '^':
        return 4;
    case '.': //can change
        return 0;
    case '%':
        return 3;
    case '(':
        return 1;
    case ')':
        return 1;
    default:
        return 1000;
    }
}

bool isOperator(char buffer){
    if(std::find(operatorList.begin(),operatorList.end(), buffer) != operatorList.end()){
        return true;
    }
    else{
        return false;
    }
}

bool isDefined(std::string buffer){
    if(std::find(definedVars.begin(),definedVars.end(), buffer) != definedVars.end()){
        return true;
    }
    else{
        return false;
    }
}

bool isFunction(std::string buffer){
    if(std::find(operationFunctions.begin(),operationFunctions.end(), buffer) != operationFunctions.end()){
        return true;
    }
    else{
        return false;
    }
}