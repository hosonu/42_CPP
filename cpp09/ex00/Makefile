CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
DEBUGFLAGS = -D DEBUG

NAME = btc

SRCS = main.cpp BitcoinExchange.cpp Validater.cpp

OBJ_DIR = build/obj
DEP_DIR = build/dep
OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
DEPS = $(SRCS:%.cpp=$(DEP_DIR)/%.d)

ifeq ($(DEBUG), 1)
	CXXFLAGS += $(DEBUGFLAGS)
endif

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(DEP_DIR):
	@mkdir -p $(DEP_DIR)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR) $(DEP_DIR)
	$(CXX) $(CXXFLAGS) -MMD -MF $(DEP_DIR)/$*.d -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

-include $(DEPS)

clean:
	@rm -rf build

fclean: clean
	@rm -f $(NAME)

re: fclean all

debug: fclean
	@make DEBUG=1

.PHONY: all clean fclean re debug
