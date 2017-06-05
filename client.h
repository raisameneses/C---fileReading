/*Raisa Meneses
Tested with Ubuntu 16.04 LTS Desktop 32-bits
Pr4 - Client - Header*/
#ifndef CLIENT_H
#define CLIENT_H
#include <stdio.h>

typedef struct client *clntPtr;

clntPtr createClient(int id, char name[], char phoneNumber[], char email[]);
void destroyClient(clntPtr clientPointer);
int getId(clntPtr clientPointer);
char* getName(clntPtr clientPointer);
char* getPhoneNumber(clntPtr clientPointer);
char* getEmail(clntPtr clientPointer);
void setId(clntPtr clientPointer, int id);
void setName(clntPtr clientPointer, char name[]);
void setPhoneNumber(clntPtr clientPointer, char phoneNumber[]);
void setEmail(clntPtr clientPointer, char email[]);
void printC(clntPtr clientPointer);
int compareClient(clntPtr c1, clntPtr c2);
int clientSize();
#endif
