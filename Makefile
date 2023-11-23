NAME = libftprintf.a

SRC_DIR = src
SRC = \
	ft_putchar.c\
	ft_putpercent.c\
	ft_putptr.c\
	ft_putnbr.c\
	ft_putunsigned.c\
	ft_puthexl.c\
	ft_putstr.c\
	ft_puthexu.c\
	ft_printf.c\
	ft_strlen.c\
	ft_putnbr_base.c
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
	cc -c main.c
	cc main.o -L. -lftprintf
	./a.out
	rm main.o
	rm ./a.out

GETSRC :
	find ./src -name "ft_*.c"