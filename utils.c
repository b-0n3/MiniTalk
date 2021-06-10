#include  "utils.h"


void    ft_putstr(char *str)
{
    if (str != NULL)
    {
       ft_putchar(*str);
        while (*(str++) != '\0')
            ft_putchar(*str);
    }
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	unsigned int newvar;

	newvar = n;
	if (n < 0)
	{
		newvar = -n;
		ft_putchar('-');
	}
	if (newvar <= 9)
	{
		ft_putchar(newvar + 48);
	}
	if (newvar > 9)
	{
		ft_putnbr(newvar / 10);
		ft_putchar(newvar % 10 + 48);
	}
}

// void conver_and_print(char ch)
// {

// }