# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asfletch <asfletch@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/13 11:42:13 by asfletch          #+#    #+#              #
#    Updated: 2024/04/16 08:44:28 by asfletch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

COLOUR_DEFAULT = \033[0m
COLOUR_BLACK = \033[0;30m
COLOUR_RED = \033[0;31m
COLOUR_GREEN = \033[0;32m
COLOUR_YELLOW = \033[0;33m
COLOUR_BLUE = \033[0;34m
COLOUR_MAGENTA = \033[0;35m
COLOUR_CYAN = \033[0;36m
COLOUR_WHITE = \033[0;37m
COLOUR_BOLD = \033[1m
COLOUR_UNDERLINE = \033[4m
COLOUR_END = \033[0m

NAME = libft.a

SRCS = strings/ft_substr.c strings/ft_strncmp.c strings/ft_strrchr.c \
	strings/ft_striteri.c strings/ft_strjoin.c strings/ft_strlcpy.c \
	strings/ft_strnstr.c strings/ft_strtrim.c strings/ft_strchr.c strings/ft_strlcat.c\
	strings/ft_strdup.c strings/ft_split.c strings/ft_strlen.c strings/ft_strmapi.c \
	strings/split_utils.c \

SRCS += mem_manip/ft_memchr.c mem_manip/ft_memcpy.c mem_manip/ft_memcmp.c \
	mem_manip/ft_memmove.c mem_manip/ft_memset.c \

SRCS +=	numbers/ft_atoi.c numbers/ft_isalnum.c numbers/ft_isdigit.c \

SRCS += to_write/ft_putchar_fd.c to_write/ft_putstr_fd.c to_write/ft_putendl_fd.c \
	to_write/ft_putnbr_fd.c

SRCS += convert/ft_tolower.c convert/ft_toupper.c convert/ft_itoa.c \

SRCS += is/ft_isalpha.c is/ft_isascii.c is/ft_isprint.c \

SRCS += alloc/ft_calloc.c alloc/ft_realloc.c \

SRCS += free/ft_freearr.c \

SRCS +=	ft_bzero.c \

SRCS +=	ft_printf/ft_printf.c ft_printf/printf_special.c ft_printf/printf_utils.c \
	ft_printf/custom_utils.c \

SRCS += get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
	get_next_line/get_next_line_bonus.c get_next_line/get_next_line_utils_bonus.c \

BONUS = linked_list/ft_lstadd_back.c linked_list/ft_lstadd_front.c linked_list/ft_lstlast.c \
	linked_list/ft_lstnew.c linked_list/ft_lstsize.c linked_list/ft_lstdelone.c \
	linked_list/ft_lstmap.c linked_list/ft_lstiter.c linked_list/ft_lstclear.c \
	linked_list/ft_lstnth.c\

BONUS_OBJS = $(BONUS:.c=.o)
CC = 	gcc
CFLAGS = -Wall -Wextra -Werror
OBJS = 	$(SRCS:.c=.o)
RM = 	rm -f

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)
		echo "$(COLOUR_MAGENTA)Libft compiled successfully!$(COLOUR_END)"

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
		rm -f $(NAME)
		echo "$(COLOUR_MAGENTA)$(COLOUR_UNDERLINE)Libft cleaned successfully!$(COLOUR_END)"

re:		fclean all

bonus: $(OBJS) $(BONUS_OBJS)
		ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re
