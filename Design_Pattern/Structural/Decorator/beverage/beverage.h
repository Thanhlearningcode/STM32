#ifndef BEVERAGE_H
#define BEVERAGE_H

// Structure representing a beverage with its price and description
typedef struct {
    float price;
    char* description;
} Beverage;

// Function prototypes for creating beverages
Beverage* createPlainCoffee();
Beverage* createPlainTea();

// Function to free memory allocated for a beverage
void freeBeverage(Beverage* beverage);

#endif // BEVERAGE_H
