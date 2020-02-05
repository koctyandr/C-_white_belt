bool	IsPalindrom(string str)
{
	int size;

	size = str.size();
	for (int i = 0; i < size / 2; ++i)
		if (str[size - i - 1] != str[i])
			return (false);
	return (true);
}
