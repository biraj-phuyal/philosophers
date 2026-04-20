/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 09:40:00 by biphuyal          #+#    #+#             */
/*   Updated: 2026/04/20 09:40:00 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static bool	philo_is_full(t_philo *philo)
{
	bool	is_full;

	if (philo->data->must_eat_count < 0)
		return (false);
	pthread_mutex_lock(&philo->meal_lock);
	is_full = philo->meals_eaten >= philo->data->must_eat_count;
	pthread_mutex_unlock(&philo->meal_lock);
	return (is_full);
}

static bool	all_philos_full(t_philo *philosophers)
{
	int	count;
	int	index;

	count = philosophers[0].data->philo_count;
	index = 0;
	while (index < count)
	{
		if (!philo_is_full(&philosophers[index]))
			return (false);
		index++;
	}
	return (count > 0);
}

static bool	philo_died(t_philo *philo)
{
	long	last_meal;

	pthread_mutex_lock(&philo->meal_lock);
	last_meal = philo->last_meal_time;
	pthread_mutex_unlock(&philo->meal_lock);
	return (get_time_ms() - last_meal >= philo->data->time_to_die);
}

static bool	check_philos(t_philo *philosophers)
{
	int	count;
	int	index;

	count = philosophers[0].data->philo_count;
	index = 0;
	while (index < count)
	{
		if (philo_died(&philosophers[index]))
			return (print_death(&philosophers[index]), true);
		index++;
	}
	if (all_philos_full(philosophers))
		return (set_simulation_stop(philosophers[0].data, true), true);
	return (false);
}

bool	monitor_simulation(t_philo *philosophers)
{
	while (!simulation_stopped(philosophers[0].data))
	{
		if (check_philos(philosophers))
			return (true);
		usleep(500);
	}
	return (true);
}
