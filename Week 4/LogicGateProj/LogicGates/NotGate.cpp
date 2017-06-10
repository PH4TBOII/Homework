#include "NotGate.h"
#include <cassert>
bool NotGate::getOutput() {
    switch(input->getOutput()) {
    case 0 : return 1;
             break;
    case 1 : return 0;
             break;
    default: assert (input != nullptr);
    }
}
