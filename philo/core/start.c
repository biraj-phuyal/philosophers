/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:21:40 by biphuyal          #+#    #+#             */
/*   Updated: 2026/01/19 17:10:44 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

bool	init(int args, char **argv, t_philo **philo)
{
	
}

bool	start(int args, char **argv, t_philo **philo)
{
	if (!init(args, argv, philo))
		return (false);
	return (true);
}