CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = fragtrap

SOURCES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean $(TARGET)

.PHONY: all clean fclean re