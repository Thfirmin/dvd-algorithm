NAME = dvd

SRC_DIR = src
INC_DIR = include

CXX = g++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = $(shell find $(SRC_DIR) -type f -name "*.cpp")

INC = $(shell find $(INC_DIR) -type d)

OBJ = $(SRC:.cpp=.o)

CXXFLAGS = $(foreach dir,$(INC),-I $(dir))

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
