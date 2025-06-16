#include <stdio.h>
#include "musicPlayer.h"
#include "stoppedState.h"

int main() {
    // Create player with initial state: Stopped
    MusicPlayer *player = musicPlayerCreate(stoppedStateCreate());

    // Simulate user interactions
    player->clickStopButton(player);   // Stop
    player->clickPlayButton(player);   // Start playing
    player->clickPauseButton(player);  // Pause
    player->clickPlayButton(player);   // Resume
    player->clickStopButton(player);   // Stop
    player->clickPauseButton(player);  // Try to pause when stopped
    player->clickStopButton(player);   // Try to stop when already stopped

    musicPlayerDestroy(player);
    return 0;
}
