/*Raisa Meneses
Tested with Ubuntu 16.04 LTS Desktop 32-bits
Pr4 - Stock - Header*/
#ifndef STOCK_H
#define STOCK_H
#include <stdio.h>

typedef struct stock *stckPtr;

stckPtr createStock(double price, char symbol[]);
void destroyStock(stckPtr stock);
double getPrice(stckPtr stock);
char* getSymbol(stckPtr stock);
void setSymbol(stckPtr stock, char symbol[]);
void setPrice(stckPtr stock, double price);
void printS(stckPtr stock);
int compareStock(stckPtr s1, stckPtr s2);
int stockSize();
#endif
