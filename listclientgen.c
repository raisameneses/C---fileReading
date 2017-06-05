#include <stdlib.h>
#include <stdio.h>
#include "listADTgen.h"

int compare(int*, int*);
void printItem(int*);

int main(void)
{
  ListType l1, l2;
  
  l1 = create(sizeof(int), compare);
  //l2 = create(sizeof(int), compare);
   
  int i; 
  int* test;

  for (i = 1; i <= 10; i++) {
	push(l1, &i);	
  }

 /* printl(l1, printItem);
  i = 3;
  delete(l1, &i);
  printl(l1, printItem);
  i = 4;
  delete(l1, &i);
  printl(l1, printItem);
  i = 1;
  delete(l1, &i);
  printl(l1, printItem);
  i = 2;
  delete(l1, &i);
  printl(l1, printItem);
  int n = 999;
  push(l2, &n);
  push(l2, &n);
  push(l2, &n);
  printl(l1, printItem);*/
  test = *(*(getListItem (l1, 0)));
  printf("test: %d\n", test);
  printf("size before make empty: %d\n", size_is(l1));
 /* make_empty(l1);
  if (is_empty(l1))
    printf("l1 is empty\n");
  else
    printf("l1 is not empty\n");
  printf("size after make empty: %d\n", size_is(l1));*/
  
  destroy(l1);
  //destroy(l2);
  return 0;
}

void printItem (int* p) {
   printf("%d", *p);
}

int compare(int *a, int *b) {
   short int toReturn = 0;
   if (*a < *b)
	toReturn = -1;
   else if (*a > *b)
	toReturn = 1;
   return toReturn;
}
