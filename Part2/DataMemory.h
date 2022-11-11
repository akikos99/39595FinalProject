#ifndef DataMemory_h
#define DataMemory_h
#include <string>
#include <vector>
#include "RunStack.h"

class DataMemory {
    public:
        static DataMemory* getInst();
        void addStack(int arr_size);
        void deleteStack(int arr_size);
        std::vector<int> data_mem;
        //std::vector<int> scope_indexes; //hold index of start of new stack
        //int scope = 0;
        void popScl(int opnd, RunStack* rs);
        void popArr(int opnd, RunStack* rs);
        void pushScl(int opnd, RunStack* rs);
        void pushArr(int opnd, RunStack* rs);

    private:
        DataMemory();
        static DataMemory* uniqueInstance;

};





#endif