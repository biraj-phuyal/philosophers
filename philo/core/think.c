/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/25 22:33:30 by biphuyal          #+#    #+#             */
/*   Updated: 2026/04/25 22:34:26 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

long	get_think_time(t_philo *philo)
{
	long	remaining_time;

	remaining_time = philo->data->time_to_die;
	remaining_time -= philo->data->time_to_eat;
	remaining_time -= philo->data->time_to_sleep;
	return (remaining_time / 2);
}

void	think_action(t_philo *philo)
{
	long	think_time;

	print_status(philo, "is thinking");
	if (philo->data->philo_count % 2 == 0)
		return ;
	think_time = get_think_time(philo);
	if (think_time > 0)
		ft_usleep(think_time, philo->data);
}
