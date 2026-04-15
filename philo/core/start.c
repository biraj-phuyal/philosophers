/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:21:40 by biphuyal          #+#    #+#             */
/*   Updated: 2026/04/15 17:12:31 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

static void	cleanup(t_philo *philosophers)
{
	int		i;
	t_data	*data;

	if (philosophers == NULL)
		return ;
	data = philosophers[0].data;
	if (data != NULL && data->forks != NULL)
	{
		i = 0;
		while (i < data->philo_count)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
	}
	free(data);
	free(philosophers);
}

static bool	init_forks(t_data *data)
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

static bool	init_data(char **argv, t_philo **philosophers)
{
	t_data	*data;
	int		i;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (false);
	data->philo_count = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->must_eat_count = -1;
	data->forks = NULL;
	if (argv[5] != NULL)
		data->must_eat_count = ft_atoi(argv[5]);
	*philosophers = malloc(sizeof(t_philo) * data->philo_count);
	if (*philosophers == NULL)
		return (free(data), false);
	if (!init_forks(data))
		return (free(*philosophers), free(data), false);
	i = 0;
	while (i < data->philo_count)
	{
		(*philosophers)[i].id = i + 1;
		(*philosophers)[i].meals_eaten = 0;
		(*philosophers)[i].thread = 0;
		(*philosophers)[i].left_fork = &data->forks[i];
		(*philosophers)[i].right_fork = \
			&data->forks[(i + 1) % data->philo_count];
		(*philosophers)[i].data = data;
		i++;
	}
	return (true);
}

static void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	(void)philo;
	return (NULL);
}

static bool	execute(t_philo *philosophers)
{
	int	i;
	int	created;

	created = 0;
	while (created < philosophers[0].data->philo_count)
	{
		if (pthread_create(&philosophers[created].thread, NULL,
				philo_routine, &philosophers[created]) != 0)
		{
			i = 0;
			while (i < created)
			{
				pthread_join(philosophers[i].thread, NULL);
				i++;
			}
			return (false);
		}
		created++;
	}
	i = 0;
	while (i < created)
	{
		if (pthread_join(philosophers[i].thread, NULL) != 0)
			return (false);
		i++;
	}
	return (true);
}

bool	start(char **argv, t_philo **philosophers)
{
	bool	result;

	if (!init_data(argv, philosophers))
		return (false);
	result = execute(*philosophers);
	cleanup(*philosophers);
	*philosophers = NULL;
	return (result);
}
