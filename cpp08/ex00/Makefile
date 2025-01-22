CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp

OBJ_DIR = build/obj
DEP_DIR = build/dep
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
DEPS = $(SRCS:%.cpp=$(DEP_DIR)/%.d)

TARGET = program

GTEST_DIR = /usr/local/include/gtest
GTEST_LIBS = -lgtest -lgtest_main -lpthread

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR) $(DEP_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MF $(DEP_DIR)/$*.d -c $< -o $@

$(OBJ_DIR) $(DEP_DIR):
	mkdir -p $@

-include $(DEPS)

test: $(OBJ_DIR)/test_easyfind.o
	$(CXX) -Wall -Werror -Wextra -o test $(OBJ_DIR)/test_easyfind.o $(GTEST_LIBS)
	./test

$(OBJ_DIR)/test_easyfind.o: test_easyfind.cpp | $(OBJ_DIR) $(DEP_DIR)
	$(CXX) -Wall -Werror -Wextra -MMD -MF $(DEP_DIR)/test.d -c test_easyfind.cpp -o $(OBJ_DIR)/test_easyfind.o

clean:
	rm -rf build

fclean: clean
	rm -rf $(TARGET) test

re: fclean all

.PHONY: all clean fclean re test