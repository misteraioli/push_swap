#######################################################
## ARGUMENTS

NAME 		=	push_swap

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
HEADER		=	-Iinc

SRC_DIR		=	src/
OBJ_DIR		=	obj/

LIB_PATH	=	./libft
LIB			=	-Llibft -lft

RM			=	rm -rf

#######################################################
## SRCS & OBJS

FILES		= \
			main \
			parsing \
			lst_utils \
			sort1 \
			sort2 \
			opti \
			instruc \

SRCS	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS	=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

#######################################################
## RULES

all : make_lib $(NAME)

make_lib :
		@make -C $(LIB_PATH)

$(NAME) : $(OBJS)
		$(CC) $(CFLAGS) $(HEADER) $(OBJS) $(LIB) -o $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJ_DIR)
		$(CC) $(CFLAGS) $(HEADER) -c $< -o $@

$(OBJ_DIR) :
		@mkdir -p $(OBJ_DIR)

norm :
	norminette libft inc src

clean :
		make -C $(LIB_PATH) fclean
		$(RM) $(OBJ_DIR)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
