#ifndef ACQUIREHEURISTICS_H
#define ACQUIREHEURISTICS_H


#include "includes.h"

class AcquireHeuristics
{
    public:
        AcquireHeuristics();
        ~AcquireHeuristics();
        void acquireHeuristics(map<char, int>&);
        void printList(map<char, int>&);
    protected:
    private:
};

#endif // ACQUIREHEURISTICS_H
