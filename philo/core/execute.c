/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:25:00 by biphuyal          #+#    #+#             */
/*   Updated: 2026/04/17 17:25:00 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	(void)philo;
	return (NULL);
}

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

bool	execute(t_philo *philosophers)
{
	int	created;
	int	count;

	set_start_times(philosophers);
	created = 0;
	count = philosophers[0].data->philo_count;
	while (created < count)
	{
		if (pthread_create(&philosophers[created].thread, NULL,
				philo_routine, &philosophers[created]) != 0)
			return (join_threads(philosophers, created), false);
		created++;
	}
	join_threads(philosophers, count);
	return (true);
}
