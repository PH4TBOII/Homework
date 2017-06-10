#ifndef MOVIE_H
#define MOVIE_H
#include <string>
#include "Actor.h"

class Movie
{
public:
    Movie();
    Movie(string theTitle, int numberActors);
    ~Movie();
    void print();
    void addActor(Actor* person);
private:
    string title;
    Actor** actors;
    int numActors;
    int maxActors;
};

#endif // MOVIE_H
