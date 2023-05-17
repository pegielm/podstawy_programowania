#ifndef ANIMAL_H
#define ANIMAL_H
#include <stdio.h>
#include <stdbool.h>
#include "map_direction.h"
#include "move_direction.h"
#include "vector.h"

typedef struct {
    Vector position;
    MoveDirection orientation;
} Animal;
void Animal_toString(Animal animal);
bool Animal_isAt(Animal animal, Vector position);
void Animal_move(Animal *animal, MoveDirection direction);
#endif /* ANIMAL_H */