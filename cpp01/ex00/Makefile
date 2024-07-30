CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = Zombie

SOURCES = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean