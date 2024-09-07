# Nome do executável
NAME = megaphone

# Compilador e flags
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Arquivos fonte
SRC = megaphone.cpp

# Arquivos objeto
OBJ = $(SRC:.cpp=.o)

# Regra padrão: compilar o programa
all: $(NAME)

# Regra para criar o executável
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# Regra para compilar os arquivos .cpp em .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza dos arquivos compilados
clean:
	rm -f $(OBJ)

# Limpeza completa, removendo também o executável
fclean: clean
	rm -f $(NAME)

# Recompilar tudo do zero
re: fclean all

# Indica que as regras 'clean', 'fclean' e 're' não são arquivos
.PHONY: all clean fclean re
