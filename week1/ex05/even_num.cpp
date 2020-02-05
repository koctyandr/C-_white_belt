#include <iostream>

using namespace std;

int		main(void)
{
	int a, b;
	int i;

	cin >> a >> b;
	i = --a;
	while (++i <= b)
	{
		if (!(i % 2))
		{
			cout << i;
			if (i != b && i != b - 1)
				cout << " ";
		}
	}
	return (0);
}
