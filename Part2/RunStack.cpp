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

void RunStack::dup(){
    int top = run_stack[0];
    run_stack.insert(run_stack.begin(), top);
}

void RunStack::swap(){
    int top = run_stack[0];
    int second = run_stack[1];
    run_stack[0] = second;
    run_stack[1] = top;
}

void RunStack::add(){
    int top = run_stack[0];
    int second = run_stack[1];
    run_stack.erase(run_stack.begin());
    run_stack[0] = top + second;
}