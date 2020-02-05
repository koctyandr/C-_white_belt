#include <set>
#include <string>
#include <iostream>

using namespace std;

int		main(void)
{
	int			n;
	set<string>	unique;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string s;

		cin >> s;
		unique.insert(s);
	}
	cout << unique.size();
	return (0);
}