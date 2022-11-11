#include "DataMemory.h"
#include <string>
#include <vector>

DataMemory* DataMemory::uniqueInstance = nullptr;
 
DataMemory::DataMemory(){
    scope_indexes.push_back(0);
};
 
DataMemory* DataMemory::getInst(){
    if(uniqueInstance == nullptr){
        uniqueInstance = new DataMemory();
    }
    return uniqueInstance;
}

void DataMemory::addStack(int arr_size){
    int startNewScope = data_mem.size();
    scope_indexes.push_back(startNewScope);
    scope++;
    

}

void DataMemory::popStack(int opnd){
    int dataMemLocation = scope_indexes[scope] + opnd - 1;
}