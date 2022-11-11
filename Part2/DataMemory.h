#ifndef DataMemory_h
#define DataMemory_h
#include <string>
#include <vector>

class DataMemory {
    public:
        static DataMemory* getInst();
        std::vector<int> data_mem;

    private:
        DataMemory();
        static DataMemory* uniqueInstance;

};





#endif