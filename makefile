SRCS = *.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Werror -Wextra -Wall -O3

LIB_FLAGS = -lmlx -lft

PATH1 = minilibx_opengl_20191021/

PATH2 = minilibx_mms_20191025_beta/

PATH3 = libft/

LIB3 = libft.a

LIB1 = libmlx.a

LIB2 = libmlx.dylib

NAME = cub3d

RM = rm -f

$(NAME):
			cd $(PATH1) && make && mv $(LIB1) .. && cd ..
			cd $(PATH2) && make && mv $(LIB2) .. && cd ..
			cd $(PATH3) && make && mv $(LIB3) .. && cd ..
			gcc $(FLAGS) $(SRCS) -L. $(LIB_FLAGS) -o $(NAME)

all:		$(NAME)

clean:
			cd $(PATH1) && make clean && cd ..
			cd $(PATH2) && make clean && cd ..
			cd $(PATH3) && make clean && cd ..
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME) $(LIB1) $(LIB3)

re:			fclean all

.PHONY:		all clean fclean re
