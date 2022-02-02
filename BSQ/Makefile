NAME = BSQ 

SRC = ft_boite_outils.c ft_erreur.c ft_recup_map.c main.c ft_erreur_map.c

LIB = -L.

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Wextra -Werror

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

all: $(NAME)

clean:	
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
