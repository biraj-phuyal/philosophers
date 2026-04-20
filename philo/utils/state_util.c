/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:52:05 by biphuyal          #+#    #+#             */
/*   Updated: 2026/04/17 17:52:05 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

bool	simulation_stopped(t_data *data)
{
	bool	stopped;

	pthread_mutex_lock(&data->state_lock);
	stopped = data->stop_simulation;
	pthread_mutex_unlock(&data->state_lock);
	return (stopped);
}

void	set_simulation_stop(t_data *data, bool value)
{
	pthread_mutex_lock(&data->state_lock);
	data->stop_simulation = value;
	pthread_mutex_unlock(&data->state_lock);
}
