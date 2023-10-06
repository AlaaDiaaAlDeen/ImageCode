#include <stdlib.h>
#include <fstream>

#include "includes.h"

using namespace std;

AcquireHeuristics::AcquireHeuristics()
{}

AcquireHeuristics::~AcquireHeuristics()
{}

void AcquireHeuristics::acquireHeuristics(map<char, int>& _heuristics)
{
    ifstream file;
    file.open("heuristics.txt", ios::in);
    if(!file)
    {
        cout << "File couldn't be opened";
        return;
    }
    string line;
    char char1;
    int cost;

    file >> char1 >> cost;
    while(!file.eof())
    {
        _heuristics.insert(pair<char,int>(char1, cost)); //atoi()
        file >> char1 >> cost;
    }

    file.close();
}

void AcquireHeuristics::printList(map<char, int>& _heuristics)
{
    cout << endl << "Heuristics:\n\t";

    map<char,int>::iterator it;
    for(it = _heuristics.begin(); it != _heuristics.end(); it++)
    {
        cout << "Heuristic(" << it->first << ") = " << it->second << "\n\t";
    }
}
