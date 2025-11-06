/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 00:04:57 by biphuyal          #+#    #+#             */
/*   Updated: 2025/11/06 00:12:54 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

bool	check_positiveness(char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while(argv[j])
	{
		while (argv[j][i])
		{
			if (argv[j][i] < 1)
			{
				write(1, "Arguments must be above 0\n", 24);
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
	if (args != 6)
	{
		write(1, "Only 5 arguments are accepted\n", 30);
			return (false);
	}
	return(true);
}