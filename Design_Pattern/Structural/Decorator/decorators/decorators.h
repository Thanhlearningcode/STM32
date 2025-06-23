#ifndef DECORATORS_H
#define DECORATORS_H

#include "../beverage/beverage.h"

// Structure for Milk decorator
typedef struct {
    Beverage* beverage; // Base beverage
} MilkDecorator;

// Structure for Sugar decorator
typedef struct {
    Beverage* beverage; // Base beverage
} SugarDecorator;

// Structure for Pearls decorator
typedef struct {
    Beverage* beverage; // Base beverage
} PearlsDecorator;

// Function prototypes for creating decorators
MilkDecorator* createMilkDecorator(Beverage* beverage);
SugarDecorator* createSugarDecorator(Beverage* beverage);
PearlsDecorator* createPearlsDecorator(Beverage* beverage);

// Function to free memory allocated for decorators
void freeMilkDecorator(MilkDecorator* milkDecorator);
void freeSugarDecorator(SugarDecorator* sugarDecorator);
void freePearlsDecorator(PearlsDecorator* pearlsDecorator);

// Functions to apply decorators
void addMilk(MilkDecorator* milkDecorator);
void addSugar(SugarDecorator* sugarDecorator);
void addPearls(PearlsDecorator* pearlsDecorator);

#endif // DECORATORS_H
