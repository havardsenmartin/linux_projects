CC := gcc

CFLAGS := -w -std=c11 -Iinclude

LDFLAGS := -ldl

SRC := $(wildcard src/*.c)

OBJ := $(SRC:.c=.o)

TARGET := server

s: server

server: src/server.o
	$(CC) src/server.o -o $@ $(LDFLAGS)

server.o: src/server.c
	$(CC) $(CFLAGS) -c $< -o $@

c: client

client: src/client.o
	$(CC) src/client.o -o $@ $(LDFLAGS)

client.o: src/client.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
