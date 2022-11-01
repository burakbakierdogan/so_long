# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/30 16:24:52 by berdogan          #+#    #+#              #
#    Updated: 2022/10/16 02:14:46 by berdogan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		:= clang
CFLAGS	:= -Wall -Werror -Wextra
RM		:= /bin/rm -f
NAME	:= libft.a
INCLUDE	:= libft.h
SRCS	:= ft_isascii.c ft_isprint.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
			ft_tolower.c ft_toupper.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
			ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
			ft_memset.c ft_bzero.c ft_memcpy.c ft_striteri.c ft_memmove.c \
			ft_memchr.c ft_memcmp.c ft_strdup.c ft_calloc.c ft_itoa.c \
			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_strmapi.c \
			ft_printf.c ft_itoa_base.c get_next_line.c get_next_line_utils.c \
			get_next_line_bonus.c get_next_line_utils_bonus.c ft_is_capital.c \
			ft_is_space.c ft_atoi_base.c ft_itoa_base_v2.c ft_max.c ft_revstr.c \
			ft_atoi_for_push_swap.c
SRCS_BONUS	:= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS	:= $(SRCS:.c=.o)
OBJS_BONUS	:= $(SRCS_BONUS:.c=.o)


all:		$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
			ar -rcs $(NAME) $(OBJS)
bonus:	$(NAME) $(OBJS_BONUS) $(INCLUDE)
		ar -rcs $(NAME) $(OBJS) $(OBJS_BONUS)
clean:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean
