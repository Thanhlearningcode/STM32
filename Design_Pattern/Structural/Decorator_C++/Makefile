CXX = g++
CXXFLAGS = -Iinc -Ilib/googletest/googletest/include -Ilib/googletest/googletest -Wall -std=c++17
SRC = src
BIN = bin
LIB = lib/googletest/googletest/src
SOURCES = $(SRC)/NotificationSystem.cpp main.cpp
OBJECTS = $(BIN)/NotificationSystem.o $(BIN)/main.o
TEST_SOURCES = $(SRC)/NotificationSystem.cpp tests/test_main.cpp
TEST_OBJECTS = $(BIN)/NotificationSystem.o $(BIN)/test_main.o
GTEST_SRC = $(LIB)/gtest-all.cc
GTEST_OBJ = $(BIN)/gtest-all.o
EXEC = notification_system
TEST_EXEC = test_notification_system

all: $(EXEC)

$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXEC)

$(BIN)/NotificationSystem.o: $(SRC)/NotificationSystem.cpp | $(BIN)
	$(CXX) $(CXXFLAGS) -c $(SRC)/NotificationSystem.cpp -o $(BIN)/NotificationSystem.o

$(BIN)/main.o: main.cpp | $(BIN)
	$(CXX) $(CXXFLAGS) -c main.cpp -o $(BIN)/main.o

# GoogleTest object file
$(GTEST_OBJ): $(GTEST_SRC) | $(BIN)
	$(CXX) $(CXXFLAGS) -c $(GTEST_SRC) -o $(GTEST_OBJ)

# Test object file
$(BIN)/test_main.o: tests/test_main.cpp | $(BIN)
	$(CXX) $(CXXFLAGS) -c tests/test_main.cpp -o $(BIN)/test_main.o

# Test executable
$(TEST_EXEC): $(TEST_OBJECTS) $(GTEST_OBJ)
	$(CXX) $(TEST_OBJECTS) $(GTEST_OBJ) -pthread -o $(TEST_EXEC)

# Create bin directory
$(BIN):
	mkdir -p $(BIN)

# Test target
test: $(TEST_EXEC)
	./$(TEST_EXEC)

clean:
	rm -rf $(BIN) $(EXEC) $(TEST_EXEC)

.PHONY: all test clean