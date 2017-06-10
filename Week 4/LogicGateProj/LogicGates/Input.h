#ifndef INPUT_H
#define INPUT_H
#include <string>
#include "Component.h"

using std::string;
class Input :public Component {
private:
    bool value;
public:
    Input(string inputName): Component(inputName){}
    void setValue(bool newValue);
    bool getOutput();
};


#endif // INPUT_H
