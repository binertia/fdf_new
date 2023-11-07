NAME		=	fdf
GETN		=	get_next_line/
MLX			=	minilibx/
GETN_A		=	get_next_line/libgetn.a
MLX_A		=	minilibx/libmlx.a

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -Iincludes
RM			=	rm -rf

SRCS		=	fdf.c						\
				get_map.c					\
				list_utils.c				\
				valid_add_color.c			\

OBJS		=	$(SRCS:%.c=%.o)

.PHONY:			all clean fclean re

all:			$(NAME)

$(NAME):		$(OBJS)  $(GETN_A) $(MLX_A)
				@$(CC) $(CFLAGS) $(OBJS) -L$(GETN) -L$(MLX) -lgetn -lmlx -lm -o $(NAME) -framework OpenGL -framework AppKit
				@echo "Hello FDF"

$(GETN_A):
				@$(MAKE) -s -C $(GETN)
				@echo "GET_NEXT_LINE is ready"

$(MLX_A):
				@$(MAKE) -s -C $(MLX)
				@echo "MLX has join the chat"

del:
				@$(RM) $(OBJS)
				@echo "Kill object."

clean:			del
				@$(MAKE) clean -s -C $(GETN)
				@$(MAKE) clean -s -C $(MLX)

fclean:			del
				@$(MAKE) fclean -s -C $(GETN)
				@$(MAKE) clean -s -C $(MLX)
				@$(RM) $(NAME)
				@echo "Execution file has gone."

re:				fclean all
