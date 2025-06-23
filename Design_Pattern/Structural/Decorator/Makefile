# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -I. -g

# Directories
SRC_DIR = .
OBJ_DIR = obj
BEVERAGE_DIR = $(OBJ_DIR)/beverage
DECORATORS_DIR = $(OBJ_DIR)/decorators

# Source files
SRCS = $(SRC_DIR)/beverage/beverage.c \
       $(SRC_DIR)/decorators/decorators.c \
       $(SRC_DIR)/main.c

# Object files
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Output executable
TARGET = beverageOrderSystem

# Build rules
all: $(OBJ_DIR) $(BEVERAGE_DIR) $(DECORATORS_DIR) $(TARGET)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BEVERAGE_DIR):
	mkdir -p $(BEVERAGE_DIR)

$(DECORATORS_DIR):
	mkdir -p $(DECORATORS_DIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)
