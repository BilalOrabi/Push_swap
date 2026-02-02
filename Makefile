NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = main.c parse.c disorder.c index.c utils.c \
	op_push.c op_reverse.c op_rotate.c op_swap.c \
	sort_adaptive.c sort_complex.c sort_medium.c sort_simple.c sort_small.c \
	stack_helper.c stack_info.c stack_utilty.c sort_medium_utlis.c

OBJDIR = obj
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))

GREEN		= \033[0;32m
YELLOW		= \033[0;33m
BLUE		= \033[0;34m
RED			= \033[0;31m
RESET		= \033[0m

all: $(LIBFT) $(NAME)

$(LIBFT):
	@printf "$(YELLOW)Compiling libft...\n$(RESET)"
	@make -C $(LIBFT_DIR) --silent
	@printf "$(GREEN)libft compiled.\n$(RESET)"

$(NAME): $(OBJS)
	@printf "$(YELLOW)Building $(NAME)...\n$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft
	@printf "$(GREEN)$(NAME) built successfully.\n$(RESET)"

$(OBJDIR)/%.o: %.c push_swap.h
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJDIR)
	@make -C $(LIBFT_DIR) clean --silent
	@printf "$(RED)Cleaned object files.\n$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean --silent
	@printf "$(RED)Fully cleaned.\n$(RESET)"

re: fclean all

test: $(NAME)
	@printf "$(BLUE)═══ Testing with 5 numbers ═══\n$(RESET)"
	@ARG="4 67 3 87 23"; ./$(NAME) $$ARG | ./checker_os $$ARG
	@printf "$(BLUE)═══ Testing with 100 numbers ═══\n$(RESET)"
	@ARG=$$(shuf -i 0-999 -n 100 | tr '\n' ' '); \
	OPS=$$(./$(NAME) $$ARG | wc -l); \
	printf "$(YELLOW)Operations: $$OPS\n$(RESET)"; \
	./$(NAME) $$ARG | ./checker_os $$ARG

test500: $(NAME)
	@printf "$(BLUE)═══ Testing with 500 numbers ═══\n$(RESET)"
	@ARG=$$(shuf -i 0-9999 -n 500 | tr '\n' ' '); \
	OPS=$$(./$(NAME) $$ARG | wc -l); \
	printf "$(YELLOW)Operations: $$OPS\n$(RESET)"; \
	./$(NAME) $$ARG | ./checker_os $$ARG

bench: $(NAME)
	@printf "$(BLUE)═══ Benchmark Mode for 500 values ═══\n$(RESET)"
	@ARG=$$(shuf -i 0-999 -n 500 | tr '\n' ' '); \
	./$(NAME) --bench $$ARG 2>&1 | grep "\[bench\]"

.PHONY: all clean fclean re test test500 bench