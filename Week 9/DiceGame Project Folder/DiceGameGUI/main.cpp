#include <iostream>
#include "ThreeDicePoker.h"
#include "Die.h"
#include "dialog.h"
#include <QApplication>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
using namespace std;


int main(int argc, char* argv[] )
{
    QApplication app(argc,argv);


    //create and show the interface
    Dialog engine;
    engine.show();























    return app.exec();
}
