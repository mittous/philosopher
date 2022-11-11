
NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INC  = philosopher.h

SRC =	main_philo.c \
		philo_utils.c \
		philo_utils_1.c

SOFILES = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(SOFILES) $(INC)
	$(CC)  $(CFLAGS) $(SOFILES) -o $(NAME)

clean :
	@-rm -rf *.o

fclean : clean
	@-rm -rf philo
re : fclean all
