#ifndef ACQUIRELINKS_H
#define ACQUIRELINKS_H

#include "includes.h"

using namespace std;

class AcquireLinks
{
    public:
        AcquireLinks();
        ~AcquireLinks();
        void acquireLinks(vector<Link>&);
        void printList(vector<Link>&);
    protected:
    private:
};

#endif // ACQUIRELINKS_H
