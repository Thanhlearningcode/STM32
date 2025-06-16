CC = gcc
CFLAGS = -Wall -Wextra -I.

# Directories
SRC_DIR = .
OBJ_DIR = object
FACADE_DIR = $(SRC_DIR)/facade
LIGHT_DIR = $(SRC_DIR)/lighting
SECURITY_DIR = $(SRC_DIR)/security
HVAC_DIR = $(SRC_DIR)/hvac

# Source files
SRCS = $(FACADE_DIR)/smart_home_facade.c \
       $(LIGHT_DIR)/lighting_system.c \
       $(SECURITY_DIR)/security_system.c \
       $(HVAC_DIR)/hvac_system.c \
       $(SRC_DIR)/main.c

# Object files
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Output executable
TARGET = smartHomeFacade

# Build rules
all: $(OBJ_DIR) $(TARGET)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/facade $(OBJ_DIR)/lighting $(OBJ_DIR)/security $(OBJ_DIR)/hvac

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(TARGET)