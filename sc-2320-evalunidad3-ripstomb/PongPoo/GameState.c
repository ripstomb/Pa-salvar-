#include "GameState.h"

// Funci�n para inicializar GameState
void GameState_initialize(struct GameState* gameState) {
    gameState->current_state = MENU;
}