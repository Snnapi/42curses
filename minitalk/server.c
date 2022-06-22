/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:52:42 by yerkiral          #+#    #+#             */
/*   Updated: 2022/06/22 14:52:43 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_binary[8];

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		c = n + 48;
		write(1, &c, 1);
	}
}

void	put_bin(void)
{
	int	chr;
	int	index;
	int	two;

	chr = 0;
	index = 0;
	two = 1;
	while (index < 8)
	{
		if (g_binary[index] == '1')
			chr += two;
		two *= 2;
		index++;
	}
	write(1, &chr, 1);
}

void	set_bin(int bin, bool bit)
{
	if (bit)
		g_binary[bin - 1] = '1';
	else
		g_binary[bin - 1] = '0';
}

void	handle(int signal)
{
	static int	bin;

	if (!bin)
		bin = 1;
	if (signal == SIGUSR1)
	{
		set_bin(bin, false);
		bin++;
	}
	else if (signal == SIGUSR2)
	{
		set_bin(bin, true);
		bin++;
	}
	if (bin == 9)
	{
		put_bin();
		bin = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = &handle;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
