#include "DataMemory.h"
#include <string>
#include <vector>

DataMemory* DataMemory::uniqueInstance = nullptr;
 
DataMemory::DataMemory(){};
 
DataMemory* DataMemory::getInst(){
    if(uniqueInstance == nullptr){
        uniqueInstance = new DataMemory();
    }
    return uniqueInstance;
}