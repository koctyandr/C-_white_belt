void	MoveStrings(vector<string>& v1, vector<string>& v2)
{
	for (int i = 0; i < (int)v1.size(); ++i)
		v2.push_back(v1[i]);
	v1.clear();
}
