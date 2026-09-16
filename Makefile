NAME = libftprintf.a

SRC_DIR = src
INC_DIR = include

SRC = $(SRC_DIR)/ft_printf.c $(SRC_DIR)/ft_printf_utils.c $(SRC_DIR)/ft_printf_format.c

OBJ = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I$(INC_DIR)
AR = ar rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/ft_printf.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
