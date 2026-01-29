/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:21:40 by biphuyal          #+#    #+#             */
/*   Updated: 2026/01/29 21:15:53 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

bool	make_data(t_philo **philosophers, char **argv)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(argv[1]))
		(*philosophers)[i].data = (*philosophers)->data;
}

bool	init_data(int args, char **argv, t_philo **philosophers)
{
	(*philosophers)->data = malloc(sizeof(t_data));
	if (!(*philosophers)->data)
		return (false);
	*philosophers = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!philosophers)
		return (free((*philosophers)->data), false);
	make_data(&philosophers, argv);
	(*philosophers)->data->philo = ft_atoi(argv[1]);
	(*philosophers)->data->death = ft_atoi(argv[2]);
	(*philosophers)->data->eaten = ft_atoi(argv[3]);
	(*philosophers)->data->sleep = ft_atoi(argv[4]);
	if (argv[5])
		(*philosophers)->data->must_eat = ft_atoi(argv[5]);
	else
		(*philosophers)->data->philo = -1;
	return (true);
}

bool mutex_initialization(t_philo **philo, int action)
{
	if ((*philo)->data->philo == 1)
		return (false);
	pthread_mutex_lock((*philo)->data->must_eat);
}

void	*eat_sleep_think(void *p)
{
	t_philo *philo;
    
    philo = *(t_philo **)p;
	if (!mutex_initialization(&philo, 1))
		return (NULL);
	
}

bool	execute(t_philo **philosophers, char **argv)
{
	int	i;

	i = -1;
	while (++i < ft_atoi(argv[1]))
	{
		if (!pthread_create(philosophers[i]->philo, NULL, eat_sleep_think, &philosophers[i]))
			return (false);
	}
	while (++i < ft_atoi(argv[1]))
	{
		if (!pthread_join(philosophers[i]->philo, NULL));
			return (false);
	}
	return (true);
}

bool	start(int args, char **argv, t_philo **philosophers)
{	
	if (!init_data(args, argv, &philosophers))
		return (false);
	execute(philosophers, argv);
	return (true);
}