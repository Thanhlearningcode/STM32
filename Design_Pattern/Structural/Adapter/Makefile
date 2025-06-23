# Name of the executable
TARGET = adapter

# Compiler and flags
CC = gcc
CFLAGS = -Iinc -Isensors/ds18b20 -Isensors/lm75 -Wall -Wextra -g

# Source files
SRCS = \
    src/temperature_sensor_interface.c \
    sensors/ds18b20/ds18b20.c \
    sensors/ds18b20/ds18b20_adapter.c \
    sensors/lm75/lm75.c \
    sensors/lm75/lm75_adapter.c \
    main.c

# Object files in obj/ directory (replace .c by .o and add obj/)
OBJS = $(patsubst %.c, obj/%.o, $(SRCS))

# Default build rule
all: obj $(TARGET)

# Link all object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Rule to create obj directory if it does not exist
obj:
	mkdir -p obj
	mkdir -p obj/src
	mkdir -p obj/sensors/ds18b20
	mkdir -p obj/sensors/lm75

# Compile .c files to .o files in obj/ directory
obj/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean generated files
clean:
	rm -rf obj $(TARGET)

.PHONY: all clean obj