# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asyed <asyed@student.42singapore.sg>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 17:36:21 by asyed             #+#    #+#              #
#    Updated: 2026/01/30 00:00:00 by asyed            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap

SRCS_PATH   = srcs
WASM_DIR    = wasm

RM          = rm -f
RM_RF       = rm -rf

SRCS        = push_swap.c \
              emit.c \
              allerrorcheck.c all_listfunctions.c allocate_stack.c \
              set_rank_in_stone.c find_index_median.c \
              sort_algorithm.c sort_two_and_three.c start_sorting_a.c \
              utils_push.c utils_swap.c utils_rotate.c utils_reverse_rotate.c \
              find_target_and_cost.c find_target.c calculate_cost.c \
              execute_move.c move_rank_one_up.c

# ---- Native build ------------------------------------------------------------

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -I.

OBJS        = $(SRCS:%.c=$(SRCS_PATH)/%.o)

$(SRCS_PATH)/%.o: $(SRCS_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(MAKE) -C libft
	@$(MAKE) -C ft_printf
	$(CC) $(CFLAGS) $(OBJS) ./libft/libft.a ./ft_printf/ft_printf.a -o $(NAME)

all: $(NAME)

# ---- WASM build --------------------------------------------------------------

EMCC        = emcc
EMAR        = emar
EMRANLIB    = emranlib

WASM_CFLAGS = $(CFLAGS) -DWASM

WASM_JS     = $(WASM_DIR)/push_swap.js
WASM_WASM   = $(WASM_DIR)/push_swap.wasm
MANIFEST    = $(WASM_DIR)/manifest.json

# wasm entry sources
WASM_SRCS_EXTRA = $(WASM_DIR)/wasm_entry.c $(WASM_DIR)/main_stub.c

# split obj dirs to avoid ambiguous pattern rules
WASM_OBJDIR_SRC   = $(WASM_DIR)/obj/srcs
WASM_OBJDIR_EXTRA = $(WASM_DIR)/obj/wasm

WASM_SRC_OBJS     = $(SRCS:%.c=$(WASM_OBJDIR_SRC)/%.o)
WASM_EXTRA_OBJS   = $(WASM_SRCS_EXTRA:$(WASM_DIR)/%.c=$(WASM_OBJDIR_EXTRA)/%.o)
WASM_OBJS         = $(WASM_SRC_OBJS) $(WASM_EXTRA_OBJS)

WASM_LIBFT   = ./libft/libft_wasm.a
WASM_PRINTF  = ./ft_printf/ft_printf_wasm.a


$(WASM_OBJDIR_SRC)/%.o: $(SRCS_PATH)/%.c
	@mkdir -p $(dir $@)
	$(EMCC) $(WASM_CFLAGS) -c $< -o $@

$(WASM_OBJDIR_EXTRA)/%.o: $(WASM_DIR)/%.c
	@mkdir -p $(dir $@)
	$(EMCC) $(WASM_CFLAGS) -c $< -o $@

# build wasm versions of libraries (must be incremental inside each lib)
# Build wasm versions of libraries (REAL file targets)
$(WASM_LIBFT):
	@$(MAKE) -C libft wasm CC=$(EMCC) AR=$(EMAR) RANLIB=$(EMRANLIB)

$(WASM_PRINTF):
	@$(MAKE) -C ft_printf wasm CC=$(EMCC) AR=$(EMAR) RANLIB=$(EMRANLIB)


# wasm main target (NOT phony)
.PHONY: wasm
wasm: $(WASM_JS) $(WASM_WASM) $(MANIFEST)

# link step creates BOTH .js and .wasm
$(WASM_JS): $(WASM_LIBFT) $(WASM_PRINTF) $(WASM_OBJS)
	@mkdir -p $(WASM_DIR)
	$(EMCC) $(WASM_CFLAGS) \
		$(WASM_OBJS) $(WASM_LIBFT) $(WASM_PRINTF) \
		-o $(WASM_JS) \
		-s MODULARIZE=1 \
		-s EXPORT_ES6=0 \
		-s ENVIRONMENT=web,node \
		-s EXPORTED_FUNCTIONS="['_wasm_entry','_malloc','_free','_main']" \
		-s EXPORTED_RUNTIME_METHODS="['UTF8ToString','stringToUTF8','lengthBytesUTF8']" \
		-s ERROR_ON_UNDEFINED_SYMBOLS=1

# emcc produces the .wasm as a side-effect of building the .js
$(WASM_WASM): $(WASM_JS)
	@true

$(MANIFEST): $(WASM_JS)
	@tmp=$$(mktemp); \
	printf '{\n' > $$tmp; \
	printf '  "schema": 1,\n' >> $$tmp; \
	printf '  "project": "push_swap",\n' >> $$tmp; \
	printf '  "artifact": "1.0.0",\n' >> $$tmp; \
	printf '  "js": "push_swap.js",\n' >> $$tmp; \
	printf '  "wasm": "push_swap.wasm",\n' >> $$tmp; \
	printf '  "entry": "wasm_entry"\n' >> $$tmp; \
	printf '}\n' >> $$tmp; \
	if [ -f $(MANIFEST) ] && cmp -s $$tmp $(MANIFEST); then rm -f $$tmp; \
	else mv $$tmp $(MANIFEST); fi


# ---- Cleaning ---------------------------------------------------------------

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C libft clean
	@$(MAKE) -C ft_printf clean

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C libft fclean
	@$(MAKE) -C ft_printf fclean

wasm_clean:
	$(RM) $(WASM_JS)
	$(RM) $(WASM_WASM)
	$(RM) $(MANIFEST)
	$(RM_RF) $(WASM_DIR)/obj

wasm_fclean: wasm_clean
	$(RM) $(WASM_DIR)/*.data $(WASM_DIR)/*.map

re: fclean all

# rebuild wasm from scratch
wasm_re: wasm_fclean wasm

.PHONY: all clean fclean re wasm_clean wasm_fclean wasm_re
