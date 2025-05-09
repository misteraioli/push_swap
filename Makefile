#######################################################
## ARGUMENTS

# NAME

NAME	=	push_swap

# CC FLAG INC

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
INC		=	-Iinc

# SRC & OBJ DIR

SRC_DIR	=	src/
OBJ_DIR	=	obj/

# LIB

LIB_PATH	=	./libft
LIB			=	$(LIB_PATH)/libft.a

# RM

RM	=	rm -rf

# HEADERS

HEADER	=	inc/push_swap.h

#######################################################
## SRCS & OBJS

FILES	= \
		main \
		parsing \
		lst_utils \
		tercil \
		sort \
		opti \
		instruc \

SRCS	=	$(addprefix $(SRC_DIR), $(addsuffix .c, $(FILES)))
OBJS	=	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(FILES)))

#######################################################
## RULES

all : $(LIB) $(NAME)

$(LIB) :
		@make -C $(LIB_PATH)

$(NAME) : $(OBJ_DIR) $(OBJS) Makefile
		$(CC) $(CFLAGS) $(INC) $(OBJS) -o $(NAME) $(LIB)

$(OBJ_DIR) :
		@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADER)
		$(CC) $(CFLAGS) $(INC) -c $< -o $@

norm :
		norminette libft inc src

clean :
		@make -C $(LIB_PATH) fclean
		$(RM) $(OBJ_DIR)

fclean : clean
		$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re norm
