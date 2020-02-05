set<string> BuildMapValuesSet(const map<int, string>& m)
{
	set<string> map_values;

	for (const auto& c : m)
		map_values.insert(c.second);
	return (map_values);
}
