# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clbernar <clbernar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 18:21:02 by clbernar          #+#    #+#              #
#    Updated: 2023/05/26 18:29:26 by clbernar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		libft.a

CC				=		@cc
FLAGS			=		-Wall -Werror -Wextra -I.
AR				=		@ar rc
RM				=		@rm -f

HD_DIR			=		./Includes
HD				=		$(HD_DIR)/libft.h $(HD_DIR)/Get_next_line.h $(HD_DIR)/ft_printf.h

GNL_SRCDIR		=		./Get_Next_Line
FT_PRINTFDIR	=		./Ft_printf
LIBFT_SRCDIRC	=		./Lft

LIBFT_SRC		= $(LIBFT_SRCDIRC)/ft_atoi.c $(LIBFT_SRCDIRC)/ft_bzero.c $(LIBFT_SRCDIRC)/ft_calloc.c \
				$(LIBFT_SRCDIRC)/ft_isalnum.c $(LIBFT_SRCDIRC)/ft_isalpha.c $(LIBFT_SRCDIRC)/ft_isascii.c \
				$(LIBFT_SRCDIRC)/ft_isdigit.c $(LIBFT_SRCDIRC)/ft_isprint.c $(LIBFT_SRCDIRC)/ft_itoa.c \
				$(LIBFT_SRCDIRC)/ft_memchr.c $(LIBFT_SRCDIRC)/ft_memcmp.c $(LIBFT_SRCDIRC)/ft_memcpy.c \
				$(LIBFT_SRCDIRC)/ft_memmove.c $(LIBFT_SRCDIRC)/ft_memset.c $(LIBFT_SRCDIRC)/ft_putchar_fd.c \
				$(LIBFT_SRCDIRC)/ft_putendl_fd.c $(LIBFT_SRCDIRC)/ft_putnbr_fd.c $(LIBFT_SRCDIRC)/ft_putstr_fd.c \
				$(LIBFT_SRCDIRC)/ft_split.c $(LIBFT_SRCDIRC)/ft_strchr.c $(LIBFT_SRCDIRC)/ft_strdup.c \
				$(LIBFT_SRCDIRC)/ft_striteri.c $(LIBFT_SRCDIRC)/ft_strjoin.c $(LIBFT_SRCDIRC)/ft_strlcat.c \
				$(LIBFT_SRCDIRC)/ft_strlcpy.c $(LIBFT_SRCDIRC)/ft_strlen.c $(LIBFT_SRCDIRC)/ft_strmapi.c \
				$(LIBFT_SRCDIRC)/ft_strncmp.c $(LIBFT_SRCDIRC)/ft_strnstr.c $(LIBFT_SRCDIRC)/ft_strrchr.c \
				$(LIBFT_SRCDIRC)/ft_strtrim.c $(LIBFT_SRCDIRC)/ft_substr.c $(LIBFT_SRCDIRC)/ft_tolower.c \
				$(LIBFT_SRCDIRC)/ft_toupper.c

GNL_SRC			= $(GNL_SRCDIR)/get_next_line.c $(GNL_SRCDIR)/get_next_line_utils.c

FTPRINTF_SRC	= $(FT_PRINTFDIR)/ft_format_c.c $(FT_PRINTFDIR)/ft_format_di.c $(FT_PRINTFDIR)/ft_format_p.c \
				$(FT_PRINTFDIR)/ft_format_s.c $(FT_PRINTFDIR)/ft_format_u.c $(FT_PRINTFDIR)/ft_format_x.c \
				$(FT_PRINTFDIR)/ft_printf_utils.c $(FT_PRINTFDIR)/ft_printf.c $(FT_PRINTFDIR)/ft_stock_arg.c

SRCS			= $(LIBFT_SRC) $(GNL_SRC) $(FTPRINTF_SRC)

B_SRCS			= $(LIBFT_SRCDIRC)/ft_lstnew_bonus.c $(LIBFT_SRCDIRC)/ft_lstadd_front_bonus.c $(LIBFT_SRCDIRC)/ft_lstsize_bonus.c \
				$(LIBFT_SRCDIRC)/ft_lstlast_bonus.c $(LIBFT_SRCDIRC)/ft_lstadd_back_bonus.c $(LIBFT_SRCDIRC)/ft_lstdelone_bonus.c \
				$(LIBFT_SRCDIRC)/ft_lstclear_bonus.c $(LIBFT_SRCDIRC)/ft_lstiter_bonus.c $(LIBFT_SRCDIRC)/ft_lstmap_bonus.c\

OBJS			= $(SRCS:.c=.o)

B_OBJS			= $(B_SRCS:.c=.o)

all :			$(NAME)

$(NAME) :		$(OBJS)
				$(AR) $(NAME) $(OBJS)
				@ranlib $(NAME)

bonus :			$(B_OBJS)
				$(AR) $(NAME) $(B_OBJS)
				@ranlib $(NAME)

cc :
				$(CC) $(FLAGS) main.c -L. -lft

%.o :			%.c $(HD)
	 			$(CC) $(FLAGS) -I $(HD_DIR) -c $< -o $@

clean:
				$(RM) $(OBJS) $(B_OBJS)

fclean:			clean
	 			$(RM) $(NAME)

re:				fclean all

.PHONY :		re all fclean bonus clean
