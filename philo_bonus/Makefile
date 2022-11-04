NAME = philo_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

BINC = philosopher_bonus.h

SRCBONUS =	philo_bonus.c\
			philo_utils_bonus.c

BOFILES = $(SRCBONUS:.c=.o)

all : $(NAME)

$(NAME) : $(BOFILES) $(BINC)
	$(CC)  $(CFLAGS) $(BOFILES) -o $(NAME)


clean :
	@-rm -rf *.o

fclean : clean
	@-rm -rf philo_bonus

re : fclean all
