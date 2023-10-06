#include "includes.h"

#define DEBUG

using namespace std;

char Node::initialCity;
char Node::goalCity;

vector<Link> _links;
map<char, int> _heuristics;

void filesInput();
int input();
bool notExist(char);
void start(int);

int main()
{

    filesInput();
    int mode = input();
    start(mode);

    return 0;
}

void start(int mode)
{
    Node* tracer;
    switch(mode)
    {
    case 1:
    case 2:
    case 3:
        tracer = new Node(new Node(NULL,'-',0), Node::initialCity, 0, true);
        break;
    case 4:
    case 5:
        tracer = new Node(new Node(NULL,'-',0), Node::initialCity, 0, _heuristics.at(Node::initialCity), true);
        break;
    }

    List* _frontier = new List(tracer);

    while(!tracer->isGoal())
    {
        switch(mode)
        {
        case 1:
            tracer->expand_Breadth(_links, _frontier);
            tracer = tracer->get_next();
            break;
        case 2:
            tracer->expand_Cheapest(_links, _frontier);
            tracer = Node::findQualified_Cheapest(_frontier);
            break;
        case 3:
            tracer->expand_Depth(_links, _frontier);
            tracer = tracer->get_next();
            break;
        case 4:
            tracer->expand_Greedy(_links, _frontier, _heuristics);
            tracer = Node::findQualified_Greedy(_frontier);
            break;
        case 5:
            tracer->expand_A(_links, _frontier, _heuristics);
            tracer = Node::findQualified_A(_frontier);
            break;
        }
        tracer->set_explored(true);
    }

    _frontier->printResult(tracer);
}

void filesInput(){

    AcquireLinks aL;
    aL.acquireLinks(_links);
    //aL.printList(_links);

    AcquireHeuristics aH;
    aH.acquireHeuristics(_heuristics);
    //aH.printList(_heuristics);
}

int input()
{
    int mode(0);

    cout << "\n\t#1- Breadth First Algorithm"
         << "\n\t#2- Cheapest First Algorithm"
         << "\n\t#3- Depth First Algorithm"
         << "\n\t#4- Greedy Algorithm"
         << "\n\t#5- A* Algorithm\n"
         << "\nChoose an algorithm: ";
    cin >> mode;
    while(!cin || (mode < 1 || mode > 5))
    {
        cout << "\nEnter a vaild number: ";
        cin.clear();
        cin.ignore(5000, '\n');
        cin >> mode;
    }


    cout << "\nEnter the initial point: ";
    cin >> Node::initialCity;
    while(!cin || !isalpha(Node::initialCity) || notExist(Node::initialCity))
    {
        cout << "\nRenter the initial point: ";
        cin.clear();
        cin.ignore(5000, '\n');
        cin >> Node::initialCity;
    }

    cout << "\nEnter the goal point: ";
    cin >> Node::goalCity;
    while(!cin || !isalpha(Node::goalCity) || notExist(Node::goalCity))
    {
        cout << "\nRenter the goal point: ";
        cin.clear();
        cin.ignore(5000, '\n');
        cin >> Node::goalCity;
    }

    return mode;
}

bool notExist (char point)
{
    for(int i = 0; i < _links.size(); i++)
        if(_links.at(i).getFirstPoint() == point || _links.at(i).getSecondPoint() == point)
            return false;
    return true;
}
