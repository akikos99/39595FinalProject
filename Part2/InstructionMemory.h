#ifndef InstructionMemory_h
#define InstructionMemory_h
#include <string>
#include <vector>

class InstructionMemory {
    public:
        static InstructionMemory* getInst();
        std::vector<std::string> inst_Mem;
    private:
        InstructionMemory();
        static InstructionMemory* uniqueInstance;
};











#endif