CC = gcc
CFLAGS = -Wall
TARGET = a.out
OBJECTS = arraygraph.o bfs.o circular_queue.o test_bfs.o

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o a.out
