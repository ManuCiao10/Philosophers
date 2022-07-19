/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:45:53 by eardingh          #+#    #+#             */
/*   Updated: 2022/07/18 16:47:11 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_philo(t_philo *philo, t_data *data)
{
	pthread_mutex_t	*chopstick;
	int				i;

	i = -1;
	chopstick = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->num_philo);
	while (++i < data->num_philo)
		if (pthread_mutex_init(&chopstick[i], NULL) != 0)
			return (1);
	init_struct_philo(philo, data, chopstick);
	return (0);
}

void	init_struct_philo(t_philo *philo, t_data *data, pthread_mutex_t *ch)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		philo[i].var = data;
		philo[i].id = i + 1;
		philo[i].chopstick = ch;
		philo[i].last_meal = 0;
		i++;
	}
}

int	init_thread(t_data *data, t_philo *philo)
{
	pthread_t	*people;
	int			i;
	int			j;

	i = -1;
	j = -1;
	printf("---------------------------Before Thread---------------------------\n");
	people = (pthread_t *)malloc(sizeof(pthread_t) * data->num_philo);
	while (++i < data->num_philo)
		pthread_create(&people[i], NULL, philosopher, philo + i);
	rules(philo, data);
	while (++j < data->num_philo)
		pthread_join(people[j], NULL);
	return (0);
}

int	init_data(t_data *data, char **argv)
{
	data->num_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->time = timestamp();
	data->total_ate = 0;
	if (data->num_philo <= 0 || data->time_die <= 0 || data->time_eat <= 0
		|| data->time_sleep <= 0)
		return (1);
	if (argv[5])
	{
		data->must_eat = ft_atoi(argv[5]);
		if (data->must_eat <= 0)
			return (1);
	}
	return (0);
}
