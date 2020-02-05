#include <locale>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string	tolower_string(string& s)
{
	for (auto& c : s)
		c = tolower(c);
	return (s);
}

int 	main(void)
{
	int n;

	cin >> n;

	vector<string> v(n);

	for (auto& x : v)
		cin >> x;
	sort(begin(v), end(v), [](string s1, string s2) { return (tolower_string(s1) < tolower_string(s2)); });
	for (const auto& x : v)
		cout << x << " ";
	return (0);
}