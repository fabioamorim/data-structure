#include <stdio.h>

/*
  Author: Fábio Amorim
  Date: 23/06/2020
*/

int fatorial(int number){

  if((number-1)>0){
    return number * fatorial(number-1);
  }
  return 1;
}

int main(){

  int number;

  printf("Enter with a number!");
  scanf("%i",&number);

/*
  Thist methods is not recommended

  int i = number;
  int result = 1;

  for(i;i>0;i--){
    result *= i;
  }

  printf("The number digited: %i\n",number);
  printf("The fatorial is: %i", result);

*/

  printf(" *The fatorial is: %i", fatorial(number));

  printf("\n");
  return 0;

}
