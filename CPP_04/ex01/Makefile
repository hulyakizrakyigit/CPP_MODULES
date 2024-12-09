CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Brain

SRCS = main.cpp ./src/Animal.cpp ./src/Dog.cpp ./src/Cat.cpp ./src/WrongAnimal.cpp ./src/WrongCat.cpp ./src/Brain.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
