# philosopher

[![eardingh's 42 stats](https://badge42.vercel.app/api/v2/cl4bi3xsw007609kvnmtrlu37/stats?cursusId=21&coalitionId=undefined)](https://github.com/JaeSeoKim/badge42)

### Overview

Here are the things you need to know if you want to succeed this assignment:
• One or more philosophers sit at a round table.
There is a large bowl of spaghetti in the middle of the table.
• The philosophers alternatively eat, think, or sleep.
While they are eating, they are not thinking nor sleeping;
while thinking, they are not eating nor sleeping;
and, of course, while sleeping, they are not eating nor thinking.
• There are also forks on the table. There are as many forks as philosophers.
• Because serving and eating spaghetti with only one fork is very inconvenient, a
philosopher takes their right and their left forks to eat, one in each hand.
• When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.
• Every philosopher needs to eat and should never starve.
• Philosophers don’t speak with each other.
• Philosophers don’t know if another philosopher is about to die.
• No need to say that philosophers should avoid dying

### Input

◦ number_of_philosophers: The number of philosophers and also the number
of forks.
◦ time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the simulation, they die.
◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.
◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
◦ number_of_times_each_philosopher_must_eat (optional argument): If all
philosophers have eaten at least number_of_times_each_philosopher_must_eat
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.

### Test

LazyPhilosophersTester :
./test.sh ../philosopher

5 800 200 200
no one should die
5 600 150 150
no one should die
4 410 200 200
no one should die
100 800 200 200
no one should die
105 800 200 200
no one should die
200 800 200 200
no one should die
1 800 200 200
a philo should die
4 310 200 100
a philo should die
4 200 205 200
a philo should die
5 800 200 200 7
no one should die, simulation should stop after 7 eats
4 410 200 200 10
no one should die, simulation should stop after 10 eats
-5 600 200 200
should error and not run (no crashing)
4 -5 200 200
should error and not run (no crashing)
4 600 -5 200
should error and not run (no crashing)
4 600 200 -5
should error and not run (no crashing)
4 600 200 200 -5
should error and not run (no crashing)

-TEST GREP
./philosopher 5 800 200 200 2 | grep "is eating"

### Link

–https://osandnetworkingcslab.wordpress.com/implementation-of-dining-philosophers-using-threads/ 
-https://pages.mtu.edu/~shene/NSF-3/e-Book/MUTEX/TM-example-philos-1.html 
-https://pages.mtu.edu/~shene/NSF-3/e-Book/index.html 
-https://docs.oracle.com/cd/E19205-01/820-0619/gepji/index.html 
-https://en.wikipedia.org/wiki/Dining_philosophers_problem 
-https://www.youtube.comwatchv=d9s_d28yJq0list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2 
-https://miro.com/app/board/o9J_l0AjIkc=/ 
-https://www.personal.kent.edu/~rmuhamma/OpSystems/Myos/threads.htm 
-http://www.csc.villanova.edu/~mdamian/threads/posixthreads.html
-https://stackoverflow.com/questions/3756323/how-to-get-the-current-time-in-milliseconds-from-c-in-linux
