#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include <iostream>
using std::string;

class Component {
private:
    string label;
public:
    Component(string componentLabel){
        label = componentLabel;
    }
    virtual bool getOutput() = 0;
    virtual void prettyPrint(string padding);
};
#endif // COMPONENT_H
