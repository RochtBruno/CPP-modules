NAME = span

CC = c++

SRC = main.cpp \
		Span.cpp \

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):
		@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf $(NAME)

fclean : clean

re: clean
	@make
