/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:34:59 by biphuyal          #+#    #+#             */
/*   Updated: 2025/11/06 00:13:03 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <sys/time.h>
# include <stdbool.h>
# include <pthread.h>

typedef struct	s_philosophers
{
	void	*fork;
	void	*eat;
	void	*sleeps;
	void	*thinks;
	void	*time_to_eat;
	void	*time_to_sleep;
	void	*time_to_think;
	pthread_t thread;
}	t_philosophers;

bool	check_args(int args);
bool	check_positiveness(char **argv);

#endif