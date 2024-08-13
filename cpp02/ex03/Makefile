CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = a.out

SOURCES = main.cpp Fixed.cpp Point.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean