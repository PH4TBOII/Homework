#include <iostream>
#include "Set.h"
#include <iostream>
using namespace std;

int main()
{
    Set<int> temp;
    temp.add(1);
    temp.add(2);
    temp.add(4);

    Set<int> temp2(temp);

    temp2.add(6);
    temp2.add(7);
    temp2.add(8);
}
