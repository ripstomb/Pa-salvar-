#include "constants.h"
#include "GameState.h"
#include "GameLogic.h"
#include "SDL.h"

void GameLogic_init(GameLogic* game_logic, struct GameState* game_state, struct WindowManager* window_manager, struct GameObject* game_object) {
    game_logic->game_state = game_state;
    game_logic->window_manager = window_manager;
    game_logic->game_object = game_object;

    // Restablece el estado del juego
    game_logic->game_over = FALSE;
    game_logic->ball_hits = 0;
    game_logic->consecutive_hits = 0;
}
void ball_create(struct GameObject* ball, float x, float y, float width, float height, float vel_x, float vel_y) {
    // Asigna los valores proporcionados a la instancia de ball
    ball->x = 20;
    ball->y = 20;
    ball->width = 15;
    ball->height = 15;
    ball->vel_x = 400;
    ball->vel_y = 300;
}


void racket_create(struct GameObject* racket, float x, float y, float width, float height, float vel_x, float vel_y) {
    // Asigna los valores proporcionados a la instancia de racket
    racket->width = 100;
    racket->height = 20;
    racket->x = (WINDOW_WIDTH / 2) - (racket->width / 2);
    racket->y = WINDOW_HEIGHT - 40;
    racket->vel_x = 0;
    racket->vel_y = 0;
}

void GameLogic_process_input(GameLogic* game_logic, struct GameObject* game_object) {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (game_logic->game_state->current_state) {
    case MENU:
        // Lógica de entrada para el estado de menú
        if (event.type == SDL_KEYDOWN) {
            
            if (event.key.keysym.sym == SDLK_SPACE) {
                // Cambiar al estado de juego nuevo (NEW_GAME)
                game_logic->game_state->current_state = NEW_GAME;
            }
            else if (event.key.keysym.sym == SDLK_l) {
                // Cambiar al estado de carga de partida (LOAD_MENU)
                game_logic->game_state->current_state = LOAD_MENU;
                // Implementa la lógica para cargar partidas anteriores aquí
            }
        }
        break;


    case NEW_GAME:
        // Lógica de entrada para el estado de juego nuevo
        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_SPACE) {
                // Cambiar al estado de juego en curso (PLAYING)
                game_logic->game_state->current_state = PLAYING;
                // Iniciar un nuevo juego
                GameLogic_setup(game_logic);
            }
            if (event.key.keysym.sym == SDLK_b) {
                // Volver al estado de menú (MENU)
                game_logic->game_state->current_state = MENU;
            }
        }
        break;

    case LOAD_MENU:
        // Lógica de entrada para el estado de carga de menú
        if (event.type == SDL_KEYDOWN) {
            
            if (event.key.keysym.sym == SDLK_SPACE) {
                // Cambiar al estado de carga de partida (LOADING_GAME)
                game_logic->game_state->current_state = MENU;
            }
        }
        break;

    case PLAYING:
        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_LEFT)
                game_logic->racket.vel_x = -RACKET_SPEED;
            if (event.key.keysym.sym == SDLK_RIGHT)
                game_logic->racket.vel_x = RACKET_SPEED;
        }

        if (event.type == SDL_KEYUP) {
            if (event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_RIGHT)
                game_logic->racket.vel_x = 0;
        }
        break;

    default:
        break;
    }
}
void GameLogic_update(GameLogic* game_logic, float delta_time) {
    if (game_logic->game_state->current_state == PLAYING) {
        // Lógica de juego aquí...
        game_logic->ball.x += game_logic->ball.vel_x * delta_time;
        game_logic->ball.y += game_logic->ball.vel_y * delta_time;

        game_logic->racket.x += game_logic->racket.vel_x * delta_time;

        if (game_logic->racket.x < 0)
            game_logic->racket.x = 0;
        if (game_logic->racket.x > WINDOW_WIDTH - game_logic->racket.width)
            game_logic->racket.x = WINDOW_WIDTH - game_logic->racket.width;

        if (game_logic->ball.y + game_logic->ball.height >= game_logic->racket.y && game_logic->ball.y <= game_logic->racket.y + game_logic->racket.height &&
            game_logic->ball.x + game_logic->ball.width >= game_logic->racket.x && game_logic->ball.x <= game_logic->racket.x + game_logic->racket.width) {
            game_logic->ball.vel_y = -game_logic->ball.vel_y;

            game_logic->consecutive_hits++;

            if (game_logic->consecutive_hits == 2) {
                game_logic->ball_hits++;

                game_logic->consecutive_hits = 0;

                if (game_logic->ball.vel_x > 0)
                    game_logic->ball.vel_x += 50;
                else
                    game_logic->ball.vel_x -= 50;

                if (game_logic->ball.vel_y > 0)
                    game_logic->ball.vel_y += 50;
                else
                    game_logic->ball.vel_y -= 50;
            }
        }

        if (game_logic->ball.y <= 0) {
            game_logic->ball.vel_y = -game_logic->ball.vel_y;
        }
        else if (game_logic->ball.y + game_logic->ball.height >= WINDOW_HEIGHT) {
            game_logic->game_over = TRUE;
        }

        if (game_logic->ball.x <= 0 || game_logic->ball.x + game_logic->ball.width >= WINDOW_WIDTH) {
            game_logic->ball.vel_x = -game_logic->ball.vel_x;
        }
    }
}
