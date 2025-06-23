#!/bin/bash

# ================================
# Build Script for STM32 Project
# Author: Nguyen Van Thanh
# ================================

# === Config ===
AUTHOR="THANH"
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"          # Đường dẫn tuyệt đối tới scripts/
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"              # Lên một cấp để về project root
LOG_DIR="$PROJECT_ROOT/LOGGING"
LOG_FILE="$LOG_DIR/build.log"
TIME_START=$(date '+%Y-%m-%d %H:%M:%S')

# === Ensure log folder exists ===
mkdir -p "$LOG_DIR"

# === Start logging ===
echo "===============================" > "$LOG_FILE"
echo "Build started at: $TIME_START" >> "$LOG_FILE"
echo "===============================" >> "$LOG_FILE"
echo "" >> "$LOG_FILE"

# === Run make in project root ===
echo "Running make in: $PROJECT_ROOT" | tee -a "$LOG_FILE"
cd "$PROJECT_ROOT"
make all 2>&1 | tee -a "$LOG_FILE"
MAKE_EXIT_CODE=${PIPESTATUS[0]}

# === Check result ===
if [ $MAKE_EXIT_CODE -eq 0 ]; then
    echo "" | tee -a "$LOG_FILE"
    echo " Build completed successfully!" | tee -a "$LOG_FILE"
    echo "Completed at: $(date '+%Y-%m-%d %H:%M:%S')" | tee -a "$LOG_FILE"
    echo "Build started by: $AUTHOR" >> "$LOG_FILE"
    echo "===============================" >> "$LOG_FILE"
    exit 0
else
    echo "" | tee -a "$LOG_FILE"
    echo " Build failed!" | tee -a "$LOG_FILE"
    echo "Failed at: $(date '+%Y-%m-%d %H:%M:%S')" | tee -a "$LOG_FILE"
    echo "===============================" >> "$LOG_FILE"
    exit 1
fi
