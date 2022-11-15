#include <string>
#include <vector>
#include <ostream>
#include "RunStack.h"
#include "DataMemory.h"
#include "InstructionMemory.h"

#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
//#include <bits/stdc++.h>
#include <vector>
#define max 3
using namespace std;
using namespace std;


string strings[max];

int len(string str)
{
    int length = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        length++;
          
    }
    return length;
}

void split (string str, char seperator)
{
    int currIndex = 0, i = 0;
    int startIndex = 0, endIndex = 0;
    while (i <= len(str))
    {
        if (str[i] == seperator || i == len(str))
        {
            endIndex = i;
            string subStr = "";
            subStr.append(str, startIndex, endIndex - startIndex);
            strings[currIndex] = subStr;
            currIndex += 1;
            startIndex = endIndex + 1;
        }
        i++;
        }
}

int main(int argc, char** argv)
{
    ifstream inFile (argv[1]);
    //ifstream inFile("/Users/jenniferniemeyer/Downloads/ECE 39595/ProjectAssigned/OutputAndTestCases/TestCases10_08_22/26Recurse");
    if (!inFile.is_open( )) {
          std::cout << "failed to open file " << argv[1] << ", terminating" << std::endl;
          return -1;
       }
    int arrayIndex = 0;
    vector<std::string> stringTable;
    InstructionMemory* i_Mem = InstructionMemory::getInst();
    RunStack* r_Stack = RunStack::getInst();
    DataMemory* d_Mem = DataMemory::getInst();
    vector<int> returnAddress; 

    int endCount =0;
    

    string declscal = "declscal";
    string declarr = "declarr";
    string gosublabel = "gosublabel";
    string label = "label";
    string start = "start";

    string end = "end";
    string exit_str = "exit";
    string jumpzero = "jumpzero";
    string jumpnzero = "jumpnzero";
    string jump = "jump";
    string gosub = "gosub";

    string return_str = "return";
    string pushscal = "pushscal";
    string pusharr = "pusharr";
    string pushi = "pushi";
    string popscal = "popscal";

    string poparr = "poparr";
    string pop = "pop";
    string dup = "dup";
    string swap = "swap";
    string add = "add";
    
    string negate = "negate";
    string mul = "mul";
    string div_str = "div";
    string printtos = "printtos";
    string prints = "prints";
    
  

    //ifstream inFile("test.txt");
    string str1;
    bool instructionBool = false;


    while (inFile)
    {
        // str1 is the line extracted from the .asm file

        getline(inFile, str1);

        // If string has 'start' in it, that means it's the beginning of the instruction bufffer

        if (str1.find("start") != string::npos) {
            instructionBool = true;
        }

        if (instructionBool == true) {
            // Add to Instruciton memory
            i_Mem->inst_Mem.push_back(str1);
        }
        else
        {
            //add to string memory
            stringTable.push_back(str1);
        }
        
        // SAVE FOR GOING THROUGH INST MEM
        
    }

    bool instMemDone = false;
    int pc = 0; // index of instruction memory vector location

    while (!instMemDone)
    {   
        std::string foo [3];
        char seperator = ' ';    // space

        split(i_Mem->inst_Mem[pc], seperator);

        // ***** Add in error handling to exit loop if error occurs *****

        for (int i = 0; i < max; i++)
        {
           foo[i] = strings[i];
        }

         //Using strstr() and converting string to c-string.
    
    if (strstr (foo[0].c_str (), gosublabel.c_str ()))
    {
        d_Mem->addStack(stoi(foo[1]));
        pc++;
    }
    else if (strstr (foo[0].c_str (), start.c_str ()))
    {
        d_Mem->addStack(stoi(foo[1]));
        pc++;
    }
    else if (strstr (foo[0].c_str (), exit_str.c_str ()))
    {
        instMemDone = true;   
    }
    else if (strstr (foo[0].c_str (), jumpzero.c_str ()))
    {
        // Piazza @561 to finish!!!!!!!!
        r_Stack->run_stack.erase(r_Stack->run_stack.begin());
        // pc = foo[]
    }
  else if (strstr (foo[0].c_str (), jumpnzero.c_str ()))
    {
        // Piazza @561 to finish!!!!!!!!
        r_Stack->run_stack.erase(r_Stack->run_stack.begin());
        // pc = foo[]
    }
  else if (strstr (foo[0].c_str (), gosub.c_str ()))
    {
        r_Stack->run_stack;
    }
  else if (strstr (foo[0].c_str (), return_str.c_str ()))
    {
       
    }
  else if (strstr (foo[0].c_str (), pushscal.c_str ()))
    {
        std::string instruction = foo[0];
        std::string total = instruction + " " + foo[1] + " ?";
        i_buff->add_instruction(total);
        //int location = inst_buffer.size();
//      cout << "pushscal is present." << endl;
        instCount++;
    }
  else if (strstr (foo[0].c_str (), pusharr.c_str ()))
    {
        std::string instruction = foo[0];
        std::string total = instruction + " " + foo[1] + " ?";
        i_buff->add_instruction(total);
        //int location = inst_buffer.size();
//      cout << "pusharr is present." << endl;
        instCount++;
    }
  else if (strstr (foo[0].c_str (), pushi.c_str ()))
    {
        std::string instruction = foo[0];
        std::string total = instruction + " " +foo[1];
        i_buff->add_instruction(total);
        //int location = inst_buffer.size();
//      cout << "pushi is present." << endl;
        instCount++;
    }
  else if (strstr (foo[0].c_str (), popscal.c_str ()))
    {
        std::string instruction = foo[0];
        std::string total = instruction + " " + foo[1] + " ?";
        i_buff->add_instruction(total);
        //int location = inst_buffer.size();
//      cout << "popscal is present." << endl;
        instCount++;
    }
  else if (strstr (foo[0].c_str (), poparr.c_str ()))
    {
        std::string instruction = foo[0];
        std::string total = instruction + " " + foo[1] + " ?";
        i_buff->add_instruction(total);
        //int location = inst_buffer.size();
//      cout << "poparr is present." << endl;
        instCount++;
    }
  else if (strstr (foo[0].c_str (), jump.c_str ()))
    {
        std::string instruction = foo[0];
        std::string total = instruction + " " + foo[1] + " ?";
        i_buff->add_instruction(total);
//      cout << "declarr is present." << endl;
        instCount++;
    }
  else if (strstr (foo[0].c_str (), pop.c_str ()))
    {
        std::string instruction = foo[0];
        i_buff->add_instruction(foo[0]);
        //int location = inst_buffer.size();
//      cout << "pop is present." << endl;
        instCount++;
    }
  else if (strstr (foo[0].c_str (), dup.c_str ()))
    {
        std::string instruction = foo[0];
        i_buff->add_instruction(foo[0]);
        //int location = inst_buffer.size();
//      cout << "dup is present." << endl;
        instCount++;
    }
  else if (strstr (foo[0].c_str (), swap.c_str ()))
    {
        std::string instruction = foo[0];
        i_buff->add_instruction(foo[0]);
        //int location = inst_buffer.size();
//      cout << "swap is present." << endl;
        instCount++;
    }
  else if (strstr (foo[0].c_str (), add.c_str ()))
    {
        std::string instruction = foo[0];
        i_buff->add_instruction(foo[0]);
        //int location = inst_buffer.size();
//      cout << "add is present." << endl;
        instCount++;
    }
  else if (strstr (foo[0].c_str (), negate.c_str ()))
    {
        std::string instruction = foo[0];
        i_buff->add_instruction(foo[0]);
        //int location = inst_buffer.size();
//      cout << "negate is present." << endl;
        instCount++;
    }
  else if (strstr (foo[0].c_str (), mul.c_str ()))
    {
        std::string instruction = foo[0];
        i_buff->add_instruction(foo[0]);
       // int location = inst_buffer.size();
//      cout << "mul is present." << endl;
        instCount++;
    }
  else if (strstr (foo[0].c_str (), div_str.c_str ()))
    {
        std::string instruction = foo[0];
        i_buff->add_instruction(foo[0]);
       // int location = inst_buffer.size();
//      cout << "div is present." << endl;
        instCount++;
    }
  else if (strstr (foo[0].c_str (), printtos.c_str ()))
    {
        std::string instruction = foo[0];
        i_buff->add_instruction(foo[0]);
       // int location = inst_buffer.size();
//      cout << "printtos is present." << endl;
        instCount++;
    }
  else if (strstr (foo[0].c_str (), prints.c_str ()))
    {

        // String added to the string buffer
       // stringBufferArr[arrayIndex] = foo[1];
        stringBufferArr.push_back(foo[1]);

        //   Now add inst to inst buffer

        std::string instruction = foo[0];
        std::string total = instruction + " " + std::to_string(arrayIndex);
        i_buff->add_instruction(total);
      //  int location = inst_buffer.size();
        arrayIndex += 1;
        instCount++;

    }
  else
    {
        if(instCount == 0){
            cout << "Error none are present." << endl;
        }
        else if(endCount == 0){
            std::cout << "Error: No End Statement In Program" << std::endl;
        }
        else if(endErr){
            //does nothing
        }
        else if (ScalErr) {
            std::cout << "error: attempting to add variable with name " << ErrScal << " twice" << std::endl;
        }
        else if (ArrErr) {
            std::cout << "error: attempting to add variable with name " << ErrArr << " twice" << std::endl;
        }
        else if (LabelErr) {
            std::cout << "error: attempting to add label with name " << ErrLabel << " twice" << std::endl;
        }
        else {
            //Print String Buffer
            for(int y = 0; y< stringBufferArr.size(); y++){
                std::cout << stringBufferArr[y] << std::endl;
            }
            // printing Instruction Buffer
            int ib_size = (int)i_buff->inst_buffer.size();
            for(int z=0;z<ib_size; z++){
                std::cout << i_buff->inst_buffer[z] << std::endl;
            }
        }
      
    }


        // Set at the end of the vector
        instMemDone = true;
    }
    

    

    
    return 0;
} 