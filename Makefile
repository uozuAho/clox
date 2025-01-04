SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := include

CC := gcc
CFLAGS := -Wall -Wextra -Werror -I$(INCLUDE_DIR)
LDFLAGS :=

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))

TARGET := $(BUILD_DIR)/clox

all: $(TARGET)

build: $(TARGET)

run: $(TARGET)
	@./$(TARGET)

$(TARGET): $(OBJ_FILES)
	@echo "linking..."
	@$(CC) $(OBJ_FILES) -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR)

.PHONY: all clean
