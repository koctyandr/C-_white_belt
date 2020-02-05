#include <iostream>
#include <vector>

using namespace std;

int		main(void)
{
	int a;
	vector<int> bin;

	cin >> a;
	for (; a; (a /= 2))
		bin.push_back(a % 2);
	for (int i = bin.size(); i; --i)
		cout << bin[i - 1];
	return (0);
}
