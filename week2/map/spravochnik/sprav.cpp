#include <map>
#include <string>
#include <iostream>

using namespace std;

void	dump(const map<string, string>& ctrs)
{
	if (ctrs.empty())
		cout << "There are no countries in the world";
	else
		for (const auto& country : ctrs)
		{
			cout << country.first << "/" << country.second << " ";
		}
	cout << endl;
}

void	about(map<string, string>& ctrs)
{
	string country;

	cin >> country;
	if (!ctrs.count(country))
		cout << "Country " << country << " doesn't exist" << endl;
	else
		cout << "Country " << country << " has capital " << ctrs[country] << endl;
}

void	rename(map<string, string>& ctrs)
{
	string old_country_name;
	string new_country_name;

	cin >> old_country_name >> new_country_name;
	if (!ctrs.count(old_country_name) || ctrs.count(new_country_name) || old_country_name == new_country_name)
		cout << "Incorrect rename, skip" << endl;
	else
	{
		cout << "Country " << old_country_name << " with capital " << ctrs[old_country_name]
		<< " has been renamed to " << new_country_name << endl;
		ctrs[new_country_name] = ctrs[old_country_name];
		ctrs.erase(old_country_name);
	}
}

void	change_capital(map<string, string>& ctrs)
{
	string country;
	string new_capital;

	cin >> country >> new_capital;
	if (!ctrs.count(country))
	{
		cout << "Introduce new country " << country << " with capital " << new_capital << endl;
		ctrs[country] = new_capital;
	}
	else if (ctrs[country] == new_capital)
		cout << "Country " << country << " hasn't changed its capital" << endl;
	else
	{
		cout << "Country " << country << " has changed its capital from " << ctrs[country] << " to " << new_capital << endl;
		ctrs[country] = new_capital;
	}
}

int		main(void)
{
	int					q;
	map<string, string>	ctrs;

	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		string str;

		cin >> str;
		if (str == "CHANGE_CAPITAL")
			change_capital(ctrs);
		else if (str == "RENAME")
			rename(ctrs);
		else if (str == "ABOUT")
			about(ctrs);
		else if (str == "DUMP")
			dump(ctrs);
	}
	return (0);
}