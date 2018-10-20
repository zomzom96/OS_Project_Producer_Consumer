#include <deque>
#include <mutex>
#include <semaphore.h>
#include <iostream>

#define SIZE 5

class Buffer{
    	std::deque<int> store;
    	std::mutex bufferAccess;
    	sem_t empty, full;

public:
  	Buffer();
  	~Buffer();
  	void insertItem(int);
  	int removeItem();
};
