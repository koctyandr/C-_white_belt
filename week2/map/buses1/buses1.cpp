#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct	s_bus
{
	string	bn;
	int 	num;
}				t_bus;

bool operator < (const t_bus& lhs, const t_bus& rhs)
{
	return lhs.num < rhs.num;
}

int g_count = 0;

void			all_buses(const map<t_bus, vector<string>>& bs)
{
	map<string, vector<string>> new_bs;
	if (bs.empty())
	{
		cout << "No buses" << endl;
		return ;
	}
	for (const auto& c : bs)
		new_bs[c.first.bn] = c.second;
	for (const auto& b : new_bs)
	{
		cout << "Bus " << b.first << ":";
		for (const auto& c : b.second)
			cout << " " << c;
		cout << endl;
	}
}

vector<t_bus>	find_bus(const map<t_bus, vector<string>>& bs, const string &stop)
{
	vector<t_bus> find;

	for (const auto& b : bs)
	{
		for (const auto& s : b.second)
		{
			if (s == stop)
			{
				find.push_back(b.first);
				break;
			}
		}
	}
	return (find);
}

void			stop_for_bus(const map<t_bus, vector<string>>& bs)
{
	string	bus;
	int 	flag;

	flag = 0;
	cin >> bus;
	for (const auto& b : bs)
	{
		if (b.first.bn == bus)
		{
			for (const auto& s : b.second)
			{
				vector<t_bus>	buses;

				buses = find_bus(bs, s);
				for (int i = 0; i < buses.size(); ++i)
					if (buses[i].bn == bus)
					{
						buses.erase(begin(buses) + i);
						break ;
					}
				cout << "Stop " << s << ":";
				if (buses.empty())
					cout << " no interchange";
				else
					for (const auto& c : buses)
						cout << " " << c.bn;
				cout << endl;
				flag = 1;
			}
			break;
		}
	}
	if (flag == 0)
		cout << "No bus" << endl;
}

void			buses_for_stop(const map<t_bus, vector<string>>& bs)
{
	string			stop;
	vector<t_bus>	find;

	cin >> stop;
	find = find_bus(bs, stop);
	if (find.empty())
		cout << "No stop";
	else
		for (const auto& c : find)
				cout << c.bn << " ";
	cout << endl;
}

void			new_bus(map<t_bus, vector<string>>& bs)
{
	t_bus			b;
	string			bus;
	vector<string>	stops;
	int 			stop_count;

	cin >> bus >> stop_count;
	for (int i = 0; i < stop_count; ++i)
	{
		string stop;

		cin >> stop;
		stops.push_back(stop);
	}
	b.bn = bus;
	b.num = g_count++;
	bs[b] = stops;
}

int				main(void)
{
	int q;
	map<t_bus, vector<string>> bs;

	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		string str;

		cin >> str;
		if (str == "NEW_BUS")
			new_bus(bs);
		else if (str == "BUSES_FOR_STOP")
			buses_for_stop(bs);
		else if (str == "STOPS_FOR_BUS")
			stop_for_bus(bs);
		else if (str == "ALL_BUSES")
			all_buses(bs);
	}
	return (0);
}