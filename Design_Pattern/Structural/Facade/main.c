#include <stdio.h>
#include <stdlib.h>
#include "facade/smart_home_facade.h"

int main() {
    SmartHomeFacade* smartHome = createSmartHomeFacade();

    printf(">>> Activating morning routine...\n");
    activateMorningRoutine(smartHome);
    
    printf("\n>>> Activating away mode...\n");
    activateAwayMode(smartHome);
    
    printf("\n>>> Setting movie night scene...\n");
    setMovieNightScene(smartHome);
    
    printf("\nFreeing allocated memory...\n");
    free(smartHome->lighting);
    free(smartHome->security);
    free(smartHome->hvac);
    free(smartHome);
    
    return 0;
}