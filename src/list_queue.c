#include "list_queue.h"
#include <stdio.h>
#include <stdbool.h>

void init_queue(queue *q)
{
  /*Makes it so that none of the queue elements have a value
  as there are no items in the queue at its inception, the
  size of the queue is set to be 0.*/
  q->front = NULL;
  q->rear = NULL;
  q->size = 0;
}

int empty(queue *q)
{
  // Add your empty function
  if (q->size == 0) // Checks if queue size is 0, if it is, then the queue is empty, as per the initialization fo the queue
  {
    // printf("The queue is empty.\n");
    return 1;
  }
  if (q->size > 0) // If the queue size is larger than 0, it of course contains at least one element
  {
    // printf("The queue is not empty.\n");
    return 0;
  }
}

void enqueue(queue *q, int x)
{
  // Add your enqueue function

  qnode *temp = (qnode *)malloc(sizeof(qnode)); // Allocate memory for a temporary node
  temp->data = x;                               // The temporary node will hold the value to be inserted
  temp->next = NULL;                            // At first it will not point to anything

  if (empty(q) == 1) // If the queue is empty, the item that is enqueued will be the front element in the queue
  {
    q->front = temp;
  }
  else // Otherwise the rear of the queue will point to that element
  {
    q->rear->next = temp;
  }
  q->rear = temp;        // The inserted element will regardless of the situation always be the rear element of the queue, as per the FIFO concept
  q->size = q->size + 1; // Queue size is increased
  /*
  qnode *temp = q->rear;
  qnode *holder = (qnode *)malloc(sizeof(qnode *));
  holder->data = x;

  holder->next = q->rear->next;
  q->rear->next = holder;
  q->size++;
  */
}

int dequeue(queue *q)
{
  // Add your dequeue function

  int data = q->front->data; // The value to be returned from the queue is stored in a variable "data"

  q->front = q->front->next; // The first element of the queue is updated

  q->size = q->size - 1;                       // Queue size is decreased
  printf("The returned value is: %d\n", data); // Printing out the data returned for testing purposes
  return data;                                 // The data we want from the queue is returned

  /*
  qnode *temp = q->rear;

  while (temp->next != q->front)
  {
    temp = temp->next;
  }
  int x = temp->data;

  qnode *linker = q->rear;
  while (linker->next != temp)
  {
    linker = linker->next;
  }
  linker->next = temp->next;
  temp = NULL;
  q->size--;
  return x;
  */
}
