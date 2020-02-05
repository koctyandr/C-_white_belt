vector<int>	Reversed(const vector<int>& v)
{
	vector<int> reversed;

	for (int i = v.size(); i; --i)
		reversed.push_back(v[i - 1]);
	return (reversed);
}
