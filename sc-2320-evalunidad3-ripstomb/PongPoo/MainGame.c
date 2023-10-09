#include "MainGame.h"

int MainGame_main(MainGame* Main_Game, struct GameLogic* game_logic, struct GameState* game_state, struct WindowManager* window_manager, struct GameObject* game_object) {
    // Inicializa objetos y recursos necesarios
    Main_Game->game_state = game_state;
    Main_Game->window_manager = window_manager;
    Main_Game->game_object = game_object;
    Main_Game->game_logic = game_logic;

    GameLogic_initialize(&game_logic);
    WindowManager_initialize(&window_manager);
    GameState_initialize(&game_state);

    int game_is_running = TRUE;

    while (game_is_running) {
        // Procesa entrada del usuario
        GameLogic_processInput(&game_logic);

        // Actualiza la lógica del juego
        GameLogic_update(&game_logic, float delta_time);

        // Renderiza el juego
        WindowManager_render(&window_manager, &game_state);

        // Implementa la lógica para verificar si el juego terminó
        if (game_logic->game_over) {
            game_state->current_state = GAME_OVER;
        }
    }

    // Limpia recursos
    GameLogic_cleanup(&game_logic);
    WindowManager_cleanup(&window_manager);

    return 0;
}

int main() {
    return MainGame_main();
}
