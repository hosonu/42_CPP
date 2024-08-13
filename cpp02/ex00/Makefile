CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = megaphone

SOURCES = megaphone.cpp

$(TARGET): $(SOURCES)
        $(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
        rm -f $(TARGET)

.PHONY: clean