#ifndef DataMemory_h
#define DataMemory_h
#include <string>
#include <vector>

class DataMemory {
    public:
        static DataMemory* getInst();
        void addStack(int arr_size);
        void deleteStack();
        std::vector<int> data_mem;
        std::vector<int> scope_indexes; //hold index of start of new stack
        int scope = 0;
        void popStack(int opnd);

    private:
        DataMemory();
        static DataMemory* uniqueInstance;

};





#endif