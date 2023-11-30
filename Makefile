NAME 		= so_long

CC 			= cc
RM			= rm -f

#CFLAGS 		+= -Wall -Wextra -Werror -g
CLINKS		= -ldl -lglfw -pthread -lm

MLX			= minilibx
LIBMLX 		= $(MLX)/libmlx42.a

FT			= libft
LIBFT		= $(FT)/libft.a

SRC 		= src/main.c
OBJ 		= $(SRC:.c=.o)

all: $(NAME)

bonus: $(NAME)

$(NAME): $(LIBMLX) $(LIBFT) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(LIBMLX) $(CLINKS)

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

clea:n
	$(RM) $(LIBMLX)
	$(RM) $(LIBFT)
	$(RM) $(NAMiiiE)

clear: fclean
	$(RM) -r $(FT)
	$(RM) -r $(MLX) 

re: fclean all

.PHONY:		all bonus clear clean fclean re
