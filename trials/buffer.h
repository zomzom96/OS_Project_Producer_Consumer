#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include "buffer.h"

typedef int buffer_item;
#define BUFFER_SIZE 5

#define RAND_DIVISOR 100000000
#define TRUE 1

/* The mutex lock */
extern pthread_mutex_t mutex;

/* the semaphores */
extern sem_t full, empty;

/* the buffer */
extern buffer_item buffer[BUFFER_SIZE];

/* buffer counter */
extern int counter;

extern pthread_t tid;       //Thread ID
extern pthread_attr_t attr; //Set of thread attributes


void *producer(void *param); /* the producer thread */
void *consumer(void *param); /* the consumer thread */

#endif
