NAME = phonebook

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = PhoneBook.cpp \
	Contact.cpp \
	main.cpp

OBJDIR = Objects

OBJ = $(SRC:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean: 
	@rm -rf $(OBJDIR)
	@echo "Objects cleaned"

fclean: clean
	@rm -rf $(NAME)
	@echo "phonebook cleaned"

re: fclean all