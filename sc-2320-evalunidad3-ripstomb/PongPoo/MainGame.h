#ifndef MAINGAME_H
#define MAINGAME_H


#include <stdio.h>
#include <stdlib.h>
#include "GameLogic.h"
#include "WindowManager.h"
#include "constants.h"

typedef struct MainGame {
    struct GameState* game_state;
    struct WindowManager* window_manager;
    struct GameObject* game_object;
    struct GameLogic* game_logic;
} MainGame;

int MainGame_main(MainGame* Main_Game, struct GameLogic* game_logic, struct GameState* game_state, struct WindowManager* window_manager, struct GameObject* game_object);

#endif