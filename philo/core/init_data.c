/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 17:25:00 by biphuyal          #+#    #+#             */
/*   Updated: 2026/04/24 18:23:04 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	set_data_values(t_data *data, char **argv)
{
	data->philo_count = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->must_eat_count = -1;
	data->start_time = 0;
	data->stop_simulation = false;
	data->forks = NULL;
	if (argv[5] != NULL)
		data->must_eat_count = ft_atoi(argv[5]);
}

static t_data	*create_data(char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	set_data_values(data, argv);
	if (!init_shared_mutexes(data))
		return (free(data), NULL);
	return (data);
}

static void	assign_philo(t_philo *philo, t_data *data, int i)
{
	philo->id = i + 1;
	philo->meals_eaten = 0;
	philo->last_meal_time = 0;
	philo->thread = 0;
	philo->left_fork = &data->forks[i];
	philo->right_fork = &data->forks[(i + 1) % data->philo_count];
	philo->data = data;
}

static bool	init_error(t_philo *philosophers, t_data *data)
{
	if (data->forks != NULL)
		destroy_forks(data);
	free(philosophers);
	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->state_lock);
	free(data);
	return (false);
}

bool	init_data(char **argv, t_philo **philosophers)
{
	t_data	*data;
	int		i;

	data = create_data(argv);
	if (data == NULL)
		return (false);
	*philosophers = malloc(sizeof(t_philo) * data->philo_count);
	if (*philosophers == NULL)
		return (init_error(*philosophers, data));
	if (!init_forks(data))
		return (init_error(*philosophers, data));
	i = 0;
	while (i < data->philo_count)
	{
		assign_philo(&(*philosophers)[i], data, i);
		i++;
	}
	if (!init_philo_mutexes(*philosophers, data->philo_count))
		return (init_error(*philosophers, data));
	return (true);
}
