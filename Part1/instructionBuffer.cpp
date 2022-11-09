#include "InstructionBuffer.h"
#include <string>
#include <vector>
#include "SymbolTable.h"
#include <iostream>
#include "TwoTuple.h"
#include <cstring>
#define max 3
#include <fstream>
#include <iostream>
 
 
InstructionBuffer* InstructionBuffer::uniqueInstance = nullptr;
 
InstructionBuffer::InstructionBuffer(){};
 
InstructionBuffer* InstructionBuffer::getInst(){
    if(uniqueInstance == nullptr){
        uniqueInstance = new InstructionBuffer();
    }
    return uniqueInstance;
}

 
void InstructionBuffer::add_instruction(std::string instruction){
    //std::cout << "Entered the add instruciton buffer " << instruction <<std::endl;
    inst_buffer.push_back(instruction);
    std::string st2 = "gosublabel";
    std::string st3 = "return";
    std::string st4 = "end";
    if(strstr(instruction.c_str(),st2.c_str())){
        start_loc = (int)inst_buffer.size();
    }
    if(strstr(instruction.c_str(),st3.c_str())){
        end_loc = (int)inst_buffer.size();
    }
    else if (strstr(instruction.c_str(),st4.c_str())){
        end_loc = (int) inst_buffer.size();
    }
}


void InstructionBuffer::update_buffer( SymbolTable* st){
    //std::cout << "Entered the update_buffer " << std::endl;
    end_loc = (int)inst_buffer.size();
    int x ;
    std::string newOp;
    
    std::string str2 = "?";
    std::string str3 = "gosublabel " ;
    std::string str4 = "start ";
    std::string str5 = "jumpzero ";
    std::string str6 = "jumpnzero ";
    std::string str7 = "jump ";
    std::string str8 = "gosub ";
    std::string str9 = "popscal ";
    std::string str10 = "poparr ";
    std::string str11 = "pushscal ";
    std::string str12 = "pusharr ";
    //std::string str11 = "pop ";
  //  std::cout << start_loc << end_loc << std::endl;
    for(x= (start_loc-1); x< end_loc; x++){
        //std::string foo [3];
        char seperator = ' ';    // space
        //std::cout << inst_buffer.size() << std::endl;
        std::string str1 = inst_buffer[x];
        //std::cout << inst_buffer[x] << std::endl;
    std::string op_code = split(str1, seperator);
        if(strstr(str1.c_str(), str2.c_str())) {
            if(strstr(str1.c_str(), str3.c_str())) {
                int sum = st->getLengthVar(1);
                newOp = std::to_string(sum);
                inst_buffer[x] = "gosublabel "  + newOp;
            }
            else if (strstr(str1.c_str(), str4.c_str())) {
                int sum = st->getLengthVar(0);
                newOp = std::to_string(sum);
                inst_buffer[x] = "start "  + newOp;
            }
            else if (strstr(str1.c_str(), str5.c_str())){
                TwoTuple* save;
 
                save = st->getLabel(op_code);
                int loc = save->position;
                newOp = std::to_string(loc);
                inst_buffer[x] = "jumpzero "  + newOp;
                
            }
            else if(strstr(str1.c_str(), str6.c_str())){
                TwoTuple* save;
                save = st->getLabel(op_code);
                int loc = save->position;
                newOp = std::to_string(loc);
                inst_buffer[x] = "jumpnzero "  + newOp;
            }
            else if(strstr(str1.c_str(), str7.c_str())) {
                TwoTuple* save;
                save = st->getLabel(op_code);
                int loc = save->position;
                newOp = std::to_string(loc);
                inst_buffer[x] = "jump "  + newOp;
            }
            else if (strstr(str1.c_str(), str8.c_str())) {
                TwoTuple* save;
                save = st->getLabel(op_code);
                int loc = save->position;
                newOp = std::to_string(loc);
                inst_buffer[x] = "gosub "  + newOp;
            }
            else if (strstr(str1.c_str(), str9.c_str())) {
                TwoTuple* save;
                save = st->getData(op_code);
                int loc = save->position;
                newOp = std::to_string(loc);
                inst_buffer[x] = "popscal "  + newOp;
            }
            else if (strstr(str1.c_str(), str10.c_str())) {
                TwoTuple* save;
                save = st->getData(op_code);
                int loc = save->position;
                newOp = std::to_string(loc);
                inst_buffer[x] = "poparray "  + newOp;
            }
            else if (strstr(str1.c_str(), str11.c_str())) {
                TwoTuple* save;
                save = st->getData(op_code);
                int loc = save->position;
                newOp = std::to_string(loc);
                inst_buffer[x] = "pushscal "  + newOp;
            }
            else if (strstr(str1.c_str(), str12.c_str())) {
                TwoTuple* save;
                save = st->getData(op_code);
                int loc = save->position;
                newOp = std::to_string(loc);
                inst_buffer[x] = "pusharray "  + newOp;
            }
        }
    }
        
}
std::string InstructionBuffer::split (std::string str, char seperator)
{
    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    std::string strings[max];
    while (i <= len(str))
    {
        if (str[i] == seperator || i == len(str))
        {
            endIndex = i;
            std::string subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
            strings[currIndex] = subStr;
            currIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;
        }
    return strings[1];
}
int InstructionBuffer::len(std::string str)
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;
          
    }
    return length;
}
