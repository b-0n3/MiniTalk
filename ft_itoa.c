# include "utils.h"
static	int		taille(unsigned int nb)
{
	unsigned int	size;

	size = 0;
	while (nb >= 10)
	{
		nb /= 10;
		++size;
	}
	return (int)(size + 1);
}

char			*ft_itoa(int n)
{
	char			*tab;
	unsigned int	nb;
	unsigned int	i;
	unsigned int	size;

	if (n < 0)
		nb = n * -1;
	else
		nb = n;
	size = taille(nb);
	i = 0;
	tab = malloc(size + 1 + (n < 0 ? 1 : 0));
	if (tab == 0)
		return (0);
	if (n < 0 && (tab[i] = '-'))
		size++;
	i = size - 1;
	while (nb >= 10)
	{
		tab[i--] = (nb % 10 + 48);
		nb /= 10;
	}
	tab[i] = (nb % 10 + 48);
	tab[size] = '\0';
	return (tab);
}