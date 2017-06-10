#ifndef OUTPUT_H
#define OUTPUT_H
#include "ChainableComponent.h"

class Output : public ChainableComponent {
public:
    Output(string outputName) : ChainableComponent(outputName){}
    bool getOutput();
};

#endif // OUTPUT_H
