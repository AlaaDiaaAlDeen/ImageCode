#include "includes.h"

Link::Link(char firstPoint, char secondPoint, int cost)
{
    this->firstPoint = firstPoint;
    this->secondPoint = secondPoint;
    this->cost = cost;
}

Link::~Link(){}

char Link::getFirstPoint()
{
    return this->firstPoint;
}


char Link::getSecondPoint()
{
    return this->secondPoint;
}

int Link::getCost()
{
    return this->cost;
}

