#ifndef RunStack_h
#define RunStack_h
#include <string>
#include <vector>

class RunStack {
    public:
        static RunStack* getInst();
        std::vector<int> run_stack;
        int getStackValue();
        void dup();
        void swap();
        void add();
        void negate();
        void mul();
        void div();
    private:
        RunStack();
        static RunStack* uniqueInstance;


};





#endif