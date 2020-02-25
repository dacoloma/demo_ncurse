int		ft_power(int nb, int power)
{
	int result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	else
		result = nb * ft_power(nb, power - 1);
	return (result);
}