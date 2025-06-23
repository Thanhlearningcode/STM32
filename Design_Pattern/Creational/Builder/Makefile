# ================================
# Makefile for STM32F411 Project
# Author: Nguyễn Văn Thành
# ================================

# ==== Compiler and Tools ====
CC      = arm-none-eabi-gcc
AS      = arm-none-eabi-as
LD      = arm-none-eabi-gcc
OBJCOPY = arm-none-eabi-objcopy
SIZE    = arm-none-eabi-size

# ==== Directories ====
SRC_DIR          = Src
INC_DIR          = Inc
BUILD_DIR        = build
STARTUP_DIR      = Startup
CMSIS_DEVICE_INC = CMSIS/Device/ST/STM32F4xx/Include
CMSIS_DEVICE_SRC = CMSIS/Device/ST/STM32F4xx/Source
CMSIS_CORE_INC   = CMSIS/Include

# ==== MCU Settings ====
MCU       = cortex-m4
FPU       = fpv4-sp-d16
FLOAT_ABI = hard

# ==== Defines and Includes ====
DEFINES  = -DSTM32F411xE
INCLUDES = -I$(INC_DIR) -I$(CMSIS_DEVICE_INC) -I$(CMSIS_CORE_INC)

# ==== Source Files ====
SRC_APP    = $(wildcard *.c) $(wildcard $(SRC_DIR)/*.c)
SRC_CMSIS  = $(CMSIS_DEVICE_SRC)/Templates/system_stm32f4xx.c

# ==== Object Files ====
OBJ_APP     = $(patsubst %.c,$(BUILD_DIR)/%.o,$(wildcard *.c)) \
              $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(wildcard $(SRC_DIR)/*.c))
OBJ_CMSIS   = $(patsubst $(CMSIS_DEVICE_SRC)/Templates/%.c,$(BUILD_DIR)/%.o,$(SRC_CMSIS))
OBJ_STARTUP = $(BUILD_DIR)/startup_stm32f411vetx.o

OBJ_ALL = $(OBJ_APP) $(OBJ_CMSIS) $(OBJ_STARTUP)

# ==== Output Files ====
TARGET = $(BUILD_DIR)/STM32F411
ELF    = $(TARGET).elf
BIN    = $(TARGET).bin
MAP    = $(TARGET).map

# ==== Compiler Flags ====
ifdef DEBUG
DEBUG_CFLAGS = -O0 -g3 -DDEBUG
else
DEBUG_CFLAGS = -O2 -g
endif

CFLAGS = -mcpu=$(MCU) -mthumb -mfpu=$(FPU) -mfloat-abi=$(FLOAT_ABI) \
         $(DEFINES) $(DEBUG_CFLAGS) -Wall -ffunction-sections -fdata-sections \
         $(INCLUDES)

LDFLAGS = -T$(STARTUP_DIR)/STM32F411VETX_FLASH.ld -mcpu=$(MCU) -mthumb \
          -mfpu=$(FPU) -mfloat-abi=$(FLOAT_ABI) -Wl,--gc-sections \
          -Wl,-Map=$(MAP)

# ==== Header dependencies ====
DEPS = $(wildcard $(INC_DIR)/*.h)

# ==== Build Rules ====

# Default rule
all: $(BIN)

# Create build directory
$(BUILD_DIR):
	@if [ -d $(BUILD_DIR) ]; then \
		echo "Directory $(BUILD_DIR) exists, so removing $(BUILD_DIR)"; \
		rm -rf $(BUILD_DIR); \
	fi; \
	mkdir -p $(BUILD_DIR)

# Compile .c in Src/
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(DEPS) | $(BUILD_DIR)
	@echo "[Compiling] $<"
	$(CC) $(CFLAGS) -c $< -o $@

# Compile .c in root (e.g. main.c)
$(BUILD_DIR)/%.o: %.c $(DEPS) | $(BUILD_DIR)
	@echo "[Compiling root] $<"
	$(CC) $(CFLAGS) -c $< -o $@

# Compile CMSIS system file
$(BUILD_DIR)/%.o: $(CMSIS_DEVICE_SRC)/Templates/%.c | $(BUILD_DIR)
	@echo "[CMSIS] $<"
	$(CC) $(CFLAGS) -c $< -o $@

# Assemble startup file
$(BUILD_DIR)/%.o: $(STARTUP_DIR)/%.s | $(BUILD_DIR)
	@echo "[Assembling] $<"
	$(AS) -mcpu=$(MCU) -mthumb $< -o $@

# Link object files
$(ELF): $(OBJ_ALL)
	@echo "[Linking] $@"
	$(LD) $(LDFLAGS) $(OBJ_ALL) -o $@
	$(SIZE) $@

# Generate .bin from .elf
$(BIN): $(ELF)
	@echo "[Objcopy] $@"
	$(OBJCOPY) -O binary $< $@

# Flash to STM32
flash: $(BIN)
	st-flash write $(BIN) 0x8000000

# Clean build directory
clean:
	@echo "[Cleaning]"
	rm -rf $(BUILD_DIR)

.PHONY: all clean flash
