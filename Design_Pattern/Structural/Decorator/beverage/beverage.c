#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "beverage.h"

// Function to create a plain coffee beverage
Beverage* createPlainCoffee() {
    Beverage* coffee = (Beverage*)malloc(sizeof(Beverage));
    coffee->price = 20000.0;
    coffee->description = strdup("Plain Coffee");
    return coffee;
}

// Function to create a plain tea beverage
Beverage* createPlainTea() {
    Beverage* tea = (Beverage*)malloc(sizeof(Beverage));
    tea->price = 15000.0;
    tea->description = strdup("Plain Tea");
    return tea;
}

// Function to free memory allocated for a beverage
void freeBeverage(Beverage* beverage) {
    if (beverage != NULL) {
        free(beverage->description);
        free(beverage);
    }
}
