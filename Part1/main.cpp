#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
//#include <bits/stdc++.h>
#include "SymbolTable.h"
#include <vector>
#include "InstructionBuffer.h"
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
    vector<std::string> stringBufferArr;
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
    int variableCount = 0;
    int variableCount2 = 0;
    bool error_marker = false;
    int instCount = 0;
    bool endErr = false;
    TwoTuple* check;
    bool ScalErr = false;
    std::string ErrScal;
    bool ArrErr = false;
    std::string ErrArr;
    bool LabelErr = false;
    std::string ErrLabel;

    // Create symbol table
    int scope = 0;
    SymbolTable* symbol_table = SymbolTable::makeSymbolTable();
    //std::vector<std::string> inst_buffer;
    InstructionBuffer* i_buff = InstructionBuffer::getInst();
    // InstructionBuffer::getInst()->add_instruction("hello");
    while (inFile)
    {
       // str1 is the line extracted from the .asm file
        // str1 is the line extracted from the .asm file

        getline(inFile, str1);

        std::string foo [3];
        char seperator = ' ';    // space
        split (str1, seperator);
        // cout << "\n 1 = instruction, 2 = opcode1, 3 = opcode2" << endl;
        for (int i = 0; i < max; i++)
        {
           foo[i] = strings[i];
          //  cout << "\n i : " << i << " " << foo[i] << endl;
        }

        if(error_marker && !(foo[0] == "")){
            cout << "end before end of file" << endl ;
            endErr = true;
        }

    //Using strstr() and converting string to c-string.
    if (strstr (foo[0].c_str (), declscal.c_str ()))
    {
        // Create instance of class
        int length = 1;
        //stmt *DS1 = new Declscal( );
        std::string key = foo[1];
        // pos = sizeof(instructionBufferArr)/sizeof(instructionBufferArr[0]);
        //DS1->symbolTableAction(key, variableCount, length, symbol_table);
        check = symbol_table->getData(key);
        if(check->length == 9999){
            symbol_table->putEntry(key, new TwoTuple(variableCount, length));
            variableCount++;
        }
        else{
            ScalErr = true;
            ErrScal = key;
        }
//        symbol_table->putEntry(key, new TwoTuple(variableCount, length));
//        variableCount++;
//        if(symbol_table->scope == 0){
//            symbol_table->putEntry(key, new TwoTuple(variableCount, length));
//            variableCount++;
//        }
//        else {
//            symbol_table->putEntry(key, new TwoTuple(variableCount2, length));
//            variableCount2++;
//        }
        
        // cout << "declscal is present." << endl;
        instCount++;
    }
  else if (strstr (foo[0].c_str (), declarr.c_str ()))
    {
       // stmt *DA1 = new Declarr( );
        std::string key = foo[1];
        int length = stoi(foo[2]);
        check = symbol_table->getData(key);
        if(check->length == 9999){
            symbol_table->putEntry(key, new TwoTuple(variableCount, length));
            variableCount+= length;
        }
        else{
            ArrErr = true;
            ErrArr = key;
        }
//        symbol_table->putEntry(key, new TwoTuple(variableCount, length));
//        variableCount += length;
        //DA1->symbolTableAction(key, variableCount, length, *symbolTable);
        //symbol_table->putEntry(key, new TwoTuple(variableCount, length));
//        if(symbol_table->scope == 0){
//            symbol_table->putEntry(key, new TwoTuple(variableCount, length));
//            variableCount++;
//        }
//        else {
//            symbol_table->putEntry(key, new TwoTuple(variableCount2, length));
//            variableCount2++;
       // }
        // cout << "declarr is present." << endl;
        instCount++;
    }
  else if (strstr (foo[0].c_str (), gosublabel.c_str ()))
    {
        // Symbol table
        int length = 0;
        
        //stmt *GSL1 = new Label( );
        std::string key = foo[1];
        //pos = sizeof(instructionBufferArr)/sizeof(instructionBufferArr[0]) + 1;
        int pos = (int)(i_buff->inst_buffer.size());
        //GSL1->symbolTableAction(key, pos, length, *symbolTable);
        check = symbol_table->getLabel(key);
        if(check->length == 9999){
            symbol_table->makeLabel(key, new TwoTuple(pos, length));
        }
        else{
            LabelErr = true;
            ErrLabel = key;
        }
        
        //variableCount++;
//        if(symbol_table->scope == 0){
//            variableCount++;
//        }
//        else {
//            variableCount2++;
//        }
        // Instruction buffer
        std::string instruction = foo[0];
        std::string total = instruction + " " + foo[1] + " ?";
        symbol_table->scope = 1;
        i_buff->add_instruction(total);
        //GSL1->instBufferAction(instruction, *instructionBufferArr[]);
        
        //int location = (int)(i_buff->inst_buffer.size()) - 1;
        
        // cout << "gosublabel is present." << endl;
        instCount++;
    }
  else if (strstr (foo[0].c_str (), label.c_str ()))
    {
        int length = 0;
        //stmt *L1 = new Label( );
        std::string key = foo[1];
        //pos = sizeof(instructionBufferArr)/sizeof(instructionBufferArr[0]) + 1;
        int pos = (int)(i_buff->inst_buffer.size());
        //L1->symbolTableAction(key, pos, length, *symbolTable);
        check = symbol_table->getLabel(key);
        if(check->length == 9999){
            symbol_table->makeLabel(key, new TwoTuple(pos, length));
        }
        else {
            LabelErr = true;
            ErrLabel = key;
        }
        //symbol_table->putEntry(key, new TwoTuple(pos, length));
        //variableCount++;
//        if(symbol_table->scope == 0){
//            variableCount++;
//        }
//        else {
//            variableCount2++;
//        }
        // cout << "label is present." << endl;
        instCount++;
    }
  else if (strstr (foo[0].c_str (), start.c_str ()))
    {
        //stmt *START1 = new Start ( );
        std::string instruction = foo[0];

       // START1->instBufferAction(instruction, *instructionBufferArr[]);
        std::string total = instruction + " " + foo[1] + " ?";
        //cout << "Entered the Start If:" << total << endl;
        i_buff->add_instruction(total);
        //cout << "Exited the add_instruction commad:" << endl;
        // cout << "Inst Buffer: " +i_buff->inst_buffer << endl;
        //int location = inst_buffer.size();
        // cout << "start is present." << endl;
    }
  else if (strstr (foo[0].c_str (), end.c_str ()))
    {
        //stmt *END1 = new End ( );
        std::string instruction = foo[0];
         error_marker = true;

            //END1->instBufferAction(instruction, *instructionBufferArr[]);
            //i_buff->add_instruction(foo[0]);
            //int location = inst_buffer.size();
        
            i_buff->update_buffer(symbol_table);
        
        
        // cout << "end is present." << endl;
        instCount++;
        endCount++;
    }
  else if (strstr (foo[0].c_str (), exit_str.c_str ()))
    {
        std::string instruction = foo[0];
        i_buff->add_instruction(foo[0]);
       // i_buff->update_buffer(symbol_table);
        //inFile.seekg(-1,ios_base::end);
       // int location = inst_buffer.size();
      //cout << "exit is present." << endl;
        instCount++;
        
    }
  else if (strstr (foo[0].c_str (), jumpzero.c_str ()))
    {
        std::string instruction = foo[0];
        std::string total = instruction + " " + foo[1] + " ?";
        i_buff->add_instruction(total);
       // int location = inst_buffer.size();
      //cout << "jumpzero is present." << endl;
        instCount++;
    }
  else if (strstr (foo[0].c_str (), jumpnzero.c_str ()))
    {
        std::string instruction = foo[0];
        std::string total = instruction + " " + foo[1] + " ?";
        i_buff->add_instruction(total);
        //int location = inst_buffer.size();
      //cout << "jumpnzero is present." << endl;
        instCount++;
    }
  else if (strstr (foo[0].c_str (), gosub.c_str ()))
    {
        std::string instruction = foo[0];
        std::string total = instruction + " " + foo[1] + " ?";
        i_buff->add_instruction(total);
        //int location = inst_buffer.size();
      //cout << "gosub is present." << endl;
        instCount++;
    }
  else if (strstr (foo[0].c_str (), return_str.c_str ()))
    {
        std::string instruction = foo[0];
        i_buff->add_instruction(foo[0]);
        
       // int location = inst_buffer.size();
        //leave subroutine so set scope back to zero
        //cout << "Exited the add_instruction command: Return" << endl;
        i_buff->update_buffer(symbol_table);
        //cout << "Exited the update_buffer command: Return" << endl;
        symbol_table->popScope();
       // cout << "Exited the popScope command: Return" << endl;
        i_buff->start_loc =1;
        symbol_table->scope = 0;
        instCount++;
        
      //cout << "return is present." << endl;
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
    }
    //cout << "End of file test" << endl;

    inFile.close();

    //Print String Buffer
//    for(int y = 0; y< stringBufferArr.size(); y++){
//        std::cout << stringBufferArr[y] << std::endl;
//    }
//    // printing Instruction Buffer
//    int ib_size = (int)i_buff->inst_buffer.size();
//    for(int z=0;z<ib_size; z++){
//        std::cout << i_buff->inst_buffer[z] << std::endl;
//    }
    std::string prefix = std::string(argv[1]);
    //std::string prefix = "test";
    // std::string outFileName = prefix + ".out";

    // std::ofstream outFile(outFileName);

    
    // outFile.write((char*) "test", sizeof(int));
    //outFile.write((char*)(&length), sizeof(int));
    // cout << "test" << endl;
    // outFile.open(outFileName);
    // outFile << "test" << endl;


        std::string binFileName = prefix + ".bin";
    ofstream my_file(binFileName, ios_base::binary);
        if (!my_file.is_open()) {
            cout << "error" << endl;
            
            
        }
        for (int i = 0; i < n; i++) {
            // If strings are null-terminated use +1 to separate them in file
            my_file.write(&str_array[i][0], str_array[i].length() + 1);
            // If strings aren't null-terminated write a null symbol after string
            // my_file.write("\0", 1);
        }
        my_file.close();
    return 0;
} 
