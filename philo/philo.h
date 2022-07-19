#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;

	int				total_ate;
	unsigned long	time;

}					t_data;

typedef struct s_philo
{
	t_data			*var;
	int				id;
	int				ate;
	pthread_mutex_t	*chopstick;
	unsigned long	last_meal;
}					t_philo;

int					exit_err(void);
int					exit_err2(void);
int					check_input(char **argv);
int					ft_atoi(const char *str);
int					init_data(t_data *data, char **argv);
int					init_philo(t_philo *philo, t_data *data);
void				*philosopher(void *num);
int					init_thread(t_data *data, t_philo *philo);
void				init_struct_philo(t_philo *philo, t_data *data,
						pthread_mutex_t *ch);
void				grab_chopstick(int p, int id, char *hand, t_philo *philo);
void				down_chopsticks(int c1, int c2, t_philo *philo);
unsigned long		timestamp(void);
unsigned long		real_time(t_philo *philo);
void				rules(t_philo *philo, t_data *data);

#endif