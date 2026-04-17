/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:36:25 by biphuyal          #+#    #+#             */
/*   Updated: 2026/04/17 17:36:25 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static bool	simulation_stopped(t_data *data)
{
	bool	stopped;

	pthread_mutex_lock(&data->state_lock);
	stopped = data->stop_simulation;
	pthread_mutex_unlock(&data->state_lock);
	return (stopped);
}

long	get_time_ms(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000L) + (current_time.tv_usec / 1000L));
}

void	ft_usleep(long duration_ms, t_data *data)
{
	long	start_time;

	start_time = get_time_ms();
	while (get_time_ms() - start_time < duration_ms)
	{
		if (data != NULL && simulation_stopped(data))
			break ;
		usleep(500);
	}
}
