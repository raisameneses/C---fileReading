#include "stock.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void){
    stckPtr s1;
    double price = 36.14;
    

    s1 = create(price, "AAAP");

    double gettingPrice = getPrice(s1);
    setPrice(s1, 225.25);

    printf("getting the price: %f\n", gettingPrice);
    printS(s1);
    
}
