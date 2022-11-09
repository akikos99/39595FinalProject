#ifndef SYMBOLTABLE_H_
#define SYMBOLTABLE_H_
 
#include <string>
#include "TwoTuple.h"
#include <map>
#include <vector>
 
class SymbolTable {
public:
   //SymbolTable(std::string _key, TwoTuple* _data);
    //SymbolTable();
   //virtual void insert(std::string key, TwoTuple* _data);
    //std::map<std::string, TwoTuple*> definedMap;
    static SymbolTable* makeSymbolTable( );
    std::map<std::string, TwoTuple*>* makeMainScope();
    std::map<std::string, TwoTuple*>* makeSubScope();
    TwoTuple* getData(std::string key);
    TwoTuple* getLabel(std::string key);
    void putEntry(std::string key, TwoTuple* datum);
    void makeLabel(std::string key, TwoTuple* datum);
    void popScope();
    int scope;
    int getLengthVar(int _scope);
private:
    SymbolTable();
   int position;
   int length;
    int idx;
    std::map<std::string, TwoTuple*>* main_scope = nullptr;
    std::map<std::string, TwoTuple*>* sub_scope = nullptr;
   // declare a std::map here that takes an int and a TwoTuple*
    std::vector<std::map<std::string, TwoTuple*>*> symbol_table = {main_scope, sub_scope};
    static SymbolTable* uniqueInstance;
    //make_shared<map<std::string, TwoTuple*>> mapDefined;
    
};
#endif /* SYMBOLTABLE_H_ */
