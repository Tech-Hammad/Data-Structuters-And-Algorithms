#pragma once
#include <string>
using namespace std;

struct Node 
{
    string name;
    int Ranking;
    Node* leftChild;
    Node* rightChild;
};
