/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:34:59 by biphuyal          #+#    #+#             */
/*   Updated: 2026/04/15 16:36:11 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdbool.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct s_data
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	pthread_mutex_t	*forks;
} 	t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
} 	t_philo;

int		ft_atoi(const char *str);
bool	check_all_posibility(int args, char **argv);
bool	start(char **argv, t_philo **philosophers);

#endif
