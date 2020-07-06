SRCS	= *.c

OBJS	= $(SRCS:.c=.o)

FLAGS	= -Werror -Wall -Wextra

NAME	= libft.a

RM		= rm -f

$(NAME):
		gcc $(FLAGS) -c $(SRCS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)

all:	$(NAME)

clean:
		$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean fclean re bonus
