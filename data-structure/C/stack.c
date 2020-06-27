#include <stdio.h>
#include <stdbool.h>

/*
  Author: Fábio Amorim
  Date: 27/06/2020
*/

#define MAX 10 // stack size

typedef int TYPE;

typedef struct{
  TYPE num;
}REGISTER;

typedef struct{
  REGISTER CONTENT[MAX];
  int numReg;
}STACK;

void initialize(STACK* S){
  S->numReg = 0;
}

int size(STACK* S){
  return S->numReg;
}

// stackIsFull: checks if the is full or no.
bool stackIsFull(STACK* S){
  if(size(S)< MAX)
    return false;
  return true;
}

// toStack: add a  new element to the stack.
bool toStack(STACK* S, TYPE element){
  if(stackIsFull(S))
    return false;
  printf("Add the element %d in Stack.\n", element);
  S->CONTENT[S->numReg].num = element;
  S->numReg++;
  return true;
}

// unstack: Removes the last element to the stack.
bool unstack(STACK* S){
  if(size(S)==0)
    return false;
  printf("Unstack: %i\n", S->CONTENT[S->numReg-1].num);

  S->CONTENT[S->numReg-1].num = -99;
  S->numReg--;

  return true;
}

// unstackAll: Rmeoves all elements to the stack.
void unstackAll(STACK* S){
  if(size(S) == 0){
    printf("The stack is already empty.");
  }else{
    int i = 0;
    for(i;i< S->numReg; i++){
      printf("Unstack: %i\n", S->CONTENT[i].num);
      S->CONTENT[i].num = -99;
    }

    S->numReg = 0;
    printf("The stack is empty.");
  }

}

// searchInStack:
int searchInStack(STACK* S, TYPE element){
    if(size(S)==0)
      return -2; // return -2 if stack is empty.

    int i = 0;
    for(i;i < S->numReg; i++){
      if (S->CONTENT[i].num == element)
        return i; // return the element's position.
    }

    return -1; // return -1 if element is not in the stack.
}

// showStack: show all elements
void showStack(STACK* S){
  printf("Stack: \n");

  if(S->numReg > 0){
    int i =0;
    for(i;i<S->numReg;i++){
      printf("%i\n", S->CONTENT[i].num);
    }

  }else{
    printf("Ther are no elements in the stack.");
  }
}

int main(){

  STACK s;

  initialize(&s);

  toStack(&s, 12);
  toStack(&s, 22);
  toStack(&s, 32);
  toStack(&s, 42);
  toStack(&s, 52);
  toStack(&s, 62);
  toStack(&s, 72);

  printf("Size: %i\n", size(&s));

  showStack(&s);

  unstack(&s);

  showStack(&s);

  printf("%i\n",searchInStack(&s, 42));

  unstackAll(&s);

  printf("Size: %i\n", size(&s));

  showStack(&s);

  return 0;

}
