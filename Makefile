# params
NAME		=	fdf
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-Iinclude -Ilib/mlx
LIBS		=	-Llib/mlx -lmlx_Linux -lm -lX11 -lXext

# files
SRC_DIR		=	src/
SRC_FILES	=	main

SRCS 	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))

OBJS	=	$(SRCS:.c=.o)



%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):$(OBJS)
	@make -C lib/mlx
	@echo "MLX|	compiled ✅"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "FdF|	compiled ✅"

all:	$(NAME)

clean:
	@make clean -C lib/mlx
	@echo "MLX|	Make clean ✅"
	@rm -f $(OBJS)
	@echo "FdF|	Cleaned ✅"

fclean:	clean
	@rm -f $(NAME)
	@echo "FdF|	Executable cleaned ✅"

re:		fclean all

.PHONY: all clean fclean re