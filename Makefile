NAME = philosopher

src = philo/main.c philo/utils.c philo/philo.c

obj = $(src:.c=.o)

hd = philo/philo.h

flags = -Wall -Wextra -Werror -g

cc = cc

all: $(NAME)

$(NAME): $(src) $(obj) $(hd)
	$(cc) $(flags) $(src) -o $(NAME)

%.o : %.c
	$(cc) $(flags) -c $< -o $@

clean:
	rm -rf $(obj)

fclean: clean
	rm -rf $(NAME)

re: fclean all