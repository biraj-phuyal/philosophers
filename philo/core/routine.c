/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:52:05 by biphuyal          #+#    #+#             */
/*   Updated: 2026/04/25 16:53:52 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	get_fork_order(t_philo *philo, pthread_mutex_t **first,
		pthread_mutex_t **second)
{
	if (philo->id % 2 == 0)
	{
		*first = philo->right_fork;
		*second = philo->left_fork;
		return ;
	}
	*first = philo->left_fork;
	*second = philo->right_fork;
}

static void	handle_single_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	ft_usleep(philo->data->time_to_die, philo->data);
	pthread_mutex_unlock(philo->left_fork);
}

static bool	take_forks(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	get_fork_order(philo, &first, &second);
	while (!simulation_stopped(philo->data))
	{
		pthread_mutex_lock(first);
		if (pthread_mutex_trylock(second) == 0)
		{
			print_status(philo, "has taken a fork");
			print_status(philo, "has taken a fork");
			return (true);
		}
		pthread_mutex_unlock(first);
		usleep(200);
	}
	return (false);
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

static long	get_think_time(t_philo *philo)
{
	long	remaining_time;

	remaining_time = philo->data->time_to_die;
	remaining_time -= philo->data->time_to_eat;
	remaining_time -= philo->data->time_to_sleep;
	return (remaining_time / 2);
}

static void	think_action(t_philo *philo)
{
	long	think_time;

	print_status(philo, "is thinking");
	if (philo->data->philo_count % 2 == 0)
		return ;
	think_time = get_think_time(philo);
	if (think_time > 0)
		ft_usleep(think_time, philo->data);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->philo_count == 1)
		return (handle_single_philo(philo), NULL);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_to_eat / 2, philo->data);
	while (!simulation_stopped(philo->data))
	{
		if (!take_forks(philo))
			break ;
		eat_action(philo);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		if (simulation_stopped(philo->data))
			break ;
		print_status(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep, philo->data);
		think_action(philo);
	}
	return (NULL);
}
