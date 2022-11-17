#ifndef DataMemory_h
#define DataMemory_h
#include <string>
#include <vector>
#include "RunStack.h"
#include <stack>

class DataMemory {
    public:
        static DataMemory* getInst();
        void addMainStack(int arr_size);
        void addSubStack(int size);
        void deleteStack(int arr_size);
        int getVal(int index);
        void setVal(int index, int val);
        //std::vector<int> scope_indexes; //hold index of start of new stack
        //int scope = 0;
        void popScl(int opnd, RunStack* rs);
        void popArr(int opnd, RunStack* rs);
        void pushScl(int opnd, RunStack* rs);
        void pushArr(int opnd, RunStack* rs);
        int mainsize = 0;

    private:
        DataMemory();
        static DataMemory* uniqueInstance;
        std::vector<int> data_mem;
        //std::vector<int> sub_mem;
        std::stack<std::vector<int>> sub_mem;

};





#endif