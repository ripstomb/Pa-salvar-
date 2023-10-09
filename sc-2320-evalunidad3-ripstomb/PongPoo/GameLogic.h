#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "GameObject.h"
#include "GameState.h"
#include "WindowManager.h"
#include "constants.h"

typedef struct GameLogic {
    int game_over;
    int ball_hits;
    int consecutive_hits;
    struct GameObject ball;
    struct GameObject racket;
    struct GameState* game_state;
    struct WindowManager* window_manager;
    struct GameObject* game_object;
} GameLogic;

// Inicializa la lógica del juego
void GameLogic_init(GameLogic* game_logic, struct GameState* game_state, struct WindowManager* window_manager, struct GameObject* game_object);

// Procesa la entrada del jugador
void GameLogic_process_input(GameLogic* game_logic, struct GameObject* game_object);

// Actualiza la lógica del juego
void GameLogic_update(GameLogic* game_logic, float delta_time);

// Renderiza el juego
void GameLogic_render(GameLogic* game_logic);

// Limpia los recursos
void GameLogic_cleanup(GameLogic* game_logic);

#endif