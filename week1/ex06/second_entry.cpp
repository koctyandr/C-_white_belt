#include <iostream>
#include <string>
#include <vector>

using namespace std;

int		main(void)
{
	vector<int>	ind;
	string		str;

	cin >> str;
	for (int i = 0; i < (int)str.size(); ++i)
	{
		if (str[i] == 'f')
			ind.push_back(i);
	}
	if (ind.size() == 0)
		cout << -2;
	else if (ind.size() == 1)
		cout << -1;
	else
		cout << ind[1];
	return (0);
}	
