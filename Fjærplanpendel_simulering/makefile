CC := gcc

CFLAGS := -w -std=c11 -Iinclude

LDFLAGS := -lraylib -lGL -lm -lpthread -ldl\
-lX11 -lXrandr -lXi -lXcursor -lXinerama

SRC := $(wildcard src/*.c)

OBJ := $(SRC:.c=.o)

TARGET := Pendulum_simulation

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
