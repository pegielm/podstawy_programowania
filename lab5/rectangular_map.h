#ifndef RECTANGULAR_MAP_H
#define RECTANGULAR_MAP_H
#include <stdio.h>
#include <stdbool.h>
#include "vector.h"
#include "move_direction.h"
#include "animal.h"
#define MAX_ANIMALS 10
typedef struct {
    int rows;
    int columns;
    Animal animals[MAX_ANIMALS];
    int numAnimals;
} RectangularMap;
void RectangularMap_init(RectangularMap *map, int rows, int columns);
bool RectangularMap_isPositionOccupied(RectangularMap *map, Vector position);
bool RectangularMap_addAnimal(RectangularMap *map, Animal animal);
void RectangularMap_executeMoves(RectangularMap *map, char *moves);
#endif /* RECTANGULAR_MAP_H */