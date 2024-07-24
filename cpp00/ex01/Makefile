CXX = c++

CXXFLAGS = -Wall  -std=c++98

TARGET = phonebook

SOURCES = main.cpp PhoneBook.cpp Contact.cpp

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: clean