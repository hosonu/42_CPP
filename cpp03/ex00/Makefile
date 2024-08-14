CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = claptrap

SOURCES = main.cpp ClapTrap.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean