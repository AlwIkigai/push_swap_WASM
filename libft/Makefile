# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asyed <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/14 12:07:44 by asyed             #+#    #+#              #
#    Updated: 2026/01/30 00:00:00 by asyed            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      ?= cc
AR      ?= ar
RANLIB  ?= ranlib

CFLAGS  = -Wall -Wextra -Werror -I.

NAME        = libft.a
WASM_NAME   = libft_wasm.a
WASM_OBJDIR = obj_wasm

SRC_FILES = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_toupper.c ft_tolower.c \
	ft_strlen.c ft_strlcpy.c ft_strlcat.c \
	ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c \
	ft_atoi.c ft_bzero.c ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_strdup.c ft_calloc.c ft_split.c \
	ft_strjoin.c ft_itoa.c ft_substr.c ft_strtrim.c \
	ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstclear.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
	ft_strcmp.c ft_atol.c

OBJ_FILES  = $(SRC_FILES:%.c=%.o)
WASM_OBJS  = $(SRC_FILES:%.c=$(WASM_OBJDIR)/%.o)

all: $(NAME)

# ---- Native build ------------------------------------------------------------

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	$(AR) rcs $(NAME) $(OBJ_FILES)
	$(RANLIB) $(NAME)

# ---- WASM build --------------------------------------------------------------

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
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re wasm wasm_clean
