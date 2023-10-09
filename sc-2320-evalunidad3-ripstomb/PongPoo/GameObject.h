#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

// Estructura para representar GameObject
struct GameObject {
    float x;
    float y;
    float width;
    float height;
    float vel_x;
    float vel_y;
};

struct GameObject* GameObject_create(float x, float y, float width, float height, float vel_x, float vel_y);
void GameObject_update(struct GameObject* gameObject, float delta_time);
void ball_create(struct GameObject* ball, float x, float y, float width, float height, float vel_x, float vel_y);
void racket_create(struct GameObject* racket, float x, float y, float width, float height, float vel_x, float vel_y);



#endif // GAMEOBJECT_H
