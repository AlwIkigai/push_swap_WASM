#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asyed <asyed@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/17 12:02:02 by asyed             #+#    #+#              #
#    Updated: 2026/01/30 00:00:00 by asyed            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC      ?= cc
AR      ?= ar
RANLIB  ?= ranlib

CFLAGS  = -Wall -Wextra -Werror -I.

NAME        = ft_printf.a
WASM_NAME   = ft_printf_wasm.a
WASM_OBJDIR = obj_wasm

SRCS = \
	ft_putchar_pf.c ft_putstr_pf.c ft_strlen_pf.c ft_putnbr_pf.c \
	ft_putunbr_pf.c ft_puthex_pf.c ft_voidptr_pf.c ft_printf.c

OBJS      = $(SRCS:%.c=%.o)
WASM_OBJS = $(SRCS:%.c=$(WASM_OBJDIR)/%.o)

all: $(NAME)

# ---- Native build ------------------------------------------------------------

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) rcs $(NAME) $(OBJS)
	$(RANLIB) $(NAME)

# ---- WASM build --------------------------------------------------------------

WASM_CFLAGS ?= $(CFLAGS) -DWASM

$(WASM_OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(WASM_CFLAGS) -c $< -o $@


wasm: $(WASM_NAME)

$(WASM_NAME): $(WASM_OBJS)
	$(AR) rcs $(WASM_NAME) $(WASM_OBJS)
	$(RANLIB) $(WASM_NAME)

wasm_clean:
	rm -rf $(WASM_OBJDIR) $(WASM_NAME)

# ---- Cleaning ----------------------------------------------------------------

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re wasm wasm_clean
