#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "WindowManager.h"
#include "constants.h"


// Función para inicializar WindowManager
void WindowManager_initialize(struct WindowManager* windowManager) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error initializing SDL.\n");
        exit(EXIT_FAILURE);
    }

    windowManager->window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH,
        WINDOW_HEIGHT,
        SDL_WINDOW_BORDERLESS
    );
    if (!windowManager->window) {
        fprintf(stderr, "Error creating SDL Window.\n");
        exit(EXIT_FAILURE);
    }

    windowManager->renderer = SDL_CreateRenderer(windowManager->window, -1, 0);
    if (!windowManager->renderer) {
        fprintf(stderr, "Error creating SDL Renderer.\n");
        exit(EXIT_FAILURE);
    }

    if (TTF_Init() != 0) {
        fprintf(stderr, "Error initializing SDL_ttf.\n");
        exit(EXIT_FAILURE);
    }

    windowManager->font = TTF_OpenFont("00TT.TTF", 24);
    if (!windowManager->font) {
        fprintf(stderr, "Error loading font.\n");
        exit(EXIT_FAILURE);
    }

    windowManager->textColor = (SDL_Color){ 255, 255, 255, 255 };
}

// Función para renderizar el juego
void WindowManager_render(struct WindowManager* windowManager, struct GameState* gameState) {
    SDL_SetRenderDrawColor(windowManager->renderer, 0, 0, 0, 255);
    SDL_RenderClear(windowManager->renderer);

    // Renderiza el juego según el estado actual
    switch (gameState->current_state) {
    case MENU:
        SDL_SetRenderDrawColor(windowManager->renderer, 0, 0, 0, 255);
        SDL_RenderClear(windowManager->renderer);
    {
        char menu_text[] = " [Espacio] para juego nuevo\n     [L] para Instrucciones";
        SDL_Surface* menuSurface = TTF_RenderText_Solid(windowManager->font, menu_text, windowManager->textColor);
        SDL_Texture* menuTexture = SDL_CreateTextureFromSurface(windowManager->renderer, menuSurface);

        SDL_Rect menuRect = {
            (WINDOW_WIDTH - menuSurface->w) / 2,
            (WINDOW_HEIGHT - menuSurface->h) / 2,
            menuSurface->w,
            menuSurface->h
        };
        SDL_RenderCopy(windowManager->renderer, menuTexture, NULL, &menuRect);

        SDL_FreeSurface(menuSurface);
        SDL_DestroyTexture(menuTexture);
    }
        break;

    case NEW_GAME:
        // Renderiza el juego en curso
        // Implementa la lógica para renderizar el juego aquí
        break;

    case LOAD_MENU:
        // Renderiza el menú de carga
        // Implementa la lógica para renderizar el menú de carga aquí
        break;

    case PLAYING:
        // Renderiza el juego en curso
        // Implementa la lógica para renderizar el juego aquí
        break;

    case GAME_OVER:
        // Renderiza la pantalla de fin de juego
        // Implementa la lógica para renderizar la pantalla de fin de juego aquí
        break;

    default:
        break;
    }

    SDL_RenderPresent(windowManager->renderer);
}



// Función para limpiar recursos de WindowManager
void WindowManager_cleanup(struct WindowManager* windowManager) {
    SDL_DestroyRenderer(windowManager->renderer);
    SDL_DestroyWindow(windowManager->window);

    TTF_CloseFont(windowManager->font);
    TTF_Quit();
    SDL_Quit();
}
