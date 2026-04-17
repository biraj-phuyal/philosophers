/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:25:00 by biphuyal          #+#    #+#             */
/*   Updated: 2026/04/17 17:25:00 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	destroy_meal_mutexes(t_philo *philosophers)
{
	int		i;
	t_data	*data;

	data = philosophers[0].data;
	i = 0;
	while (i < data->philo_count)
	{
		pthread_mutex_destroy(&philosophers[i].meal_lock);
		i++;
	}
}

void	cleanup(t_philo *philosophers)
{
	t_data	*data;

	if (philosophers == NULL)
		return ;
	data = philosophers[0].data;
	destroy_meal_mutexes(philosophers);
	if (data->forks != NULL)
		destroy_forks(data);
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->state_lock);
	free(data);
	free(philosophers);
}
