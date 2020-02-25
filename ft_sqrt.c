#include "demo.h"

int				ft_sqrt(int nb)
{
	int		sqr_test;
	int		nb_return;

	nb_return = 0;
	sqr_test = 0;
	if (nb <= 0)
		return (0);
	while (nb_return < nb)
	{
		sqr_test++;
		nb_return = ft_power(sqr_test, 2);
	}
	if (nb_return == nb)
		return (sqr_test);
	return (0);
}
