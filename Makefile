# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lnierobi <lnierobi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 10:34:37 by lnierobi          #+#    #+#              #
#    Updated: 2024/08/01 15:20:57 by lnierobi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHILO_SRCS	=	main.c parsing_input.c 

PUSH = $(PHILO_SRCS:.c=.o)
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g

RM		= rm -f


PHILO = philo


all: $(PHILO)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -g

$(PHILO): $(PUSH) $(LIBS)
		$(CC) $(CFLAGS) $(PUSH) $(LIBS) -o $(PHILO) -g

clean:
		$(RM) $(PUSH) $(SERVER_OBJS)

fclean: clean
		$(RM) $(PHILO) $(SERVER)

re:	fclean all