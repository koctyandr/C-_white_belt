#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct	s_days
{
	vector<vector<string>>	days;
	int						month;
	vector<int>				m;
}				t_days;

void	create_days(t_days& days)
{
	days.days.resize(31);
	days.m = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	days.month = 1;
}

void	add(t_days& days)
{
	int i;
	string s;

	cin >> i >> s;
	days.days[i - 1].push_back(s);
}

void	dump(t_days& days)
{
	int i;

	cin >> i;
	cout << days.days[i - 1].size();
	for (const auto& c : days.days[i - 1])
		cout << " " << c;
	cout << endl;
}

void	next(t_days& days)
{
	days.month == 12 ? (days.month = 1) : (days.month++);
	for (int i = days.m[days.month - 1]; i < 31; ++i)
	{
		days.days[days.m[days.month - 1] - 1].insert(
				end(days.days[days.m[days.month - 1] - 1]),
				begin(days.days[i]), end(days.days[i]));
		days.days[i].clear();
	}
}

int		main(void)
{
	int q;
	string str;
	t_days days;

	create_days(days);
	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		cin >> str;
		if (str == "ADD")
			add(days);
		else if (str == "DUMP")
			dump(days);
		else if (str == "NEXT")
			next(days);
	}
	return (0);
}
