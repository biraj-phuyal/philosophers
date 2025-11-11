/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:34:59 by biphuyal          #+#    #+#             */
/*   Updated: 2025/11/11 17:15:40 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>
# include <pthread.h>

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

bool	check_all_posibility(int args, char **argv);

#endif