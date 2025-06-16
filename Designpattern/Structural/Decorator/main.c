#include <stdio.h>
#include <stdlib.h>
#include "beverage/beverage.h"
#include "decorators/decorators.h"

int main() {
    // Create a plain coffee beverage
    Beverage* coffee = createPlainCoffee();
    printf("Description: %s\n", coffee->description);
    printf("Price: %.2fđ\n\n", coffee->price);

    // Create decorators for the beverage
    MilkDecorator* milkDecorator = createMilkDecorator(coffee);
    SugarDecorator* sugarDecorator = createSugarDecorator(coffee);

    // Add milk, sugar to the beverage
    addMilk(milkDecorator);
    addSugar(sugarDecorator);

    // Print the updated beverage description and price
    printf("Updated Description: %s\n", coffee->description);
    printf("Updated Price: %.2f\n", coffee->price);

    // Free allocated memory
    freeMilkDecorator(milkDecorator);
    freeSugarDecorator(sugarDecorator);
    freeBeverage(coffee);
    
    return 0;
}
