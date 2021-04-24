NAME = libftprintf.a
HEADER = ft_printf.h
CFLAGS = -Wall -Wextra -Werror -c
CC = gcc
AR = ar rc
RM = rm -f

# BSRCS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
# 		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

SRCS = ft_itoa.c ft_printf_c.c ft_printf_i.c ft_printf_p.c ft_printf_s.c \
		ft_printf_u.c ft_printf_x.c ft_printf_utils.c ft_printf.c \
		ft_utils1.c ft_utils2.c ft_itoa_utils.c ft_printf_i_utils.c

OBJS = $(SRCS:.c=.o)
# BOBJS = $(BSRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

# bonus: $(BOBJS) $(OBJS)
# 	$(AR) $(NAME) $^

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BOBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
