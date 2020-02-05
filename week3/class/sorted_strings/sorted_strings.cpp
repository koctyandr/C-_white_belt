class SortedStrings {
public:
	void AddString(const string& s) {
		ss.push_back(s);
	}
	vector<string> GetSortedStrings() {
		sort(begin(ss), end(ss));
		return (ss);
	}
private:
	vector<string> ss;
};
