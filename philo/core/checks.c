/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:04:57 by biphuyal          #+#    #+#             */
/*   Updated: 2026/01/19 17:05:00 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

bool	check_positiveness(int args, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while(j < args)
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] >= '1' && argv[j][i] <= '9')
			{
				write(1, "Arguments must be above 0\n", 26);
				return (false);
			}
			i++;
		}
		j++;
	}
	return (true);
}

bool	check_args(int args)
{
	if (args != 5 && args != 6)
	{
		write(1, "Too many or less argument\n", 30);
			return (false);
	}
	return(true);
}

bool	check_all_posibility(int args, char **argv)
{
	if (!check_positiveness(args, argv))
		return (false);
	if (!check_args(args))
		return (false);
	return (true);
}