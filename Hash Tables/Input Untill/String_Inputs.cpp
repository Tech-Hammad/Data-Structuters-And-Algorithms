#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	string input;
	unordered_map<string, int> umap;

	while (input != "stop")
	{
		cout << "Input String: ";
		cin >> input;
		umap[input]++;
	}

	for (auto x : umap)
	{
		cout << x.first << " ------ " << x.second << "\n";
	}

	return 0;
}
