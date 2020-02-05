#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int 	g_count = 1;

int 	main(void)
{
	int 						q;
	map<vector<string>, int>	buses;

	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		int n;
		vector<string> stops;

		cin >> n;
		for (int j = 0; j < n; ++j)
		{
			string s;

			cin >> s;
			stops.push_back(s);
		}
		if (!buses.count(stops))
		{
			buses[stops] = g_count++;
			cout << "New bus ";
		}
		else
			cout << "Already exists for ";
		cout << buses[stops] << endl;
	}
	return (0);
}