/*Raisa Meneses
Tested with Ubuntu 16.04 LTS Desktop 32-bits
Pr4 - Stock*/
#include "stock.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//struct definition for a client:
struct stock {
 double price;
 char Symbol[50];
};
// allocate memory for a structure variable containing all
// list components
stckPtr createStock(double price, char symbol[]){   
   //Allocate space in the heap. 
   stckPtr stock = malloc(sizeof(struct stock));
   // if allocation was succesfull
   if (stock != NULL) { 
      stock->price = price;
      strcpy(stock->Symbol, symbol);
    }
   return stock;
}
//dealocate heap memory
void destroyStock(stckPtr stckPtr) {
   free(stckPtr);
}
//getters:
double getPrice(stckPtr stckPtr){
   return stckPtr->price;
}
char* getSymbol(stckPtr stckPtr){
   return stckPtr->Symbol;
}
//Setters: 
void setSymbol(stckPtr stckPtr, char symbol[]){
   strcpy(stckPtr->Symbol, symbol);
}
void setPrice(stckPtr stckPtr, double price){
   stckPtr->price = price;
}
//Prints stock:
void printS(stckPtr stckPtr){
printf(" Symbol: %s\n priCe: %f\n",
   stckPtr->Symbol, stckPtr->price);
}

//Compare function for stock. Used in generic array. Returns an array
//pre: two stock structs. 
//post: int. -1 if first one is lower than the other. 1 if it is greater. 0 if equal. 
int compareStock(/*Two stock structs*/stckPtr s1, stckPtr s2) {
   short int toReturn = 0;
   if (s1->price < s2->price)
	toReturn = -1;
   else if (s1->price > s2->price)
	toReturn = 1;
   return toReturn;
}

//Returs the size of the struct
int stockSize() {

    return sizeof(struct stock);
}
