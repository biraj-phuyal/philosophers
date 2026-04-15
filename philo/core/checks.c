/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:04:57 by biphuyal          #+#    #+#             */
/*   Updated: 2026/04/15 17:11:28 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

static bool	check_arg_count(int args)
{
	static const char	usage[] = "Usage: ./philo number_of_philosophers time_to_die "
		"time_to_eat time_to_sleep "
		"[number_of_times_each_philosopher_must_eat]\n";

	if (args != 5 && args != 6)
	{
		write(2, usage, sizeof(usage) - 1);
		return (false);
	}
	return (true);
}

static bool	check_positive_number(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (false);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	if (ft_atoi(str) <= 0)
		return (false);
	return (true);
}

bool	check_all_posibility(int args, char **argv)
{
	int	i;

	if (!check_arg_count(args))
		return (false);
	i = 1;
	while (i < args)
	{
		if (!check_positive_number(argv[i]))
		{
			write(2, "Arguments must be positive integers\n", 36);
			return (false);
		}
		i++;
	}
	return (true);
}
