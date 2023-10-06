#ifndef NODE_H
#define NODE_H


#include "includes.h"


using namespace std;

class Node
{
public:
    Node(Node*, char, int);
    Node(Node*, char, int, bool);
    Node(Node*, char, int, int);
    Node(Node*, char, int, int, bool);
    ~Node();

    static char initialCity, goalCity;

    void set_next(Node*);
    void set_explored(bool);

    Node* get_parent();
    char get_name();
    int get_cost();
    int get_heuristic();
    bool get_explored();
    Node* get_next();


    bool isGoal();

    void expand_Breadth(vector<Link>&, List*);
    void pushNodeToList_Breadth(List*, Node*);

    void expand_Cheapest(vector<Link>&, List*);
    void pushNodeToList_Cheapest(List*, Node*);
    static Node* findQualified_Cheapest(List*);

    void expand_Depth(vector<Link>&, List*);
    bool pushNodeToList_Depth(List*, Node*);

    void expand_Greedy(vector<Link>&, List*, map<char, int>&);
    void pushNodeToList_Greedy(List*, Node*);
    static Node* findQualified_Greedy(List*);

    void expand_A(vector<Link>&, List*, map<char, int>&);
    void pushNodeToList_A(List*, Node*);
    static Node* findQualified_A(List*);

protected:
private:
    Node* parent;
    char name;
    int cost;
    int heuristic;
    bool explored;
    Node* next;
};

#endif // NODE_H
