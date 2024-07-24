NAME = libasm
NAMELIB = libasm.a

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -no-pie

NASM = nasm -g -F dwarf -f elf64
RM = rm -f

SRCS = ft_write/ft_write.s ft_read/ft_read.s ft_strlen/ft_strlen.s ft_strcmp/ft_strcmp.s ft_strcpy/ft_strcpy.s ft_strdup/ft_strdup.s

OBJ = $(SRCS:.s=.o)

all: $(NAME) libasmtest

$(NAME): $(OBJ)
	ar rcs $(NAMELIB) $(OBJ)

libasmtest: $(NAME)
	$(CC) $(CFLAGS) main.c $(NAMELIB) -o libasmtest

%.o: %.s
	$(NASM) -o $@ $<

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAMELIB)
	$(RM) libasmtest

re: fclean all

.PHONY: all libasmtest clean fclean re