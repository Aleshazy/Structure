# Define the compiler
CC = gcc

# Define the compiler flags
CFLAGS = -Wall -Wextra -std=c11

# Define the target executable
TARGET = main

# Define the source files
SRCS = src/main.c includes/student_manage.h

# Define the object files
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to build the object files
%.o: %.c student_manage.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean