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

  int n, p;
  // formule: Cn,p = n!/c!(p-n)!

  printf("Enter the set quantity: \n");
  scanf("%i",&n);

  printf("Entre number of p: \n");
  scanf("%i",&p);

  int result = (fatorial(n)) / (fatorial(p) * fatorial((n-p)));

  printf("The result is: %i\n", result);

  return 0;

}
