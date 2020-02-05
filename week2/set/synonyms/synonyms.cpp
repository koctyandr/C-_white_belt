#include <set>
#include <map>
#include <string>
#include <iostream>

using namespace std;

void	add(map<string, set<string>>& synonyms)
{
	string		word1, word2;

	cin >> word1 >> word2;
	synonyms[word1].insert(word2);
	synonyms[word2].insert(word1);
}

void	count(map<string, set<string>>& synonyms)
{
	int		count = 0;
	string	word;

	cin >> word;
	cout << synonyms[word].size() << endl;
}

void	check(map<string, set<string>>& synonyms)
{
	string		word1, word2;

	cin >> word1 >> word2;
	if (synonyms[word1].count(word2) || synonyms[word2].count(word1))
	{
		cout << "YES";
	}
	else
		cout << "NO";
	cout << endl;
}

int		main(void)
{
	int q;
	map<string, set<string>> synonyms;

	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		string s;

		cin >> s;
		if (s == "ADD")
			add(synonyms);
		else if (s == "COUNT")
			count(synonyms);
		else if (s == "CHECK")
			check(synonyms);
	}
	return (0);
}