#include "Page.h"

Page::Page()
{
    url = "";
    visits = 0;
    usedLinks = 0;
    links[3] = {nullptr};
}

Page::Page(string urlValue)

{
    url = urlValue;
    visits = 0;
    usedLinks = 0;
    links[3] = {nullptr};
}

string Page::getURL(){
    return this->url;
}

int Page::getNumLinks(){
    return usedLinks;
}

//cant get rng to work properly
Page* Page::getRandomLink(){
    int x = 0;
    x = (rand()% usedLinks);
    return this->links[x];
}

void Page::visit(){
    visits = visits + 1;
}

int Page::getNumVisits(){
    return visits;
}

void Page::addLink(Page* other){
    links[usedLinks] = other;
    usedLinks = usedLinks + 1;
}
