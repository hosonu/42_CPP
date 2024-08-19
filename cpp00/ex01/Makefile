CXX = c++

CXXFLAGS = -Wall  -std=c++98

TARGET = phonebook

SOURCES = main.cpp PhoneBook.cpp Contact.cpp

OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(TARGET)

.PHONY: clean
