#ifndef LIST_H
#define LIST_H

#include "includes.h"

class List
{
    public:
        List();
        List(Node*);
        ~List();

        Node* firstNode;
        Node* lastNode;

        void printList();
        void printResult(Node*);

    protected:
    private:

};

#endif // LIST_H
