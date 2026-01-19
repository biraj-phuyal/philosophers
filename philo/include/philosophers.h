/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:34:59 by biphuyal          #+#    #+#             */
/*   Updated: 2026/01/19 17:08:06 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>
# include <pthread.h>

typedef struct	s_ms t_ms;

typedef struct	s_data
{
	pthread_t		*fork;
	pthread_t		*eat;
	pthread_t		*sleep;
	void			*time_to_eat;
	void			*time_to_sleep;
	void			*time_to_think;
	int				must_eat;
	
}	t_data;

typedef struct	s_philo
{
	t_data		*data;
	pthread_t	thread;
}	t_philo;

bool	check_all_posibility(int args, char **argv);
bool	start(int args, char **argv, t_philo **philo);

#endif