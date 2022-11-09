#include <map>
#include <string>
#include "SymbolTable.h"
#include "TwoTuple.h"
#include <iostream>
 
SymbolTable* SymbolTable::uniqueInstance = nullptr;
 
SymbolTable::SymbolTable() {
    //symbol_table = new std::map<std::string, TwoTuple*>[2];
    //std::map<std::string, TwoTuple*> definedMap;
    //idx = 0;
    symbol_table[0] = makeMainScope();
    symbol_table[1] = makeSubScope();
 
}
 
SymbolTable* SymbolTable::makeSymbolTable( ) {
    if (uniqueInstance == nullptr) {
        uniqueInstance = new SymbolTable();
    }
    // scope = _scope;
    // if(scope == 0){
    //     makeMainScope();
    // }
    // else if (scope == 1){
    //     makeSubScope();
    // }
 
    return uniqueInstance;
}
TwoTuple* SymbolTable::getData(std::string key) {
//   if (!*symbol_table) {
//       return new TwoTuple(99999, 99999); // just an error value I picked
    TwoTuple* found = new TwoTuple(9999,9999);
        for (auto const& e : *symbol_table[scope]) {
            if (e.first == key) {
                found = e.second;
            }
        }
    return found;
    }
TwoTuple* SymbolTable::getLabel(std::string key) {
//   if (!*symbol_table) {
//       return new TwoTuple(99999, 99999); // just an error value I picked
    TwoTuple* found = new TwoTuple(9999,9999);
        for (auto const& e : *symbol_table[0]) {
            if (e.first == key) {
                found = e.second;
            }
        }
    return found;
    }
 
//void SymbolTable::insert(std::string key, TwoTuple* _data) {
//   definedMap.insert(std::pair<std::string, TwoTuple*>(key, _data));
//}
 
void SymbolTable::putEntry(std::string key, TwoTuple* datum) {
    if(scope == 0){
        main_scope->insert(std::pair<std::string, TwoTuple*>(key, datum));
    }
    else if (scope == 1){
        sub_scope->insert(std::pair<std::string, TwoTuple*>(key, datum));
    }
    }

void SymbolTable::makeLabel(std::string key, TwoTuple* datum){
    main_scope->insert(std::pair<std::string, TwoTuple*>(key, datum));
}
 
std::map<std::string, TwoTuple*>* SymbolTable::makeMainScope(){
    if(!main_scope){
        main_scope = new std::map<std::string, TwoTuple*>();
    }
    return main_scope;
}
 
std::map<std::string, TwoTuple*>* SymbolTable::makeSubScope(){
    if(!sub_scope){
        sub_scope = new std::map<std::string, TwoTuple*>();
    }
    return sub_scope;
}
 
void SymbolTable::popScope(){
    delete(sub_scope);
    scope = 0;
    makeSubScope();
}
int SymbolTable::getLengthVar(int _scope){
    //int x;
    TwoTuple* output;
    int sum = 0;
    bool otherLabel;
    bool anotherLabel;
    bool exitLabel;
    //std::cout << symbol_table[_scope] << std::endl;
    auto iter = symbol_table[_scope]->begin();
    while(iter != symbol_table[_scope]->end()){
        bool answer;
        std::string str1 = iter->first;
        std::string str2 = "L";
        std::string str3 = "label";
        std::string str4 = "FIB";
        std::string str5 = "EXIT";
        
        answer = strstr(str1.c_str(), str2.c_str());
        otherLabel = strstr(str1.c_str(), str3.c_str());
        anotherLabel = strstr(str1.c_str(), str4.c_str());
        exitLabel =strstr(str1.c_str(), str5.c_str());
        if (!answer || !otherLabel || !anotherLabel || exitLabel) {
            output = iter->second;
            sum += output->length;
        }
        iter++;
    }
    return sum;
}
//#endif /* SYMBOLTABLE_H_ */
