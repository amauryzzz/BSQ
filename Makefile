##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## Makefile
##

NAME	= bsq

CC	= gcc -g

RM	= rm -f

SRCS	=	src/bsq.c\
		src/utility.c\
		src/parsing.c\
		src/algo.c\
		src/sub_functs.c\
		src/last_function.c

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/

CFLAGS += -W -Wall -Wextra

all: $(NAME)

$(NAME):	$(OBJS)
		$(CC) $(OBJS) -o $(NAME) $(CFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
