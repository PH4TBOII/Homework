#ifndef NOTGATE_H
#define NOTGATE_H
#include "ChainableComponent.h"
class NotGate : public ChainableComponent {
public:
    NotGate():ChainableComponent("NOT"){}
    bool getOutput();
};



#endif // NOTGATE_H
