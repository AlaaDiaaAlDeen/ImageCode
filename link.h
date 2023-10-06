#ifndef LINK_H
#define LINK_H

#include "includes.h"

class Link
{
public:
    Link();
    Link(char, char, int);
    ~Link();

    char getFirstPoint();
    char getSecondPoint();
    int getCost();

protected:
private:
    char firstPoint;
    char secondPoint;
    int cost;
};

#endif // LINK_H
