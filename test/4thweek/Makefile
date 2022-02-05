NAME	=	editor_2stacks

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

SRC		=	$(NAME).c

all: $(NAME)
	bash editor_2stacks_test.sh

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $@

clean:
	rm -f $(NAME)

.PHONY: clean
