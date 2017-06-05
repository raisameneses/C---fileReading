/*Raisa Meneses
Tested with Ubuntu 16.04 LTS Desktop 32-bits
Pr4 - Client*/
#include "client.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//struct definition for a client:
struct client {
   int id;
   char name[50];
   char phoneNumber[50];
   char email[50];
};

 // allocate memory for a structure variable containing all
 // list components
clntPtr createClient(int id, char name[], char phoneNumber[], char email[]) {
   //Allocate space in the heap. 
   clntPtr client = malloc(sizeof(struct client));
   // if allocation was succesfull
   if (client != NULL) { 
      client->id = id;
      strcpy(client->name, name);
      strcpy(client->phoneNumber, phoneNumber);
      strcpy(client->email, email);
      } 
      return client;
}

void destroyClient(clntPtr client){
   free(client);
}

//getters:

int getId(clntPtr client){
   return client->id;

}
char* getName(clntPtr client){
   return client->name;

}
char* getPhoneNumber(clntPtr client){
   return client->phoneNumber;
}
char* getEmail(clntPtr client){
   return client->email;
}

//setters
void setId(clntPtr client, int id){
   client->id = id;
}
void setName(clntPtr client, char name[]){	
   strcpy(client->name, name);
}
void setPhoneNumber(clntPtr client, char phoneNumber[]){
   strcpy(client->phoneNumber, phoneNumber);
}
void setEmail(clntPtr client, char email[]){
   strcpy(client->email, email);
}
//method to print a client
void printC(clntPtr clientPointer){
   printf("Id: %d\n Name: %s\n Phone Number: %s\n E-Mail: %s\n",
   clientPointer->id , clientPointer->name, clientPointer->phoneNumber, clientPointer->email);
}
//Returns the size of a struct client
int clientSize() {   
   return sizeof(struct client);
}

//Compare function for client. Used in the generic array
//pre: two client structs. 
//post: int. -1 if first one is lower than the other. 1 if it is greater. 0 if equal.
int compareClient(/*Two client struct*/clntPtr c1, clntPtr c2) {
   short int toReturn = 0;
   if (c1->id < c2->id)
	toReturn = -1;
   else if (c1->id > c2->id)
	toReturn = 1;
   return toReturn;
}

