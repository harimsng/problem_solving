NAME	= word_flip2

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) word_flip2.c -o $@
	bash test.sh

clean:
	rm -f $(NAME)

.PHONY: clean 
