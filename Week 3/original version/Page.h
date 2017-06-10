#ifndef PAGE_H
#define PAGE_H
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Page
{
private:
    string url = "";
    int visits = 0;
    Page* links[3] = {nullptr};
    int usedLinks = 0;
public:

    ///
    /// \brief Default Constructor for Page class
    ///
    Page();

    ///
    /// \brief 1 arg constructor for Page class
    /// \param urlValue sets the url of the Page
    ///
    Page(string urlValue);

    ///
    /// \brief gets the url of the page
    /// \return URL
    ///
    string getURL();

    ///
    /// \brief gets the number of links used by the Page
    /// \return int between 0 and 3
    ///
    int getNumLinks();

    ///
    /// \brief chooses a random link held by the given Page
    /// \return
    ///
    Page* getRandomLink();

    ///
    /// \brief adds a page pointer to the links array for a page
    /// \param page pointer
    ///
    void addLink(Page* other);

    ///
    /// \brief adds 1 to the visits counter
    ///
    void visit();

    ///
    /// \brief returns how many visits the page has
    /// \return
    ///
    int getNumVisits();
};



#endif // PAGE_H
