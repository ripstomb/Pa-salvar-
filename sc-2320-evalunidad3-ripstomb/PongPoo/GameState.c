#include "GameState.h"

// Función para inicializar GameState
void GameState_initialize(struct GameState* gameState) {
    gameState->current_state = MENU;
}