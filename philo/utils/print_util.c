/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:52:05 by biphuyal          #+#    #+#             */
/*   Updated: 2026/04/21 17:27:39 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>
#include <stdio.h>

static long	get_timestamp(t_philo *philo)
{
	return (get_time_ms() - philo->data->start_time);
}

void	print_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print_lock);
	if (!simulation_stopped(philo->data))
	{
		printf("%ld %d died\n", get_timestamp(philo), philo->id);
		set_simulation_stop(philo->data, true);
	}
	pthread_mutex_unlock(&philo->data->print_lock);
}

void	print_status(t_philo *philo, const char *status)
{
	pthread_mutex_lock(&philo->data->print_lock);
	if (!simulation_stopped(philo->data))
		printf("%ld %d %s\n", get_timestamp(philo), philo->id, status);
	pthread_mutex_unlock(&philo->data->print_lock);
}
