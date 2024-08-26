CXX = cpp

CXXFALGS = -Wall -Wextra -Werror -std=c++98

TARGET = bureaucrat

SOURCES = main.cpp Bureaucrat.cpp

OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
        $(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

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