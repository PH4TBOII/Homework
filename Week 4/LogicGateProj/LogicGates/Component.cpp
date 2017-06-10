#include "Component.h"
#include <iostream>
using std::string;

void Component::prettyPrint(string padding){
std::cout << padding << this->label
          << ":"     << this->getOutput()
          << std::endl;
}
