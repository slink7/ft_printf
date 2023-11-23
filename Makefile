NAME = libftprintf.a

SRC_DIR = src
SRC = ft_printf.c
SRC_BONUS =

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(notdir $(basename $(SRC)))))
OBJ_BONUS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(notdir $(basename $(SRC_BONUS)))))

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(OBJ_DIR) :
	mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(OBJ_DIR)
	cc $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

clean :
	rm -rf $(OBJ_DIR) || true

fclean : clean
	rm $(NAME) || true

re : fclean all

MAIN : $(NAME)
	cc main.c -L. -lftprintf
	./a.out
	rm ./a.out