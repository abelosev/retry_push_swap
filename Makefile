NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
LIB		= libft/libft.a
INC	= -Iinc -Ilibft

SRCDIR = src/
OBJDIR = obj/

SRC		= main.c \
		find_node.c mini_sort.c \
		push.c reverse.c\
		rotate.c sort_5_utils.c \
		sort_radix.c \
		stack_create.c free.c \
		swap.c input_tab.c \
		stack_check.c

OBJ		= $(patsubst %.c, $(OBJDIR)/%.o, $(SRC))

all: $(NAME)

$(LIB) :
	make -C libft

$(NAME) : $(OBJ) $(LIB)
	$(CC) $(OBJ) $(LIB) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	@rm -rf $(OBJDIR)
	make clean -C libft

fclean: clean
	@rm -rf $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
