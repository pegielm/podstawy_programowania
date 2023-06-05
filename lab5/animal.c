#include <stdio.h>
#include <stdbool.h>
#include "map_direction.h"
#include "move_direction.h"
#include "vector.h"
typedef struct {
    Vector position;
    MapDirection orientation;
} Animal;


void Animal_toString(Animal animal) {
    printf("Position: ");
    Vector_toString(animal.position);

    printf(", Orientation: ");
    switch (animal.orientation) {
        case NORTH:
            printf("NORTH\n");
            break;
        case SOUTH:
            printf("SOUTH\n");
            break;
        case WEST:
            printf("WEST\n");
            break;
        case EAST:
            printf("EAST\n");
            break;
        default:
            printf("UNKNOWN\n");
            break;
    }
}

bool Animal_isAt(Animal animal, Vector position) {
    return (animal.position.x == position.x) && (animal.position.y == position.y);
}

void Animal_move(Animal *animal, MoveDirection direction) {
    switch (direction) {
        case FORWARD:
            switch (animal->orientation) {
                case NORTH:
                    if (animal->position.y < 9)
                        animal->position.y++;
                    break;
                case SOUTH:
                    if (animal->position.y > 0)
                        animal->position.y--;
                    break;
                case WEST:
                    if (animal->position.x > 0)
                        animal->position.x--;
                    break;
                case EAST:
                    if (animal->position.x < 9)
                        animal->position.x++;
                    break;
            }
            break;
        case BACKWARD:
            switch (animal->orientation) {
                case NORTH:
                    if (animal->position.y > 0)
                        animal->position.y--;
                    break;
                case SOUTH:
                    if (animal->position.y < 9)
                        animal->position.y++;
                    break;
                case WEST:
                    if (animal->position.x < 9)
                        animal->position.x++;
                    break;
                case EAST:
                    if (animal->position.x > 0)
                        animal->position.x--;
                    break;
            }
            break;
        case RIGHT:
            switch (animal->orientation) {
                case NORTH:
                    animal->orientation = EAST;
                    break;
                case SOUTH:
                    animal->orientation = WEST;
                    break;
                case WEST:
                    animal->orientation = NORTH;
                    break;
                case EAST:
                    animal->orientation = SOUTH;
                    break;
            }
            break;
        case LEFT:
            switch (animal->orientation) {
                case NORTH:
                    animal->orientation = WEST;
                    break;
                case SOUTH:
                    animal->orientation = EAST;
                    break;
                case WEST:
                    animal->orientation = SOUTH;
                    break;
                case EAST:
                    animal->orientation = NORTH;
                    break;
            }
            break;
    }
}