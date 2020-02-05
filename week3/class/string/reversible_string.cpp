#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class ReversibleString
{
public:
	ReversibleString(){}
	ReversibleString(const string& str)
	{
		rev_str = str;
	}
	void	Reverse(void)
	{
		reverse(begin(rev_str), end(rev_str));
	}
	string	ToString() const
	{
		return (rev_str);
	}
private:
	string rev_str;
};
