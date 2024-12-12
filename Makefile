SRCS = main.c

OBJS = $(addprefix build/,$(SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

RM = rm -rf

LIBFT_DIR = libft
LIBFT_REPO = https://github.com/LauraNierobisch/libft.git
LIBFT_LIB = $(LIBFT_DIR)/libft.a

PUSHSWAP = build/push_swap

all: build $(LIBFT_LIB) $(PHILO)

build:
	@mkdir -p build

build/.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

$(PHILO): $(PUSH_OBJS) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) -o $@

$(LIBFT_LIB):
	@if [ ! -d $(LIBFT_DIR) ]; then \
		git clone $(LIBFT_REPO) $(LIBFT_DIR); \
	fi
	make -C $(LIBFT_DIR)

clean:
	$(RM) build
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(LIBFT_DIR)

re: fclean all
