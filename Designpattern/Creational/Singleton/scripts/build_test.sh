#!/bin/bash

# ================================
# === Build and Run Unit Tests ===
# Author: Nguyen Van Thanh
# ================================

# === Path setup ===
SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"
TEST_DIR="$PROJECT_ROOT/tests"
BUILD_DIR="$TEST_DIR/build"
LOG_DIR="$PROJECT_ROOT/LOGGING"
LOG_FILE="$LOG_DIR/build_test.log"
TEST_BINARY="$BUILD_DIR/uart_builder_test"
TIME_START=$(date '+%Y-%m-%d %H:%M:%S')

# === Ensure logging directory exists ===
mkdir -p "$LOG_DIR"

# === Start logging ===
echo "===============================" > "$LOG_FILE"
echo "Test build started at: $TIME_START" >> "$LOG_FILE"
echo "===============================" >> "$LOG_FILE"
echo "" >> "$LOG_FILE"

echo "Running cmake and make..." | tee -a "$LOG_FILE"

# === Clean old CMake cache if needed ===
if [ -f "$BUILD_DIR/CMakeCache.txt" ]; then
    echo "Old CMake cache found. Cleaning build directory to avoid conflict." | tee -a "$LOG_FILE"
    rm -rf "$BUILD_DIR"
fi

# === Prepare build directory ===
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

# === Run CMake ===
cmake .. 2>&1 | tee -a "$LOG_FILE"
CMAKE_EXIT_CODE=${PIPESTATUS[0]}

if [ $CMAKE_EXIT_CODE -ne 0 ]; then
    echo "" | tee -a "$LOG_FILE"
    echo "CMake configuration failed!" | tee -a "$LOG_FILE"
    echo "===============================" >> "$LOG_FILE"
    exit 1
fi

# === Run Make ===
make 2>&1 | tee -a "$LOG_FILE"
MAKE_EXIT_CODE=${PIPESTATUS[0]}

if [ $MAKE_EXIT_CODE -ne 0 ]; then
    echo "" | tee -a "$LOG_FILE"
    echo "Make failed!" | tee -a "$LOG_FILE"
    echo "===============================" >> "$LOG_FILE"
    exit 1
fi

# === Run test binary if exists ===
if [ -x "$TEST_BINARY" ]; then
    echo "" | tee -a "$LOG_FILE"
    echo "Test build successful!" | tee -a "$LOG_FILE"
    echo "Running test:" | tee -a "$LOG_FILE"
    "$TEST_BINARY" 2>&1 | tee -a "$LOG_FILE"
    echo "===============================" >> "$LOG_FILE"
else
    echo "" | tee -a "$LOG_FILE"
    echo "Test binary '$TEST_BINARY' not found or not executable!" | tee -a "$LOG_FILE"
    echo "===============================" >> "$LOG_FILE"
    exit 1
fi
