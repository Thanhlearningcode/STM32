#include <stdlib.h>
#include <string.h>
#include "decorators.h"

// Function to create a Milk decorator
MilkDecorator* createMilkDecorator(Beverage* beverage) {
    MilkDecorator* milkDecorator = (MilkDecorator*)malloc(sizeof(MilkDecorator));
    milkDecorator->beverage = beverage;
    return milkDecorator;
}

// Function to create a Sugar decorator
SugarDecorator* createSugarDecorator(Beverage* beverage) {
    SugarDecorator* sugarDecorator = (SugarDecorator*)malloc(sizeof(SugarDecorator));
    sugarDecorator->beverage = beverage;
    return sugarDecorator;
}

// Function to create a Pearls decorator
PearlsDecorator* createPearlsDecorator(Beverage* beverage) {
    PearlsDecorator* pearlsDecorator = (PearlsDecorator*)malloc(sizeof(PearlsDecorator));
    pearlsDecorator->beverage = beverage;
    return pearlsDecorator;
}

// Function to free memory allocated for Milk decorator
void freeMilkDecorator(MilkDecorator* milkDecorator) {
    free(milkDecorator);
}

// Function to free memory allocated for Sugar decorator
void freeSugarDecorator(SugarDecorator* sugarDecorator) {
    free(sugarDecorator);
}

// Function to free memory allocated for Pearls decorator
void freePearlsDecorator(PearlsDecorator* pearlsDecorator) {
    free(pearlsDecorator);
}

// Function to add milk to the beverage
void addMilk(MilkDecorator* milkDecorator) {
    strcat(milkDecorator->beverage->description, ", Milk"); // Add milk to description
    milkDecorator->beverage->price += 5000.0; // Increase price by milk cost
}

// Function to add sugar to the beverage
void addSugar(SugarDecorator* sugarDecorator) {
    strcat(sugarDecorator->beverage->description, ", Sugar"); // Add sugar to description
    sugarDecorator->beverage->price += 2000.0; // Increase price by sugar cost
}

// Function to add pearls to the beverage
void addPearls(PearlsDecorator* pearlsDecorator) {
    strcat(pearlsDecorator->beverage->description, ", Pearls"); // Add pearls to description
    pearlsDecorator->beverage->price += 3000.0; // Increase price by pearls cost
}
