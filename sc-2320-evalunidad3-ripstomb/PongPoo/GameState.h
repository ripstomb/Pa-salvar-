#ifndef GAMESTATE_H
#define GAMESTATE_H


// Enumeración para representar los estados del juego
enum GameStates {
    MENU,
    NEW_GAME,
    LOAD_MENU,
    PLAYING,
    GAME_OVER
};

// Estructura para representar el estado del juego
struct GameState {
    enum GameStates current_state;
};

// Función para inicializar GameState
void GameState_initialize(struct GameState* gameState);

#endif
