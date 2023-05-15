# SOURCE FILES
SRCS = 	ft_printf.c \
		ft_putchar_sfd.c \
		ft_putstr_sfd.c	\
		ft_putnb_sfd.c \
		ft_puthex_sfd.c

# TARGET NAME AND VARIBLES
TEST = main
NAME = libftprintf.a

PRINTFH = ft_printf.h ft_lprintf.h

OBJDIR = obj/
CC = cc
WFLAGS = -Wall -Wextra -Werror
CFLAGS = $(WFLAGS) $(DFLAGS)

# OBJECT FILES
OBJ = $(patsubst %.c,$(OBJDIR)%.o, $(SRCS))

all: $(NAME)

# BUILD LIBRARY
$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "ar rcs $(NAME) ...\nPrintf libary generated!"

# COMPILE SOURCES
$(OBJDIR)%.o: %.c $(PRINTFH)
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled: $<"

# CLEANING
re: fclean all

fclean: clean mclean
	@echo "Full clean!"
	@-rm -f $(NAME)

fdclean: dclean fclean

dclean:
	@cd ../libft && make fclean

mclean:
	@-rm -f main.o

clean:
	@-rm -rf $(OBJDIR)
	@rm -rf ./libtmp

# BUILD MAIN.C TARGET
main: main.c $(NAME)
	$(CC) $< -o main.o $(NAME) $(CFLAGS)

# EXECUTE MAIN.O TARGET
run: main
	@echo "Executing main:\n"
	@./main.o
	@echo "\n\nEnd of program!"

.PHONY: clean fclean mclean $(NAME) all re main run libdeps debug
