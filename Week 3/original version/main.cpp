#include <iostream>
#include "Page.h"
using namespace std;


int main()
{
    //setting up the 4 pages with the proper url
    Page p1 = Page("http://page1");
    Page p2 = Page("http://page2");
    Page p3 = Page("http://page3");
    Page p4 = Page("http://page4");
    Page* currentPage = &p1;

    // section adds links to pages
    p1.addLink(&p2);
    p1.addLink(&p3);
    p2.addLink(&p3);
    p3.addLink(&p1);
    p4.addLink(&p1);
    p4.addLink(&p3);
    int numberOfRuns = 10000;
    //run simulation 10,000 times
    for (int i = 0; i < numberOfRuns; i++){
        currentPage->visit();
        //decides if it will choose a link or new page
        if ((rand() & (99)) + 1 > 15) {
            currentPage = currentPage->getRandomLink();
        }
        else {
            //select a random page not following a link
            switch(rand()%3) {
            case(0):
            {
                currentPage = &p1;
            }
            case(1):
            {
                currentPage = &p2;
            }
            case(2):
            {
                currentPage = &p3;
            }
            case(3):
            {
                currentPage = &p4;
            }

            }
        }
    }

    cout << "Page 1: " << (static_cast<double>(p1.getNumVisits())*100/numberOfRuns) << "%" << endl
         << "Page 2: " << (static_cast<double>(p2.getNumVisits())*100/numberOfRuns) << "%" << endl
         << "Page 3: " << (static_cast<double>(p3.getNumVisits())*100/numberOfRuns) << "%" << endl
         << "Page 4: " << (static_cast<double>(p4.getNumVisits())*100/numberOfRuns) << "%" << endl;

    return 0;
}
