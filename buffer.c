#include "buffer.h"

/* The mutex lock */
pthread_mutex_t mutex;

/* the semaphores */
sem_t full, empty;

/* the buffer */
buffer_item buffer[BUFFER_SIZE];

/* buffer counter */
int counter;

pthread_t tid;       // Thread ID
pthread_attr_t attr; // Set of thread attributes

/* Add an item to the buffer */
int insert_item(buffer_item item) {
  /* When the buffer is not full add the item
   *       and increment the counter*/
  if (counter < BUFFER_SIZE) {
    buffer[counter] = item;
    counter++;
    return 0;
  } else { /* Error the buffer is full */
    return -1;
  }
}

/* Remove an item from the buffer */
int remove_item(buffer_item *item) {
  /* When the buffer is not empty remove the item
   *       and decrement the counter */
  if (counter > 0) {
    *item = buffer[(counter - 1)];
    counter--;
    return 0;
  } else { /* Error buffer empty */
    return -1;
  }
}

/* Producer Thread */
void *producer(void *param) {
  buffer_item item;

  while (TRUE) {
    /* sleep for a random period of time */
    int rNum = rand() / RAND_DIVISOR;
    sleep(rNum);

    /* generate a random number */
    item = rand();

    /* acquire the empty lock */
    sem_wait(&empty);
    /* acquire the mutex lock */
    pthread_mutex_lock(&mutex);

    if (insert_item(item)) {
      fprintf(stderr, " Producer report error condition\n");
    } else {
      printf("producer produced %d\n", item);
    }
    /* release the mutex lock */
    pthread_mutex_unlock(&mutex);
    /* signal full */
    sem_post(&full);
  }
}

/* Consumer Thread */
void *consumer(void *param) {
  buffer_item item;

  while (TRUE) {
    /* sleep for a random period of time */
    int rNum = rand() / RAND_DIVISOR;
    sleep(rNum);

    /* aquire the full lock */
    sem_wait(&full);
    /* aquire the mutex lock */
    pthread_mutex_lock(&mutex);
    if (remove_item(&item)) {
      fprintf(stderr, "Consumer report error condition\n");
    } else {
      printf("consumer consumed %d\n", item);
    }
    /* release the mutex lock */
    pthread_mutex_unlock(&mutex);
    /* signal empty */
    sem_post(&empty);
  }
}
