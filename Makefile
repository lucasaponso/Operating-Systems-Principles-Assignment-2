CC = g++
CFLAGS = -std=c++11
EXECUTABLES = fifo sjf rr

all: $(EXECUTABLES)

fifo: src/main.cpp src/Loader.cpp src/algorithms.cpp
	$(CC) $(CFLAGS) $^ -o $@

sjf: src/main.cpp src/Loader.cpp src/algorithms.cpp
	$(CC) $(CFLAGS) $^ -o $@

rr: src/main.cpp src/Loader.cpp src/algorithms.cpp
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f $(EXECUTABLES)
