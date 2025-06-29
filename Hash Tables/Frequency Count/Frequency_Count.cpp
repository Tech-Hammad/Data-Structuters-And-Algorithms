#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string,int> umap;
    string input;
    ifstream fin;
    fin.open("file.txt");

    while (!fin.eof())
    {
        fin >> input;
        umap[input]++;
    }

    for (auto x : umap)
    {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}