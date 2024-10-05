CC = gcc
CFLAGS = -Wall -Wextra -std=c99

SRCS = main.c pgm.c
OBJS = $(SRCS:.c=.o)
TARGET = app.out

.PHONY: all clean debug

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

debug: CFLAGS += -g
debug: all

clean:
	rm -f $(OBJS) $(TARGET)