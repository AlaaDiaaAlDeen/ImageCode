#include "includes.h"

Node::Node(Node* parent, char name, int cost)
{
    this->parent = parent;
    this->name = name;

    if(parent != NULL)
        this->cost = parent->cost + cost;
    else
        this->cost = cost;

    this->explored = false;
    this->next = NULL;
}
Node::Node(Node* parent, char name, int cost, bool explored):Node(parent, name, cost)
{

    this->explored = explored;
}
Node::Node(Node* parent, char name, int cost, int heuristic):Node(parent, name, cost)
{
    this->heuristic = heuristic;
}
Node::Node(Node* parent, char name, int cost, int heuristic, bool explored):Node(parent, name, cost, heuristic)
{
    this->explored = explored;
}

Node::~Node() {}

bool Node::isGoal()
{
    return this->name == Node::goalCity;
}

void Node::expand_Breadth(vector<Link>& _links, List* _frontier)
{
    for(int i = 0; i < _links.size(); i++)
        if(_links.at(i).getFirstPoint() == this->get_name() && _links.at(i).getSecondPoint() != this->parent->get_name())
            pushNodeToList_Breadth(_frontier, new Node(this, _links.at(i).getSecondPoint(), _links.at(i).getCost()));
        else if(_links.at(i).getSecondPoint() == this->get_name() && _links.at(i).getFirstPoint() != this->parent->get_name())
            pushNodeToList_Breadth(_frontier, new Node(this, _links.at(i).getFirstPoint(), _links.at(i).getCost()));
}

void Node::pushNodeToList_Breadth(List* _frontier, Node* newNode)
{
    Node* temp1 = _frontier->firstNode;
    Node* temp2 = _frontier->firstNode;
    while(temp1 != NULL)
    {
        if(temp1->get_name() == newNode->get_name())
            return;

        temp2 = temp2->get_next();
        temp1 = temp1->get_next();
    }
    _frontier->lastNode->next = newNode;
    _frontier->lastNode = newNode;
}

void Node::expand_Cheapest(vector<Link>& _links, List* _frontier)
{
    for(int i = 0; i < _links.size(); i++)
        if(_links.at(i).getFirstPoint() == this->get_name() && _links.at(i).getSecondPoint() != this->parent->get_name())
            pushNodeToList_Cheapest(_frontier, new Node(this, _links.at(i).getSecondPoint(), _links.at(i).getCost()));
        else if(_links.at(i).getSecondPoint() == this->get_name() && _links.at(i).getFirstPoint() != this->parent->get_name())
            pushNodeToList_Cheapest(_frontier, new Node(this, _links.at(i).getFirstPoint(), _links.at(i).getCost()));
}

void Node::pushNodeToList_Cheapest(List* _frontier, Node* newNode)
{
    Node* temp1 = _frontier->firstNode;
    Node* temp2 = _frontier->firstNode;
    while(temp1 != NULL)
    {
        if(temp1->get_name() == newNode->get_name())
            if(temp1->get_cost() > newNode->get_cost())
            {
                delete temp2->get_next();
                temp2->set_next(temp1->get_next());
                break;
            }
            else if(temp1->get_cost() <= newNode->get_cost())
                return;

        temp2 = temp2->get_next();
        temp1 = temp1->get_next();
    }

    _frontier->lastNode->next = newNode;
    _frontier->lastNode = newNode;
}

Node* Node::findQualified_Cheapest(List* _frontier)
{
    Node* tempNode = _frontier->firstNode;
    Node* minNode;
    int min;
    bool flag = false;
    do
    {
        if(!tempNode->get_explored())
            if(!flag)
            {
                min = tempNode->get_cost();
                minNode = tempNode;
                flag = true;
            }
            else if(tempNode->get_cost() < min)
            {
                min = tempNode->get_cost();
                minNode = tempNode;
            }
        tempNode = tempNode->get_next();

    }
    while(tempNode != NULL);

    return minNode;
}


void Node::expand_Depth(vector<Link>& _links, List* _frontier)
{
    bool toBreak = false;
    for(int i = 0; i < _links.size(); i++)
    {
        if(_links.at(i).getFirstPoint() == this->get_name() && _links.at(i).getSecondPoint() != this->parent->get_name())
            toBreak = pushNodeToList_Depth(_frontier, new Node(this, _links.at(i).getSecondPoint(), _links.at(i).getCost()));
        else if(_links.at(i).getSecondPoint() == this->get_name() && _links.at(i).getFirstPoint() != this->parent->get_name())
            toBreak = pushNodeToList_Depth(_frontier, new Node(this, _links.at(i).getFirstPoint(), _links.at(i).getCost()));

        if(toBreak)
            break;
    }
}

