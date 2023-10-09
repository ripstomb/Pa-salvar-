#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <SDL.h>
#include <SDL_ttf.h>
#include "GameState.h"


// Estructura para representar WindowManager
struct WindowManager {
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;
    SDL_Color textColor;
};

// Funci�n para inicializar WindowManager
void WindowManager_initialize(struct WindowManager* windowManager);

// Funci�n para renderizar el juego
void WindowManager_render(struct WindowManager* windowManager, struct GameState* gameState);

// Funci�n para limpiar recursos de WindowManager
void WindowManager_cleanup(struct WindowManager* windowManager);

#endif // WINDOWMANAGER_H
