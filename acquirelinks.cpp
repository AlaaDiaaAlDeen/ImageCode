#include <stdlib.h>
#include <fstream>

#include "includes.h"

using namespace std;

AcquireLinks::AcquireLinks()
{}

AcquireLinks::~AcquireLinks()
{}

void AcquireLinks::acquireLinks(vector<Link>&_links)
{
    ifstream file;
    file.open("links.txt", ios::in);
    if(!file){
        cout << "File couldn't be opened";
        return;
    }
    string line;
    char char1, char2;
    int cost;

    file >> char1 >> char2 >> cost;
    while(!file.eof()){
        _links.push_back(Link(char1, char2, cost)); //atoi()
        file >> char1 >> char2 >> cost;
    }

    file.close();
}

void AcquireLinks::printList(vector<Link>&_links)
{
    cout << endl << "Links:\n\t";

    for(int i = 0; i < _links.size(); i++){
        cout << _links.at(i).getFirstPoint() << " " << _links.at(i).getSecondPoint() << " " << _links.at(i).getCost() << "\n\t";
    }
}
