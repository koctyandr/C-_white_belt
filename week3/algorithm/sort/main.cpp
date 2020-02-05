#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int 	main(void)
{
	int n;
	vector<int> v;

	cin >> n;
	v.resize(n);
	for (auto& c : v)
	{
		cin >> c;
	}
	sort(begin(v), end(v), [](int x, int y) {	return (abs(x) < abs(y));});
	for (const auto& c : v)
		cout << c << " ";
	return (0);
}