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

void RectangularMap_init(RectangularMap *map, int rows, int columns) {
    map->rows = rows;
    map->columns = columns;
    map->numAnimals = 0;
}

bool RectangularMap_isPositionOccupied(RectangularMap *map, Vector position) {
    for (int i = 0; i < map->numAnimals; i++) {
        if (Vector_equals(map->animals[i].position, position)) {
            return true;
        }
    }
    return false;
}

bool RectangularMap_addAnimal(RectangularMap *map, Animal animal) {
    if (map->numAnimals >= MAX_ANIMALS) {
        return false;
    }

    if (RectangularMap_isPositionOccupied(map, animal.position)) {
        return false;
    }

    map->animals[map->numAnimals] = animal;
    map->numAnimals++;
    return true;
}

void RectangularMap_executeMoves(RectangularMap *map, char *moves) {
    int numMoves = 0;
    while (moves[numMoves] != '\0') {
        numMoves++;
    }

    int animalIndex = 0;
    for (int i = 0; i < numMoves; i++) {
        char moveChar = moves[i];
        Animal *animal = &map->animals[animalIndex];

        switch (moveChar) {
            case 'f':
                Animal_move(animal, FORWARD);
                break;
            case 'b':
                Animal_move(animal, BACKWARD);
                break;
            case 'l':
                Animal_move(animal, LEFT);
                break;
            case 'r':
                Animal_move(animal, RIGHT);
                break;
        }

        animalIndex = (animalIndex + 1) % map->numAnimals;
    }
}