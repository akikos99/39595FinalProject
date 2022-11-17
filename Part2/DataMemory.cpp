#include "DataMemory.h"
#include <string>
#include <vector>
#include "RunStack.h"

DataMemory* DataMemory::uniqueInstance = nullptr;
 
DataMemory::DataMemory(){
    //scope_indexes.push_back(0);
};
 
DataMemory* DataMemory::getInst(){
    if(uniqueInstance == nullptr){
        uniqueInstance = new DataMemory();
    }
    return uniqueInstance;
}

void DataMemory::addStack(int scope_size){

    for(int i=0; i<scope_size; i++){
        data_mem.push_back(0); // initialized new scope values with zeros

    }

}

void DataMemory::popScl(int opnd, RunStack* rs){
    data_mem[opnd] = rs->run_stack[0];
    rs->run_stack.erase(rs->run_stack.begin());
}

void DataMemory::popArr(int opnd, RunStack* rs){
    int stackValue = rs->run_stack[0];
    int e = opnd + stackValue;
    rs->run_stack.erase(rs->run_stack.begin());
   
    data_mem[e] = rs->run_stack[0];
    rs->run_stack.erase(rs->run_stack.begin());
}

void DataMemory::pushScl(int opnd, RunStack* rs){

    rs->run_stack.insert(rs->run_stack.begin(), data_mem[opnd]);
}

void DataMemory::pushArr(int opnd, RunStack* rs){
    int e = opnd + rs->run_stack[0];
    rs->run_stack.erase(rs->run_stack.begin());
    rs->run_stack.insert(rs->run_stack.begin(), data_mem[e]);

}

void DataMemory::deleteStack(int size){
    for(int i=0; i<size; i++){
        data_mem.pop_back();
    }
}