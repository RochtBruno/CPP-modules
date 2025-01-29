NAME = harl

CXX = g++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp \
	Harl.cpp \

OBJ_DIR = objects
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "Build complete!"

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compiled $< into $@"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Object files cleaned!"

fclean: clean
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)  # Garantir que o diretório seja removido, independentemente de conter arquivos
	@echo "Executable and object directory removed!"

re: fclean all
