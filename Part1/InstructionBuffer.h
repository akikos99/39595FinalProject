#ifndef InstructionBuffer_h
#define InstructionBuffer_h
#include <string>
#include <vector>
#include "SymbolTable.h"
 
class InstructionBuffer{
public:
    static InstructionBuffer* getInst();
    int start_loc=1;
    int end_loc;
    void update_buffer(SymbolTable* st);
    void add_instruction(std::string instruction);
    std::vector<std::string> inst_buffer;
    
private:
    InstructionBuffer();
    
    
    static InstructionBuffer* uniqueInstance;
    
    std::string split (std::string str, char seperator);
    int len(std::string str);
};
 
#endif /* InstructionBuffer_h */
