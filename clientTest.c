#include "client.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
    clntPtr c1;
    //test getters:
    int id = 12345;   
    char name[50];
    char phoneNumber[50];
    char email[50];
    c1 = createClient(id, "Joseph Miller", "206-555-1212", "millers@comcast.net");
     strcpy(name, getName(c1)); 
     strcpy(phoneNumber, getPhoneNumber(c1)); 
     strcpy(email, getEmail(c1));

    //int gettingId = getId(c1);
    //setId(c1, 555555);

    printf("testing getters\n: Name: %s\nphoneNumber: %s\n email: %s\n", name, phoneNumber, email);
    //printC(c1);
    destroyClient(c1);
    
}
