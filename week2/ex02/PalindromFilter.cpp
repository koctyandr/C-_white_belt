bool	IsPalindrom(string str)
{
	int size;

	size = str.size();
	for (int i = 0; i < size / 2; ++i)
		if (str[size - i - 1] != str[i])
			return (false);
	return (true);
}

vector<string>	PalindromFilter(vector<string> words, int minLength)
{
	for (int i = 0; i < (int)words.size(); ++i)
	{
		if ((int)words[i].size() < minLength || !IsPalindrom(words[i]))
			words.erase(words.begin() + i--);
	}
	return (words);
}
