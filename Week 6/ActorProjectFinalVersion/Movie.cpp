#include "Movie.h"
#include <iostream>
#include <fstream>


Movie::Movie(){
title = "?";
actors = new Actor*[maxActors];
numActors = 0;
ifstream input("actors.txt");

if(!input.is_open()) {
    std::cout << "couldn't find the file";
    exit(0);
}

input >> maxActors;

}
Movie::Movie(string theTitle, int numberActors){
    title = theTitle;
    numActors = 0;
    actors = new Actor*[numberActors];
    maxActors = numberActors;
}
Movie::~Movie(){
    if (actors){
        delete[] actors;
    }
    cout << "deleting a movie" << endl;
}
void Movie::print(){
    cout << title << endl;

    for (int i = 0; i < numActors; i++){
       cout << actors[i]->getInfo() << endl;
    }
    cout << "" << endl;
}
void Movie::addActor(Actor *person){
    if (numActors < maxActors){
    this->actors[numActors] = person;
    numActors ++;
    }
    else
        cout << "can't add actor, too many already" << endl;
}
