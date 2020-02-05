#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, int>	create_angr(const string& s)
{
	map<char, int>	angr;

	for (char c : s)
		++angr[c];
	return (angr);
}

int 			main(void)
{
	int		n;
	string	s[2];

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		map<char, int> angr[2];
		cin >> s[0] >> s[1];
		cout << (create_angr(s[0]) == create_angr(s[1]) ? "YES" : "NO") << endl;
	}
	return (0);
}