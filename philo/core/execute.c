/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:25:00 by biphuyal          #+#    #+#             */
/*   Updated: 2026/04/20 09:40:00 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	join_threads(t_philo *philosophers, int count)
{
	int	index;

	index = 0;
	while (index < count)
	{
		pthread_join(philosophers[index].thread, NULL);
		index++;
	}
}

static void	set_start_times(t_philo *philosophers)
{
	int		index;
	long	start_time;

	start_time = get_time_ms();
	philosophers[0].data->start_time = start_time;
	index = 0;
	while (index < philosophers[0].data->philo_count)
	{
		philosophers[index].last_meal_time = start_time;
		index++;
	}
}

static int	create_threads(t_philo *philosophers)
{
	int	count;
	int	index;

	count = philosophers[0].data->philo_count;
	index = 0;
	while (index < count)
	{
		if (pthread_create(&philosophers[index].thread, NULL,
				philo_routine, &philosophers[index]) != 0)
			return (set_simulation_stop(philosophers[0].data, true), index);
		index++;
	}
	return (count);
}

bool	execute(t_philo *philosophers)
{
	int	created;

	set_start_times(philosophers);
	created = create_threads(philosophers);
	if (created != philosophers[0].data->philo_count)
		return (join_threads(philosophers, created), false);
	monitor_simulation(philosophers);
	join_threads(philosophers, created);
	return (true);
}
