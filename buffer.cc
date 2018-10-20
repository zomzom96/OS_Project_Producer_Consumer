#include "buffer.hh"

Buffer::Buffer()
{
    int i = 0;
    do{
        sem_init(&empty, 0, SIZE);
        sem_getvalue(&empty, &i);
    } while(!i);

    do {
        sem_init(&full, 0, 0);
        sem_getvalue(&full, &i);
    } while(i);
}
void Buffer::insertItem(int item){
    sem_wait(&empty);
    bufferAccess.lock();

    store.push_back(item);

    bufferAccess.unlock();
    sem_post(&full);
}
int Buffer::removeItem(){
    sem_wait(&full);
    bufferAccess.lock();

    int toReturn = store.front();
    store.pop_front();

    bufferAccess.unlock();
    sem_post(&empty);

    return toReturn;
}
Buffer::~Buffer(){
    sem_destroy(&empty);
    sem_destroy(&full);
}
