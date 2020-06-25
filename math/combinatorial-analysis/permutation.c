#include <stdio.h>

/*
  Author: Fábio Amorim
  Date: 24/06/2020
*/

int fatorial(int number){
  if((number-1)>0){
    return number * fatorial(number-1);
  }

  return 1;
}

int main(){

  int n;
  // formule Cn,p = n!/(p-n)!

  printf("Enter with a number: \n");
  scanf("%i",&n);

  printf("The permutation is: %i\n", fatorial(n));

  return 0;

}
