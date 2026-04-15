/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:56:46 by biphuyal          #+#    #+#             */
/*   Updated: 2026/01/20 15:34:38 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	main(int args, char **argv)
{
	t_philo	*philosophers;

	philosophers = NULL;
	if (!check_all_posibility(args, argv))
		return (1);
	if (!start(argv, &philosophers))
		return (1);
	return (0);
}
