/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-ham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 11:29:28 by aait-ham          #+#    #+#             */
/*   Updated: 2021/06/11 11:29:30 by aait-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig)
{
	static unsigned char	resutl;
	static int				power;

	resutl += (sig == SIGUSR1) << power;
	power++;
	if (power > 7)
	{
		if (resutl != 0)
			ft_putchar(resutl);
		resutl = 0;
		power = 0;
	}
}

int	main(void)
{
	const int	pid = getpid();

	ft_putstr("SERVER PID: ");
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
}
