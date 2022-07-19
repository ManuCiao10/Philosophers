/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eardingh <eardingh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:45:44 by eardingh          #+#    #+#             */
/*   Updated: 2022/07/19 11:10:27 by eardingh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philo;

	if (argc < 5 || argc > 6 || check_input(argv))
		return (exit_err());
	data = (t_data *)malloc(sizeof(t_data));
	if (init_data(data, argv))
		return (exit_err2());
	philo = (t_philo *)malloc(sizeof(t_philo) * data->num_philo);
	init_philo(philo, data);
	init_thread(data, philo);
	return (0);
}

void	*philosopher(void *num)
{
	t_philo	*philo;

	philo = (t_philo *)num;
	if (philo->id % 2 == 0)
		usleep(10);
	philo->last_meal = timestamp();
	while (1)
	{
		grab_chopstick(philo->id, philo->id - 1, "left", philo);
		grab_chopstick(philo->id, philo->id % philo->var->num_philo, "right",
				philo);
		printf("%lums Philosopher [%d] is eating 🍝\n", real_time(philo),
				philo->id);
		philo->ate++;
		if (philo->ate == philo->var->must_eat)
			philo->var->total_ate++;
		usleep(philo->var->time_eat * 1000);
		philo->last_meal = timestamp();
		down_chopsticks(philo->id - 1, philo->id % philo->var->num_philo,
				philo);
		printf("%lums Philosopher [%d] is sleeping 🛏️\n", real_time(philo),
				philo->id);
		usleep(philo->var->time_sleep * 1000);
		printf("%lums Philosopher [%d] is thinking 💭\n", real_time(philo),
				philo->id);
	}
	return (0);
}

/*
EATING:
If all philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies. [first if]
DIE:
If a philosopher didn’t start eating time_to_diemilliseconds 
since the beginning of their last meal or the beginning of 
the simulation, they die. [second if]
*/

void	rules(t_philo *philo, t_data *data)
{
	int	i;
	i = 0;
	while (1)
	{
		if(philo[i].var->total_ate == philo[i].var->num_philo)
			exit(0);
		if (timestamp() - philo[i].last_meal > (unsigned long)data->time_die)
		{
			usleep(1000);
			printf("%lums Philosopher [%d] died 💀\n", real_time(philo), philo->id);
			exit(0);
		}
		i = (i + 1) % data->num_philo;
		usleep(500);
	}
}

void	down_chopsticks(int c1, int c2, t_philo *philo)
{
	pthread_mutex_unlock(&philo->chopstick[c1]);
	pthread_mutex_unlock(&philo->chopstick[c2]);
}

void	grab_chopstick(int p, int id, char *hand, t_philo *philo)
{
	pthread_mutex_lock(&philo->chopstick[id]);
	printf("%lums Philosopher [%d] got %s chopstick 🥢\n", real_time(philo), p,
			hand);
}
