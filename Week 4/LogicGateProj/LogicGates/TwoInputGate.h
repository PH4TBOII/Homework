#ifndef TWOINPUTGATE_H
#define TWOINPUTGATE_H
#include "ChainableComponent.h"
#include <string>

//Supported operations
enum LogicOperation {OR, AND, XOR};

//Lookup table for names of operations:
//  LOGIC_LABELS[OR] --> "OR"
//  LOGIC_LABELS[AND] --> "AND"...
const std::string LOGIC_LABELS[] = {"OR", "AND", "XOR"};

class TwoInputGate : public ChainableComponent {
private:
    LogicOperation gateType;
    Component* input2;
public:
    TwoInputGate(LogicOperation gateOperator)
        :ChainableComponent(LOGIC_LABELS[gateOperator])
    {
        gateType = gateOperator;
    }


    void setInput2(Component* inputLink);
    void prettyPrint(string padding);
    bool getOutput();
};



#endif // TWOINPUTGATE_H
