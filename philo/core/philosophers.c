/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:56:46 by biphuyal          #+#    #+#             */
/*   Updated: 2025/11/11 18:45:28 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void create_philisophers(t_philosophers *philosophers, char **argv)
{
	pthread_create(&philosophers, NULL, NULL, argv[3]);
	pthread_join(philosophers, NULL);
}

int main(int args, char **argv)
{
	pthread_t philosophers;
	
	if (!check_all_posibility(args, argv))
		return (1);
	create_philisophers(&philosophers, argv);
	
}