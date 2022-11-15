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


string strings[max];int len(string str)
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
    std::string instructionBufferArr[24];
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
        //  != string::npos
        if (str1.find("start")) {
            instructionBool = true;
            // // This means it's from the instructuion buffer and we should add it to the Instruction memory
            // split (str1, seperator);
        }

        if (instructionBool == true) {
            // Add to Instruciton memory
        }
        else
        {
            //add to string memory
        }
        
        // SAVE FOR GOING THROUGH INST MEM
        // std::string foo [3];
        // char seperator = ' ';    // space
        // for (int i = 0; i < max; i++)
        // {
        //    foo[i] = strings[i];
        // }

    

    
    return 0;
} 