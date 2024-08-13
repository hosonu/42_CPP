CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = Harlfilter

SOURCES = main.cpp Harl.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean