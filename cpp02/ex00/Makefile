CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = a.out

SOURCES = main.cpp Fixed.cpp

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