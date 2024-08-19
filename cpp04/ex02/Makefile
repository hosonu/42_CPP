CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

TARGET = animal

FILES = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

$(TARGET): $(FILES)
	$(CXX) $(CXXFLAGS) $(FILES) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean