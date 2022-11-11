#include "RunStack.h"
#include <string>
#include <vector>

RunStack* RunStack::uniqueInstance = nullptr;
 
RunStack::RunStack(){};
 
RunStack* RunStack::getInst(){
    if(uniqueInstance == nullptr){
        uniqueInstance = new RunStack();
    }
    return uniqueInstance;
}