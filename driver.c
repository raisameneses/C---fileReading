/*Raisa Meneses
Tested with Ubuntu 16.04 LTS Desktop 32-bits
Pr4 - Driver
Note: I made the stock class private, planning to make the first 
option for the extra credit, but when I finished my homework
I couldn't really see the difference between the first
option of the extra credit and the what I had already done for the homework. I decided to leave the 
class private, as I put some extra work coding my program that way.
I understand if that doesn't apply to extra credit. Just wanted to let you know. 
*/
#include "client.h"
#include "stock.h"
#include "listADTgen.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//Prototypes:
void populateClientList(ListType clientList); 
void populateStockList(ListType stockList);
void createSummary(ListType clientList, ListType stockList);

int main(void){     
   int i, clientListSize, stockListSize;
  	
   //Lists to hold all clients and stock structs. 
   ListType stockList, clientList;   
   clientList = create(clientSize(), compareClient);
   stockList =  create(stockSize(), compareStock);
   //Populating the client and stock class
   populateClientList(clientList);
   populateStockList(stockList);
   //printl(clientList, printC);
   //Create summary file:
   createSummary(clientList, stockList);

  
   //Free memory to avoid memory leaks. 
   destroy(stockList);
   destroy(clientList);

}

//Function to populate the List with all the clients
//Pre: an List and the File
//Pos: Populated Client list
void populateClientList(/*List to be populated with client structs.*/ListType clientList){   
   FILE* clientFile;
   int id;
   char name[50];
   char Lastname[50];
   char phoneNumber[50];
   char email[50];
   
   //Pointer to hold a temporary client value
   clntPtr client;
   int i, len;
  //File pointer to read the file where the clients information is stored.
   clientFile = fopen("clients.txt", "r");
   if(clientFile == NULL) {
      perror("Error opening the File");
      return;
    }
   
   while(!feof(clientFile)) {
     //There is a space before and after %d and %s. This is important for the file to be read and stored correctly. 
     //Please be careful when reading this file
     //do not move the space. Thanks. 
      fscanf(clientFile, " %d ", &id);       
      fgets (name, 25, clientFile);
      //Get rid of possible new line after client name.   
      /*len = strlen(name);
      if (len > 0 && name[len-1] == '\n') name[len-1] = '\0';  */
      //strtok(name, "\n");

      fscanf(clientFile, " %s ", phoneNumber);
      fscanf(clientFile, "%s ", email);         
      client = createClient(id, name, phoneNumber, email);

      push(clientList, client);
      destroyClient(client);
   }
   printf("------Client array populated-------\n");
   fclose(clientFile);
}


//Function to populate the List with all the stocks
//Pre: an List and the File
//Pos: Populated Stock list 
void populateStockList(/*List to be populated with stock structs.*/ListType stockList) {   
   FILE* stockFile;
   int len;
   double price;
   char symbol[50];
   
   //Pointer to hold a temporary stock value
   stckPtr stock;
   stockFile = fopen("stocks.csv", "r");
   if(stockFile == NULL) {
      perror("Error opening the File");
      return;
    }
   fscanf(stockFile, "Symbol,Current Price");
   while(!feof(stockFile)){
     //There is a space before the %lf. This is important for the file to be read and stored correctly. 
     //Please be careful when reading this file
     //do not move the space. Thanks. 
     fscanf(stockFile, " %[^,],%lf", symbol, &price);
     //getting rid of the new line in the stock:
     len = strlen(symbol);
     if (len > 0 && symbol[len-1] == '\n') symbol[len-1] = '\0';
     stock = createStock(price, symbol);
     //printS(stock);
     push(stockList, stock);
     //Free the stock to avoid memory leaks
     destroyStock(stock);
  }
  printf("------Stock array populated-------\n");
   fclose(stockFile);
}

//Creates the file summary
//pre: Client list and stok list
//We'll be using the client/stock relation as well. 
//Pos: File summary.

void createSummary(ListType clientList, ListType stockList){
   //Files
   FILE* summaryFile; 
   FILE* stockClientFile;
   //Variables used to hold temp. info. 
   int id, i, j, k, numberOfStocks, tempIdHolder, numberOfShares, clientSize, stockSize, compare, tempId;
   char name[50];
   char phoneNumber[50];
   char email[50];
   char symbol[50];
   char tempSymbol[50];
   double price, valueOfClient = 0;
   //temp stock and client values for quick look up:
   clntPtr tempClient;
   stckPtr tempStock;

   clientSize =  size_is(clientList);
   stockSize = size_is(stockList);
   stockClientFile = fopen("stock_client.txt", "r");
   summaryFile = fopen("summary.csv", "w");
   //scan until the end of the file
   while(!feof(stockClientFile)){ 
     fscanf(stockClientFile,"%d%d", &id, &numberOfStocks);  
     
     for(j = 0; j <  clientSize; j++){
        tempClient = getListItem(clientList, j);
	tempId = getId(tempClient);
	//printf("The temp Id is: %d\n", tempId);        
          if (tempId == id) { 
	      strcpy(name, getName(tempClient)); 
	      strcpy(phoneNumber, getPhoneNumber(tempClient)); 
	      strcpy(email, getEmail(tempClient));  
	      //printf("Number of stocks: %d\n", numberOfStocks);
              
	    fprintf(summaryFile, "Client:,%d,%s,%s,%s\n", id, name, phoneNumber, email); 
	     //Gather the information about each stock the client owns and send it to the summary file: 
          	for (i = 1; i <= numberOfStocks; i++) { 	   	   
          	    fscanf(stockClientFile," %s %d", symbol, &numberOfShares);
	  	    	  
           		for(k = 0; k < stockSize; k++) {
			     tempStock = getListItem(stockList, k);
			     strcpy(tempSymbol, getSymbol(tempStock)); 
	   	    	     compare = strcmp(tempSymbol,  symbol);	     	      
	      		    if (compare == 0) {	       	
               		    price = getPrice(tempStock);	    
              	            valueOfClient += (numberOfShares * price);
             		}  
                   }	
		   
		       fprintf(summaryFile, "%s,%d,%lf\n", symbol, numberOfShares, price);
	   		free(tempStock); 
               }  
  	       if (valueOfClient > 0) {
	       printf("$%'.2f\n", valueOfClient);
	       fprintf(summaryFile, "Value of client:,%lf\n", valueOfClient); 
 	       } 
            }  
        }      
    
   }   
   printf("----------------------Success------------------------\n");
   printf("------------------Summary File Created--------------------\n");
   //End of while  
   fclose(stockClientFile);  
}

