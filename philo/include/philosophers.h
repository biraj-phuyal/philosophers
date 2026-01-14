/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:34:59 by biphuyal          #+#    #+#             */
<<<<<<< Updated upstream
/*   Updated: 2025/11/11 17:15:40 by biphuyal         ###   ########.fr       */
=======
/*   Updated: 2026/01/14 20:21:25 by biphuyal         ###   ########.fr       */
>>>>>>> Stashed changes
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>
# include <pthread.h>

<<<<<<< Updated upstream
typedef long long t_ms;

typedef struct	s_philosophers
{
	void		*fork;
	void		*eat;
	void		*sleeps;
	void		*thinks;
	void		*time_to_eat;
	void		*time_to_sleep;
	void		*time_to_think;
	pthread_t	thread;
}	t_philosophers;
=======
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
>>>>>>> Stashed changes

bool	check_all_posibility(int args, char **argv);
int		start(int args, char **argv, t_philo **philo);

#endif