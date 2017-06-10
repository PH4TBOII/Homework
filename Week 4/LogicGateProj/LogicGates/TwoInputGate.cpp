#include "TwoInputGate.h"


bool TwoInputGate::getOutput() {
    switch (gateType){

    case(OR) :
        if (input->getOutput() == 1 || input2->getOutput() == 1)
            return 1;
        else
            return 0;
        break;
    case(AND):
        if (input->getOutput() == 1 && input2->getOutput() == 1)
            return 1;
        else
            return 0;
        break;
    case(XOR):
        if (input->getOutput() == 1 && input2->getOutput() == 0)
            return 1;
        else if (input->getOutput() == 0 && input2->getOutput() == 1)
            return 1;
        else return 0;
        break;
    }
}


void TwoInputGate::setInput2(Component* inputLink){
    input2 = inputLink;
}



void TwoInputGate::prettyPrint(std::string padding) {
    ChainableComponent::prettyPrint(padding);
    if (input2 != NULL){
        std::cout << "---";
        Component::prettyPrint(padding);
    }
}
