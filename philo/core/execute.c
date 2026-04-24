/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:25:00 by biphuyal          #+#    #+#             */
/*   Updated: 2026/04/24 18:23:04 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	join_threads(t_philo *philosophers, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_join(philosophers[i].thread, NULL);
		i++;
	}
}

static void	set_start_times(t_philo *philosophers)
{
	int		i;
	long	start_time;

	start_time = get_time_ms();
	philosophers[0].data->start_time = start_time;
	i = 0;
	while (i < philosophers[0].data->philo_count)
	{
		philosophers[i].last_meal_time = start_time;
		i++;
	}
}

static int	create_threads(t_philo *philosophers)
{
	int	count;
	int	i;

	count = philosophers[0].data->philo_count;
	i = 0;
	while (i < count)
	{
		if (pthread_create(&philosophers[i].thread, NULL,
				philo_routine, &philosophers[i]) != 0)
			return (set_simulation_stop(philosophers[0].data, true), i);
		i++;
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
