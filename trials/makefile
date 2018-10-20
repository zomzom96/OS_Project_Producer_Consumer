CXX = g++
CXXFLAGS = -std=c++11 -Wno-c++11-extensions -g3

all: bin
bin: main buffer
	$(CXX) $(CXXFLAGS) -pthread -o prodConsumer main.o buffer.o
main: main.c
	$(CXX) $(CXXFLAGS) -o main.o -c main.c
buffer: buffer.c buffer.h
	$(CXX) $(CXXFLAGS) -o buffer.o -c buffer.c
run: bin
	./prodConsumer 10 10 10
clean:
	rm -f $(wildcard *.o)
	rm -f prodConsumer
