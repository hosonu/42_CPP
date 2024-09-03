CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = form

SOURCES = main.cpp Bureaucrat.cpp Form.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

re: fclean $(TARGET)

.PHONY: all clean fclean re