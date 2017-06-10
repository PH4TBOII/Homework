#include "ChainableComponent.h"
void ChainableComponent::setInput(Component* inputLink){
    input = inputLink;
}




void ChainableComponent::prettyPrint(string padding){
    Component::prettyPrint(padding);

    if (this->input != NULL) {
        std::cout << "---" ;
        input->prettyPrint(padding);
    }


}
