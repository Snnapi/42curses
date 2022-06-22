/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerkiral <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 14:52:00 by yerkiral          #+#    #+#             */
/*   Updated: 2022/06/22 14:52:03 by yerkiral         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static size_t	check(size_t n, const char *nptr, int sign)
{
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = *nptr - '0' + (n * 10);
		nptr++;
	}
	return (n * sign);
}

int	ft_atoi(const char *nptr)
{
	size_t	n;
	int		sign;
	int		d;

	d = 0;
	sign = 1;
	n = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	while (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		d++;
		nptr++;
	}
	if (d > 1)
		return (n);
	n = check(n, nptr, sign);
	return (n);
}

void	send_chr(int chr, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (chr % 2)
		{
			kill(pid, SIGUSR2);
			usleep(150);
		}
		else
		{
			kill(pid, SIGUSR1);
			usleep(150);
		}
		chr /= 2;
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
		{
			write(1, "INVALID PID\n", 12);
			return (0);
		}
		while (argv[2][i])
		{
			send_chr((int)argv[2][i], pid);
			i++;
		}
	}
	else
		write(1, "USAGE: ./client ${PID} ${STRING}\n", 34);
	return (0);
}
