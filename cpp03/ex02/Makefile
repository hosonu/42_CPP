CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = fragtrap

SOURCES = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean