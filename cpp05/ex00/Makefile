NAME = Bureaucrat

CC = c++

SRC = Bureaucrat.cpp \
		main.cpp

CFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME):
		@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@rm -rf $(NAME)

re: clean
	@make
