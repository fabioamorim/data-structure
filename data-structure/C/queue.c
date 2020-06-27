#include <stdio.h>
#include <stdbool.h>

/*
  Author: Fábio Amorim
  Date: 27/06/2020
*/

#define MAX 10 // queue size.

typedef int TYPE;

typedef struct{
  TYPE num;
}REGISTER;

typedef struct{
  REGISTER CONTENT[MAX];
  int numReg;
}QUEUE;

void initialize(QUEUE* Q){
  Q->numReg = 0;
}

int size(QUEUE* Q){
  return Q->numReg;
}

// queueIsFull: checks if the is full or no.
bool queueIsFull(QUEUE* Q){
  if(size(Q)< MAX)
    return false;
  return true;
}

// toQueue: add a new element to the queue.
bool toQueue(QUEUE* Q, TYPE element){
  if(queueIsFull(Q))
    return false;
  printf("Add the element %d in Queue.\n", element);
  Q->CONTENT[Q->numReg].num = element;
  Q->numReg++;
  return true;
}

// dequeue: Removes the first element to the queue.
bool dequeue(QUEUE* Q){
  if(size(Q)==0)
    return false;
  printf("Dequeue: %i\n", Q->CONTENT[0].num);

  int i = 0;

  for(i;i < Q->numReg;i++){
    Q->CONTENT[i].num = Q->CONTENT[i+1].num;
  }

  Q->numReg--;
  return true;
}

// dequeueAll: Removes all element to the queue.
bool dequeueAll(QUEUE* Q){
  if(size(Q) > 0){
    int i = 0;
    for(i;i < Q->numReg;i++){
      printf("Dequeue: %i\n", Q->CONTENT[i].num);
      Q->CONTENT[i].num = -1;
    }

    Q->numReg = 0;
    printf("Queue is empty.");
  }else{
      printf("The queue is already empty.");
  }
}

// searchInQueue:
int searchInQueue(QUEUE* Q, TYPE element)
{
  if(size(Q)==0)
    return -2; // return -2 if queue is empty.

  int i = 0;
  for(i;Q->numReg;i++)  {
    if(Q->CONTENT[i].num == element)
      return i; // return the element's position.
  }

  return -1; // return -1 if element is not in the queue.
}

// showQueue: show all elements.
void showQueue(QUEUE* Q){
  printf("Queue: \n");

  if(Q->numReg>0){
    int i = 0;
    for(i;i < Q->numReg; i++){
      printf("%i\n", Q->CONTENT[i].num);
    }

  }else{
    printf("There are no elements in the queue.");
  }
}

int main(){

  QUEUE q;

  initialize(&q);

  toQueue(&q, 2);
  toQueue(&q, 5);
  toQueue(&q, 1);
  toQueue(&q, 3);
  toQueue(&q, 7);

  printf("Size: %i\n", size(&q));

  showQueue(&q);

  printf("Size: %i\n", size(&q));

  printf("Position: %i\n", searchInQueue(&q, 1));

  dequeue(&q);

  showQueue(&q);

  printf("Size: %i\n", size(&q));

  return 0;
}
