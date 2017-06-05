# makefile for pr4
#Raisa Meneses
#University of Washington Tacoma

#Run the main program:
pr4: stock.c client.c driver.c listADTgen.c  
	gcc -std=gnu90 -o pr4 stock.c client.c driver.c listADTgen.c 

#Test the client
#clnttst: client.c clientTest.c  
	#gcc -std=gnu90 -o clnttst client.c clientTest.c  

#Test the stock
#stocktst: stock.c stocktest.c  
	#gcc -std=gnu90 -o stocktst stock.c stocktest.c  



