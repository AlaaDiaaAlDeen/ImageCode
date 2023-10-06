#include "includes.h"

using namespace std;

List::List()
{}

List::List(Node* node)
{
    this->firstNode = node;
    this->lastNode = node;
}

List::~List()
{}

void List::printList()
{
    Node* tracer = firstNode;
    cout << "\nParent's name\t\tName\t\tCost";
    while(tracer != NULL){
        cout << "\n\t" << tracer->get_parent()->get_name() << "\t\t" << tracer->get_name() << "\t\t" << tracer->get_cost();
        tracer = tracer->get_next();
    }
}

void List::printResult(Node* tracer)
{
    int cost = tracer->get_cost();
    int counter = 0;
    string out="";
    while(tracer != NULL){
        if(tracer->get_explored())
            out += tracer->get_name();
        counter ++;
        tracer = tracer->get_parent();
    }
    cout << "\n\nSolution path: ";
    for(int i = out.length()-1; i > 0; i --){
        cout << out.at(i) << " -> ";
    }
    cout << out.at(0);
    cout << "\n\nPath cost: " << cost;
    cout << "\n\nNumber of expanded nodes: " << counter <<endl;
}

