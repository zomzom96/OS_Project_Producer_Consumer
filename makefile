CXX = g++
CXXFLAGS = -std=c++11 -Wno-c++11-extensions -g3

all: bin
bin: main buffer
	$(CXX) $(CXXFLAGS) -lpthread -o prodConsumer main.o buffer.o
main: main.cc
	$(CXX) $(CXXFLAGS) -o main.o -c main.cc
buffer: buffer.cc buffer.hh
	$(CXX) $(CXXFLAGS) -o buffer.o -c buffer.cc
run: bin
	./prodConsumer 6 2 3
clean:
	rm -f $(wildcard *.o)
	rm -f prodConsumer
