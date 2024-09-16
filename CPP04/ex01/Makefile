# Name
NAME = I_dont_want_to_set_the_world_on_fire

# Sources and objects.
SRCS = Brain.cpp main.cpp Dog.cpp Cat.cpp Animal.cpp
OBJS = $(SRCS:.cpp=.o)

# Define all the compiling flags.
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

# Compile and create everything.
all: $(NAME)

# Compile the program with the objects.
$(NAME): $(OBJS)
	@$(CXX) $(OBJS) -o $@

# Won't run if the source files don't exist or are not modified.
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@echo "[INFO] Objects removed."

fclean: clean
	@rm -f $(NAME)
	@echo "[INFO] $(NAME) removed."

re: fclean all

.PHONY: all clean fclean re
