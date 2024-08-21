

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = Zombie

SOURCES = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean $(TARGET)

.PHONY: all clean clean re