NAME 		= so_long

CC 			= cc
RM			= rm -f

CFLAGS 		= -Wall -Wextra -Werror -g
CLINKS		= -ldl -lglfw -pthread -lm

MLX			= minilibx
LIBMLX 		= $(MLX)/libmlx42.a

FT			= libft
LIBFT		= $(FT)/libft.a

SRC 		= src/main.c\
			  ft_printf/ft_printf.c\
			  ft_printf/ft_printfaddon.c\
			  get_next_line/get_next_line.c\
			  get_next_line/get_next_line_utils.c


OBJ 		= $(SRC:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBMLX) $(LIBFT) $(OBJ)
	$(CC) -g -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX) $(CLINKS)

$(LIBMLX): $(MLX)
	cmake $(MLX) -B $(MLX)	
	$(MAKE) -C $(MLX)

$(LIBFT): $(FT)
	$(MAKE) -C $(FT)

$(MLX):
	git clone https://github.com/kodokaii/MLX42.git $(MLX)

$(FT):
	git clone https://github.com/Wizard232323/42-Libft.git $(FT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJ)
	$(MAKE) clean -C $(FT)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(LIBFT)
	$(RM) $(LIBMLX)

clear: fclean
	$(RM) -r $(FT)
	$(RM) -r $(MLX)

re: fclean all

.PHONY:		all bonus clean clear fclean re
