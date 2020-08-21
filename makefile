SRCS = *.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Werror -Wextra -Wall -O3

LIB_FLAGS2 = -lmlx -framework OpenGL -framework Appkit

LIB_FLAGS = -lft

PATH1 = /usr/local/include

PATH2 = /usr/local/lib/

PATH3 = libft/

LIB3 = libft.a

NAME = cub3d

RM = rm -f

$(NAME):
			cd $(PATH3) && make && mv $(LIB3) .. && cd ..
			gcc $(FLAGS) -I $(PATH1) $(SRCS) -L. $(LIB_FLAGS) -L $(PATH2) $(LIB_FLAGS2) -o $(NAME)

all:		$(NAME)

clean:
			cd $(PATH3) && make clean && cd ..
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME) $(LIB1) $(LIB3)

re:			fclean all

.PHONY:		all clean fclean re
