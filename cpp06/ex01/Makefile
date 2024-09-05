CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp Serializer.cpp

OBJ_DIR = build/obj
DEP_DIR = build/dep
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
DEPS = $(SRCS:%.cpp=$(DEP_DIR)/%.d)

TARGET = serialize

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR) $(DEP_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MF $(DEP_DIR)/$*.d -c $< -o $@

$(OBJ_DIR) $(DEP_DIR):
	mkdir -p $@

-include $(DEPS)

clean:
	rm -rf build

fclean: clean
	rm -rf $(TARGET)

re: fclean $(TARGET)

.PHONY: all clean fclean re