bool Node::pushNodeToList_Depth(List* _frontier, Node* newNode)
{
    Node* temp1 = _frontier->firstNode;
    Node* temp2 = _frontier->firstNode;
    while(temp1 != NULL)
    {
        if(temp1->get_name() == newNode->get_name())
            return false;

        temp2 = temp2->get_next();
        temp1 = temp1->get_next();

    }

    _frontier->lastNode->next = newNode;
    _frontier->lastNode = newNode;

    return true;
}

void Node::expand_Greedy(vector<Link>& _links, List* _frontier, map<char, int>& _heuristics) {
    for(int i = 0; i < _links.size(); i++)
    {
        if(_links.at(i).getFirstPoint() == this->get_name() && _links.at(i).getSecondPoint() != this->parent->get_name())
            pushNodeToList_Greedy(_frontier, new Node(this, _links.at(i).getSecondPoint(), _links.at(i).getCost(), _heuristics.at(_links.at(i).getSecondPoint())));

        else if(_links.at(i).getSecondPoint() == this->get_name() && _links.at(i).getFirstPoint() != this->parent->get_name())
            pushNodeToList_Greedy(_frontier, new Node(this, _links.at(i).getFirstPoint(), _links.at(i).getCost(), _heuristics.at(_links.at(i).getFirstPoint())));
    }
}

void Node::pushNodeToList_Greedy(List* _frontier, Node* newNode) {
    Node* temp1 = _frontier->firstNode;
    Node* temp2 = _frontier->firstNode;
    while(temp1 != NULL)
    {
        if(temp1->get_name() == newNode->get_name())
            return;

        temp2 = temp2->get_next();
        temp1 = temp1->get_next();

    }

    _frontier->lastNode->next = newNode;
    _frontier->lastNode = newNode;
}

Node* Node::findQualified_Greedy(List* _frontier) {
    Node* tempNode = _frontier->firstNode;
    Node* minNode;
    int min;
    bool flag = false;
    do
    {
        if(!tempNode->get_explored())
            if(!flag)
            {
                min = tempNode->get_heuristic();
                minNode = tempNode;
                flag = true;
            }
            else if(tempNode->get_heuristic() < min)
            {
                min = tempNode->get_heuristic();
                minNode = tempNode;
            }

        tempNode = tempNode->get_next();

    }
    while(tempNode != NULL);

    return minNode;
}


void Node::expand_A(vector<Link>& _links, List* _frontier, map<char, int>& _heuristics) {
    for(int i = 0; i < _links.size(); i++)
        if(_links.at(i).getFirstPoint() == this->get_name() && _links.at(i).getSecondPoint() != this->parent->get_name())
            pushNodeToList_A(_frontier, new Node(this, _links.at(i).getSecondPoint(), _links.at(i).getCost(), _heuristics.at(_links.at(i).getSecondPoint())));
        else if(_links.at(i).getSecondPoint() == this->get_name() && _links.at(i).getFirstPoint() != this->parent->get_name())
            pushNodeToList_A(_frontier, new Node(this, _links.at(i).getFirstPoint(), _links.at(i).getCost(), _heuristics.at(_links.at(i).getFirstPoint())));
}

void Node::pushNodeToList_A(List* _frontier, Node* newNode) {
    Node* temp1 = _frontier->firstNode;
    Node* temp2 = _frontier->firstNode;
    while(temp1 != NULL)
    {
        if(temp1->get_name() == newNode->get_name())
            if(temp1->get_cost() > newNode->get_cost())
            {
                delete temp2->get_next();
                temp2->set_next(temp1->get_next());
                break;
            }
            else if(temp1->get_cost() <= newNode->get_cost())
                return;

        temp2 = temp2->get_next();
        temp1 = temp1->get_next();

    }

    _frontier->lastNode->next = newNode;
    _frontier->lastNode = newNode;
}

Node* Node::findQualified_A(List* _frontier) {
    Node* tempNode = _frontier->firstNode;
    Node* minNode;
    int min;
    bool flag = false;
    do
    {
        if(!tempNode->get_explored())
            if(!flag)
            {
                min = tempNode->get_cost() + tempNode->get_heuristic();
                minNode = tempNode;
                flag = true;
            }
            else if((tempNode->get_cost() + tempNode->get_heuristic()) < min)
            {
                min = tempNode->get_cost() + tempNode->get_heuristic();
                minNode = tempNode;
            }

        tempNode = tempNode->get_next();

    }
    while(tempNode != NULL);

    return minNode;
}

void Node::set_explored(bool explored)
{
    this->explored = explored;
}

void Node::set_next(Node* next)
{
    this->next = next;
}

Node* Node::get_parent()
{
    return parent?this->parent:NULL;
}

char Node::get_name()
{
    return this->name;
}

int Node::get_cost()
{
    return this->cost;
}

int Node::get_heuristic()
{
    return this->heuristic;
}

bool Node::get_explored()
{
    return this->explored;
}

Node* Node::get_next()
{
    return this->next;
}



