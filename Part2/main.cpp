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
    vector<int> stackSize;

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
            // std::cout <<"Start has been found"<< std::endl;
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

    while (!instMemDone and instructionBool == true)
    {   
        // std::cout <<"While loop has been entered"<< std::endl;
        std::string foo [3];
        char seperator = ' ';    // space

        split(i_Mem->inst_Mem[pc], seperator);

        // ***** Add in error handling to exit loop if error occurs *****

        for (int i = 0; i < max; i++)
        {
          // std::cout <<"Setting Foo"<< std::endl;
          foo[i] = strings[i];
        }
         //Using strstr() and converting string to c-string.
    
    if (strstr (foo[0].c_str (), gosublabel.c_str ()))
    {
        d_Mem->addSubStack(stoi(foo[1]));
        stackSize.insert(stackSize.begin(), stoi(foo[1])); // hold the size of the stack so you can pop off the correct amt at return
        pc++;
    }
    else if (strstr (foo[0].c_str (), start.c_str ()))
    {
        d_Mem->addMainStack(stoi(foo[1]));
        d_Mem->mainsize = stoi(foo[1]);
        pc++;
    }
    else if (strstr (foo[0].c_str (), exit_str.c_str ()))
    {
        // std::cout <<"Entered Exit"<< std::endl;
        instMemDone = true;   
    }
    else if (strstr (foo[0].c_str (), jumpzero.c_str ()))
    {
        // Piazza @561 to finish!!!!!!!!
        if(r_Stack->run_stack[0] == 0){
            pc = stoi(foo[1]);
        }
        else {
            pc++;
        }
        r_Stack->run_stack.erase(r_Stack->run_stack.begin());
        // pc = foo[]
    }
  else if (strstr (foo[0].c_str (), jumpnzero.c_str ()))
    {
        // Piazza @561 to finish!!!!!!!!
        if(r_Stack->run_stack[0]){
            pc = stoi(foo[1]);
        }
        else{
            pc++;
        }
        r_Stack->run_stack.erase(r_Stack->run_stack.begin());
        // pc = foo[]
    }
  else if (strstr (foo[0].c_str (), gosub.c_str ()))
    {
        returnAddress.insert(returnAddress.begin(), (pc+1));
        pc = stoi(foo[1]);
        // for (int i = 0; i < returnAddress.size(); i++)
        // {
        //   //std::cout << returnAddress[i] << std::endl;
        // }
    }
  else if (strstr (foo[0].c_str (), return_str.c_str ()))
    {
       pc = returnAddress[0];
       returnAddress.erase(returnAddress.begin());
       d_Mem->deleteStack(stackSize[0]);
       stackSize.erase(stackSize.begin());

    }
  else if (strstr (foo[0].c_str (), pushscal.c_str ()))
    {
        d_Mem->pushScl(stoi(foo[1]), r_Stack);
        pc++;
    }
  else if (strstr (foo[0].c_str (), pusharr.c_str ()))
    {
        d_Mem->pushArr(stoi(foo[1]), r_Stack);
        pc++;
    }
  else if (strstr (foo[0].c_str (), pushi.c_str ()))
    {
        r_Stack->run_stack.insert(r_Stack->run_stack.begin(), stoi(foo[1]));
        pc++;
    }
  else if (strstr (foo[0].c_str (), popscal.c_str ()))
    {
        d_Mem->popScl(stoi(foo[1]), r_Stack);
        pc++;
    }
  else if (strstr (foo[0].c_str (), poparr.c_str ()))
    {
        d_Mem->popArr(stoi(foo[1]), r_Stack);
        pc++;
    }
  else if (strstr (foo[0].c_str (), jump.c_str ()))
    {
        pc = stoi(foo[1]);
    }
  else if (strstr (foo[0].c_str (), pop.c_str ()))
    {
        r_Stack->run_stack.erase(r_Stack->run_stack.begin());
        pc++;
    }
  else if (strstr (foo[0].c_str (), dup.c_str ()))
    {
        r_Stack->dup();
        pc++;
    }
  else if (strstr (foo[0].c_str (), swap.c_str ()))
    {
        r_Stack->swap();
        pc++;
    }
  else if (strstr (foo[0].c_str (), add.c_str ()))
    {
        r_Stack->add();
        pc++;
    }
  else if (strstr (foo[0].c_str (), negate.c_str ()))
    {
        r_Stack->negate();
        pc++;
    }
  else if (strstr (foo[0].c_str (), mul.c_str ()))
    {
        r_Stack->mul();
        pc++;
    }
  else if (strstr (foo[0].c_str (), div_str.c_str ()))
    {
        r_Stack->div();
        pc++;
    }
  else if (strstr (foo[0].c_str (), printtos.c_str ()))
    {
        std::cout << r_Stack->run_stack[0] << std::endl;
        r_Stack->run_stack.erase(r_Stack->run_stack.begin());
        pc++;
    }
  else if (strstr (foo[0].c_str (), prints.c_str ()))
    {
        std::cout << stringTable[stoi(foo[1])] << std::endl;
        pc++;
    }
  else
    {
        // if(instCount == 0){
        //     cout << "Error none are present." << endl;
        // }
        // else if(endCount == 0){
        //     std::cout << "Error: No End Statement In Program" << std::endl;
        // }
        // else if(endErr){
        //     //does nothing
        // }
        // else if (ScalErr) {
        //     std::cout << "error: attempting to add variable with name " << ErrScal << " twice" << std::endl;
        // }
        // else if (ArrErr) {
        //     std::cout << "error: attempting to add variable with name " << ErrArr << " twice" << std::endl;
        // }
        // else if (LabelErr) {
        //     std::cout << "error: attempting to add label with name " << ErrLabel << " twice" << std::endl;
        // }
        // if {

          ;
    }


        // Set at the end of the vector
    }
    // std::cout << i_Mem->inst_Mem << std::endl;
    

    return 0;
} 