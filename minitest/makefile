CC=gcc
CFLAGS=-I
LDFLAGS = -lpthread -lrt

all: reader writer

reader: shm_reader.c
	$(CC) $^ $(LDFLAGS) -o reader 
writer: shm_writer.c
	$(CC) $^ $(LDFLAGS) -o  writer 

clean:
	rm -rf *.o  reader writer