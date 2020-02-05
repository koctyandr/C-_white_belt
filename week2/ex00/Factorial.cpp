int		Factorial(int a)
{
	if (a <= 0)
		return (1);
	return (a * Factorial(a - 1));
}
