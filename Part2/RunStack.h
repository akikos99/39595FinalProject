#ifndef RunStack_h
#define RunStack_h
#include <string>
#include <vector>

class RunStack {
    public:
        static RunStack* getInst();
        std::vector<int> run_stack;
    private:
        RunStack();
        static RunStack* uniqueInstance;


};





#endif