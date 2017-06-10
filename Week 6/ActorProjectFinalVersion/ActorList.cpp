#include "ActorList.h"
#include <iostream>
#include <fstream>

using namespace std;


ActorList::ActorList(){
    ifstream input("actors.txt");

    if(!input.is_open()) {
        cout << "couldn't find the file";
        exit(0);
    }

    input >> numActors;

    actors = new Actor[numActors];

    for (int i = 0; i < numActors; i++){
        string lastName;
        string firstName;
        int birthYear;
        input >> lastName >> firstName >> birthYear;
        actors[i] = Actor(firstName, lastName, birthYear);
    }

}
ActorList::~ActorList(){
    if(actors)
        delete actors;
    cout << "deleting an ActorList" << endl;
}
ActorList::ActorList(ActorList *otherList){
    numActors = otherList->numActors;
    actors = new Actor[numActors];

    for(int i = 0; i < numActors; i++){
        actors[i] = otherList->actors[i];
    }
}
Actor* ActorList::getActorByIndex(int n){
    return &this->actors[n-1];
}





