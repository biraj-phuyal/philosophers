/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:52:05 by biphuyal          #+#    #+#             */
/*   Updated: 2026/04/17 17:52:05 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	lock_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken a fork");
}

static void	eat_action(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal_time = get_time_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meal_lock);
	print_status(philo, "is eating");
	ft_usleep(philo->data->time_to_eat, philo->data);
}

static bool	meals_complete(t_philo *philo)
{
	bool	complete;

	if (philo->data->must_eat_count < 0)
		return (false);
	pthread_mutex_lock(&philo->meal_lock);
	complete = philo->meals_eaten >= philo->data->must_eat_count;
	pthread_mutex_unlock(&philo->meal_lock);
	return (complete);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!simulation_stopped(philo->data) && !meals_complete(philo))
	{
		lock_forks(philo);
		eat_action(philo);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		if (simulation_stopped(philo->data) || meals_complete(philo))
			break ;
		print_status(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep, philo->data);
		print_status(philo, "is thinking");
	}
	return (NULL);
}
