#include <vector>
#include <iostream>

using namespace std;

int			average(const vector<int>& days)
{
	int average;

	average = 0;
	for (auto x : days)
		average += x;
	average /= days.size();
	return (average);
}

vector<int>	num_over(const vector<int>& days)
{
	int	avrg;
	vector<int> num_over;

	avrg = average(days);
	for (int i = 0; i < (int)days.size(); ++i)
		if (days[i] > avrg)
			num_over.push_back(i);
	return (num_over);
}

int			main(void)
{
	vector<int>	days;
	vector<int> over;
	int			size;

	cin >> size;
	days.resize(size);
	for (int& x : days)
		cin >> x;
	over = num_over(days);
	cout << over.size() << endl;
	for (auto x : over)
		cout << x << " ";
	return (0);
}
