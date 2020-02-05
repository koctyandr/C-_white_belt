#include <iostream>
#include <math.h>

using namespace std;

int		main(void)
{
	double a, b, c;
	double disc, x1, x2;

	cin >> a >> b >> c;
	if (a == 0)
	{
		if (b != 0)
			cout << -c/b;
	}
	else
	{
		if ((disc = b*b - 4*a*c) < 0)
			return (1);
		x1 = (-b + sqrt(disc))/(2*a);
		x2 = (-b - sqrt(disc))/(2*a);
		if (x1 == x2)
		{
			cout << x1;
			return (0);
		}
		cout << x1 << " " << x2;
	}
	return (0);
}

