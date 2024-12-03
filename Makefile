#===CONFIGURATION===
NAME = libftprintf.a

SRC =\
	src/ft_sprintf.c\
	src/ft_dprintf.c\
	src/ft_printf.c\
	src/add_char.c\
	src/add_str.c\
	src/conversion_specification.c

CFLAGS = -Wall -Werror -Wextra -g3
LFLAGS = 

LIBS = \
	libft/libft.a\

INCLUDES = -Ilibft/ -I./

OBJ_DIR = obj

#===AUTOMATIC VARS===

OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(SRC))))

LIB_FLAGS = $(addprefix -L, $(dir $(LIBS))) $(addprefix -l, $(patsubst lib%.a, %, $(notdir $(LIBS))))

#===TARGETS===

all : $(NAME)

#===COMPILING===
$(OBJ_DIR) :
	$(shell mkdir -p $(OBJ_DIR))
$(OBJ_DIR)/%.o : %.c
	mkdir -p $(dir $@)
	cc $(CFLAGS) -o $@ -c $< $(INCLUDES)
%.a :
	make -C $(dir $@)

#===LINKING===
$(NAME) : $(OBJ_DIR) $(LIBS) $(OBJ)
	ar -crs $(LIBS) $(OBJ)
	cp ./libft/libft.a ./libftprintf.a

#===CLEAN===
clean :
	rm -rf $(OBJ_DIR) || true

#===FCLEAN===
fclean : clean
	rm -f $(NAME) $(NAME_BONUS) || true

#===RE===
re : fclean all

main: all
	cc main.c -w -g3 -Llibft/ -lft

.PHONY : re fclean clean all default bonus