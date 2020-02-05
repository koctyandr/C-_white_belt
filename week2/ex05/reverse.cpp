void	Reverse(vector<int>& v)
{
	vector<int> tmp;

	for (int i = v.size(); i; --i)
	{
		tmp.push_back(v[i - 1]);
	}
	v.clear();
	for (auto x : tmp)
		v.push_back(x);
}
