#include <map>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct s_person
{
	string fn;
	string ln;
};

bool	need_bracket(const vector<string>& v)
{
	for (const auto& c : v)
		if (v[0] != c)
			return (true);
	return (false);
}

string	printname(const vector<string>& name)
{
	string s;

	s += name[0];
	if (name.size() > 1)
	{
		if (need_bracket(name))
			s += " (";
		for (int i = 1; i < name.size(); ++i)
		{
			if (name[i] != name[i - 1])
			{
				s += name[i];
				if (i != name.size() - 1)
					s += ", ";
			}
		}
		if (need_bracket(name))
			s += ")";
	}
	return (s);
}

class Person {
public:
	Person(const string& first_name, const string& last_name, const int& age)
	{
		person[age] = {first_name, last_name};
		this->age = age;
	}
	void ChangeFirstName(int year, const string& first_name) {
		person[year].fn = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		person[year].ln = last_name;
	}
	string GetFullName(int year) const {
		vector<string> full_name(2);

		if (age > year)
			return ("No person");
		for (auto it = person.rbegin(); it != person.rend(); ++it)
			if (!it->second.ln.empty() && it->first <= year)
			{
				full_name[1] += it->second.ln;
				break ;
			}
		for (auto it = person.rbegin(); it != person.rend(); ++it)
			if (!it->second.fn.empty() && it->first <= year)
			{
				full_name[0] += it->second.fn;
				break ;
			}
		if (!full_name[0].empty() && !full_name[1].empty())
			return (full_name[0] + " " + full_name[1]);
		else if (!full_name[0].empty() && full_name[1].empty())
			return (full_name[0] + " with unknown last name");
		else if (full_name[0].empty() && !full_name[1].empty())
			return (full_name[1] + " with unknown first name");
		else
			return ("Incognito");
	}
	string GetFullNameWithHistory(int year) const {
		vector<vector<string>> name_history(2);

		if (age > year)
			return ("No person");
		for (auto it = person.rbegin(); it != person.rend(); ++it)
			if (!it->second.ln.empty() && it->first <= year)
				name_history[1].push_back(it->second.ln);
		for (auto it = person.rbegin(); it != person.rend(); ++it)
			if (!it->second.fn.empty() && it->first <= year)
				name_history[0].push_back(it->second.fn);
		if (name_history[0].empty() && name_history[1].empty())
			return ("Incognito");
		else if (!name_history[0].empty() && name_history[1].empty())
			return (printname(name_history[0]) + " with unknown last name");
		else if (name_history[0].empty() && !name_history[1].empty())
			return (printname(name_history[1]) + " with unknown first name");
		else
			return (printname(name_history[0]) + " " + printname(name_history[1]));
	}
private:
	map<int, s_person> person;
	int age;
};
