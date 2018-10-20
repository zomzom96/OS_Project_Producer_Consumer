#include "buffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void initializeData() {

  /* Create the mutex lock */
  pthread_mutex_init(&mutex, NULL);

  /* Create the full semaphore and initialize to 0 */
  sem_init(&full, 0, 0);

  /* Create the empty semaphore and initialize to BUFFER_SIZE */
  sem_init(&empty, 0, BUFFER_SIZE);

  /* Get the default attributes */
  pthread_attr_init(&attr);

  /* init buffer */
  counter = 0;
}

int main(int argc, char *argv[]) {
  /* Loop counter */
  int i;
  /* Verify the correct number of arguments were passed in */
  if (argc != 4) {
    fprintf(stderr, "USAGE:./prodConsumer <INT> <INT> <INT>\n");
  }

  int mainSleepTime = atoi(argv[1]); /* Time in seconds for main to sleep */
  int numProd = atoi(argv[2]);       /* Number of producer threads */
  int numCons = atoi(argv[3]);       /* Number of consumer threads */
  /* Initialize the app */
  initializeData();
  /* Create the producer threads */
  for (i = 0; i < numProd; i++) {
    /* Create the thread */
    pthread_create(&tid, &attr, producer, NULL);
  }

  /* Create the consumer threads */
  for (i = 0; i < numCons; i++) {
    /* Create the thread */
    pthread_create(&tid, &attr, consumer, NULL);
  }
  /* Sleep for the specified amount of time in milliseconds */
  sleep(mainSleepTime);
  /* Exit the program */
  printf("Exit the program\n");
  exit(0);
}
