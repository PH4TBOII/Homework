#ifndef CHAINABLECOMPONENT_H
#define CHAINABLECOMPONENT_H
#include <Component.h>
class ChainableComponent : public Component {
protected:
    Component* input;
public:
    ChainableComponent(string componentLabel)
        :Component(componentLabel){}
    void setInput(Component* inputLink);
    void prettyPrint(string padding);
};

#endif // CHAINABLECOMPONENT_H
