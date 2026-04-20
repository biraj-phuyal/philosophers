/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:34:59 by biphuyal          #+#    #+#             */
/*   Updated: 2026/04/17 16:41:42 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <sys/time.h>
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
	long			start_time;
	bool			stop_simulation;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	state_lock;
} 	t_data;

typedef struct s_philo
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_lock;
	t_data			*data;
} 	t_philo;

int		ft_atoi(const char *str);
long	get_time_ms(void);
void	ft_usleep(long duration_ms, t_data *data);
bool	simulation_stopped(t_data *data);
void	set_simulation_stop(t_data *data, bool value);
void	print_status(t_philo *philo, const char *status);
void	print_death(t_philo *philo);
bool	check_all_posibility(int args, char **argv);
void	cleanup(t_philo *philosophers);
bool	init_data(char **argv, t_philo **philosophers);
bool	init_forks(t_data *data);
bool	init_philo_mutexes(t_philo *philosophers, int count);
bool	init_shared_mutexes(t_data *data);
void	destroy_forks(t_data *data);
void	*philo_routine(void *arg);
bool	monitor_simulation(t_philo *philosophers);
bool	execute(t_philo *philosophers);
bool	start(char **argv, t_philo **philosophers);

#endif
