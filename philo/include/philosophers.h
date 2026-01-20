/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:34:59 by biphuyal          #+#    #+#             */
/*   Updated: 2026/01/20 18:58:56 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>
# include <pthread.h>
# include <stdlib.h>

typedef struct	s_ms t_ms;

typedef struct	s_data
{
	size_t			eaten;
	size_t			philo;
	size_t			sleep;
	size_t			think;
	size_t			death;
	size_t			must_eat;
}	t_data;

typedef struct s_mutex
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*must_eat;
	pthread_mutex_t	*last_meal_time;
}	t_mutex;

typedef struct	s_philo
{
	t_data		*data;
	t_mutex		*mutex;
	pthread_t	*philo;
}	t_philo;

bool	check_all_posibility(int args, char **argv);
bool	start(int args, char **argv, t_philo **philo);

#endif