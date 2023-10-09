#include "GameObject.h"
#include "constants.h"
#include "WindowManager.h"

// Función para inicializar GameObject
struct GameObject* GameObject_create(float x, float y, float width, float height, float vel_x, float vel_y) {
    struct GameObject* gameObject = (struct GameObject*)malloc(sizeof(struct GameObject));
    if (gameObject != NULL) {
        gameObject->x = x;
        gameObject->y = y;
        gameObject->width = width;
        gameObject->height = height;
        gameObject->vel_x = vel_x;
        gameObject->vel_y = vel_y;
    }
    return gameObject;
}

void GameObject_update(struct GameObject* gameObject, float delta_time) {
    // Actualiza la posición u otros atributos de GameObject aquí en función de la lógica del juego
    gameObject->x += gameObject->vel_x * delta_time;
    gameObject->y += gameObject->vel_y * delta_time;
}