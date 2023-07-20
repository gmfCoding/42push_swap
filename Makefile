SRCSF =	main.c operations.c node.c stack.c input.c verify.c \
	   	$(addprefix util/, tiny.c cost.c median.c median_util.c stats.c) \
	   	$(addprefix sort/, helm_sort.c least_sort.c) \
	   	$(addprefix ops/, push.c rev_rotate.c rotate.c swap.c extra.c)

OBJSF = $(patsubst %.c,%.o, $(SRCSF))

LIBSF = libft/libft.a

ifndef $(OS)
OS := $(shell uname)
endif

$(info Compiling for OS:$(OS))

DIRSRC = src/
DIROBJ = obj/
DIRINC = include/
DIRLIB = .lib/

# All relative to Makefile's folder
SRCS = $(patsubst %.c,$(DIRSRC)%.c, $(SRCSF))
OBJS = $(patsubst %.c,$(DIROBJ)%.o, $(SRCSF))
LIBS = $(patsubst %.a,$(DIRLIB)%.a, $(LIBSF))

# All headers files are a dependency, so if any changes there will a recompile
INCS = $(shell find $(DIRINC) -name "*.h")

LIB-I = $(patsubst %,-I%,$(dir $(LIBS)))
LIB-l = $(subst lib,-l,$(basename $(notdir $(LIBSF))))
LIB-L = $(patsubst %,-L$(DIRLIB)%, $(dir $(LIBSF)))

NAME = push_swap
CC = cc

WFLAGS = -Wall -Werror -Wextra
OFLAGS = $(DFLAGS) $(WFLAGS) $(LIB-I) -I$(DIRINC)
CFLAGS = $(DFLAGS) $(LIB-L) $(LIB-l)

ifeq ($(DEBUG),1)
OFLAGS += -g -fsanitize=address
CFLAGS += -g -fsanitize=address
endif

# RULES
all: $(NAME)

# OBJ TO PROJECT
$(NAME): $(LIBS) $(OBJS)
	@$(CC) $(OBJS) $(CFLAGS) -o $@

# SOURCE TO OBJ
$(OBJS): $(DIROBJ)%.o : $(DIRSRC)%.c $(INCS)
	@mkdir -p $(dir $@)
	-$(CC) $(OFLAGS) -o $@ -c $<

# COMPILE LIBS
$(LIBS):
	@-echo "\n${GREEN}Compiling ${BLUE}Libft: ${NC}"
	@-make -s -C $(dir $@) all bonus

# CLEANING
fclean: libclean clean
	-rm -f $(NAME)
	@-echo "${GREEN}DONE CLEANING!${NC}"

libclean:
	@-echo "\n${GREEN}Cleaning Libft${NC}"
	@-make -C .lib/libft fclean

clean:
	-rm -rf $(DIROBJ)

re: fclean all

.PHONY: all re fclean clean libclean

# COLORS
BLUE = \033[1;34m
CYAN = \033[1;36m
GREEN = \033[1;32m
NC = \033[0m
