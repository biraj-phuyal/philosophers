/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:25:00 by biphuyal          #+#    #+#             */
/*   Updated: 2026/04/24 18:07:58 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

bool	init_shared_mutexes(t_data *data)
{
	if (pthread_mutex_init(&data->print_lock, NULL) != 0)
		return (false);
	if (pthread_mutex_init(&data->state_lock, NULL) != 0)
	{
		pthread_mutex_destroy(&data->print_lock);
		return (false);
	}
	return (true);
}

bool	init_philo_mutexes(t_philo *philosophers, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (pthread_mutex_init(&philosophers[i].meal_lock, NULL) != 0)
		{
			while (i > 0)
			{
				i--;
				pthread_mutex_destroy(&philosophers[i].meal_lock);
			}
			return (false);
		}
		i++;
	}
	return (true);
}

bool	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->philo_count);
	if (data->forks == NULL)
		return (false);
	i = 0;
	while (i < data->philo_count)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			while (i > 0)
			{
				i--;
				pthread_mutex_destroy(&data->forks[i]);
			}
			free(data->forks);
			data->forks = NULL;
			return (false);
		}
		i++;
	}
	return (true);
}
