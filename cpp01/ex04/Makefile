CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = filesub

SOURCES = main.cpp Sed.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean