# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -IInc -g

# Directories
SRC_DIR = Src
OBJ_DIR = Obj
SENSORS_OBJ_DIR = $(OBJ_DIR)/Sensors
SUBSCRIBERS_OBJ_DIR = $(OBJ_DIR)/Subscribers

# Source files
SRCS = main.c \
       $(SRC_DIR)/Publisher.c \
       $(SRC_DIR)/Sensors/Door_Sensor.c \
       $(SRC_DIR)/Sensors/Smoke_Sensor.c \
       $(SRC_DIR)/Subscribers/Mobile_App_Notifier.c \
       $(SRC_DIR)/Subscribers/Alarm_System_Controller.c

# Object files
OBJS = $(OBJ_DIR)/main.o \
       $(OBJ_DIR)/Publisher.o \
       $(SENSORS_OBJ_DIR)/Door_Sensor.o \
       $(SENSORS_OBJ_DIR)/Smoke_Sensor.o \
       $(SUBSCRIBERS_OBJ_DIR)/Mobile_App_Notifier.o \
       $(SUBSCRIBERS_OBJ_DIR)/Alarm_System_Controller.o

# Output executable
TARGET = smartHome

# Build rules
all: $(OBJ_DIR) $(SENSORS_OBJ_DIR) $(SUBSCRIBERS_OBJ_DIR) $(TARGET)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(SENSORS_OBJ_DIR):
	mkdir -p $(SENSORS_OBJ_DIR)

$(SUBSCRIBERS_OBJ_DIR):
	mkdir -p $(SUBSCRIBERS_OBJ_DIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compile main
$(OBJ_DIR)/main.o: main.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile publisher
$(OBJ_DIR)/Publisher.o: $(SRC_DIR)/Publisher.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile sensors
$(SENSORS_OBJ_DIR)/%.o: $(SRC_DIR)/Sensors/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile subscribers
$(SUBSCRIBERS_OBJ_DIR)/%.o: $(SRC_DIR)/Subscribers/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf $(OBJ_DIR) $(TARGET)
