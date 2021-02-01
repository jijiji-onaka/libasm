NAME = libasm.a

AS = nasm
ASFLAGS = -g -f macho64

CC = gcc
CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror

SRCS =	mandatory/ft_strlen.s \
		mandatory/ft_strcmp.s \
		mandatory/ft_strcpy.s \
		mandatory/ft_write.s \
		mandatory/ft_read.s \
		mandatory/ft_strdup.s \

INCULDES = includes

B_SRCS =	bonus/ft_list_push_front_bonus.s \
			bonus/ft_list_size_bonus.s \
			bonus/ft_list_remove_if_bonus.s \
			bonus/ft_list_sort_bonus.s \
			bonus/ft_atoi_base.s \

TEST_SRCS =	$(wildcard mandatory/test_srcs/*.c)
TEST_B_SRCS =	$(wildcard bonus/test_srcs/*.c) \

OBJS = $(SRCS:.s=.o)
B_OBJS = $(B_SRCS:.s=.o)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

bonus : $(OBJS) $(B_OBJS)
	ar rcs $(NAME) $(OBJS) $(B_OBJS)

%.o: %.s
	$(AS) $(ASFLAGS) $<

clean:
	rm -f $(OBJS) $(B_OBJS)

fclean: clean
	rm -f $(NAME) test
	rm -f libasm

re: fclean all
# @$(CC) -I$(INCLUDES) $(CFLAGS) $(TEST_SRCS) $(NAME) test_srcs/libft.a main.c -o libasm -fsanitize=address -g

test: all
	@$(CC) -I$(INCLUDES) $(CFLAGS) $(TEST_SRCS) $(NAME) main.c -o test
	@ echo "$(GREEN)Created exe file"
	@ echo "$(BOLD)Usage : ./test [No argument or function name]$(RESET)"
test_bonus: bonus
	$(CC) -I$(INCLUDES) $(CFLAGS) $(TEST_B_SRCS) $(NAME) main_bonus.c -o test
	@ echo "$(GREEN)Created exe file"
	@ echo "$(BOLD)Usage : ./test [No argument or function name]$(RESET)"

.PHONY: all clean fclean re test

RESET		= \033[0m
RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
MAGENT		= \033[0;35m
CYAAN		= \033[0;36m
WHITE		= \033[0;37m
B_RESET		= \033[0;49m
B_YELLOW	= \033[0;43m
B_CYAAN		= \033[0;46m
BOLD		= \033[1m
UNDER_LINE	= \033[0;4m
