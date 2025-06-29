#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main()
{
    unordered_map<string,int> people;
    string name;

    people["Hammad"] = 25;
    people["Saad"] = 30;
    people["Abdullah"] = 22;

    cout << "Enter a name to search: ";
    cin >> name;

    if (people.find(name) != people.end()) 
    {
        cout << name << " is " << people[name] << " years old." << endl;
    }
    else
    {
        cout << "Not found." << endl;
    }

    return 0;
}
