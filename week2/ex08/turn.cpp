#include <iostream>
#include <string>
#include <vector>

using namespace std;

int		print_worry(const vector<bool> turn)
{
	int worry;

	worry = 0;
	for (int i = 0; i < (int)turn.size(); ++i)
		worry += turn[i];
	return (worry);
}

void	command(const string& str, vector<bool>& turn)
{
	int index;

	cin >> index;
	if (str == "WORRY")
		turn[index] = 1;
	else if (str == "QUIET")
		turn[index] = 0;
	else if (str == "COME")
		turn.resize(turn.size() + index);
}


int		main(void)
{
	vector<bool> turn(0, 0);
	int n;
	string str;

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		if (str == "WORRY_COUNT")
			cout << print_worry(turn) << endl;
		else
			command(str, turn);
	}
	return (0);
}
