#include <stdio.h>

typedef enum {
    NORTH,
    SOUTH,
    WEST,
    EAST
} MapDirection;

void MapDirection_toString(MapDirection direction) {
    switch (direction) {
        case NORTH:
            printf("Polnoc\n");
            break;
        case SOUTH:
            printf("Poludnie\n");
            break;
        case WEST:
            printf("Zachod\n");
            break;
        case EAST:
            printf("Wschod\n");
            break;
        default:
            printf("Nieznany kierunek\n");
            break;
    }
}

MapDirection MapDirection_next(MapDirection direction) {
    switch (direction) {
        case NORTH:
            return EAST;
        case SOUTH:
            return WEST;
        case WEST:
            return NORTH;
        case EAST:
            return SOUTH;
        default:
            return direction;
    }
}

MapDirection MapDirection_previous(MapDirection direction) {
    switch (direction) {
        case NORTH:
            return WEST;
        case SOUTH:
            return EAST;
        case WEST:
            return SOUTH;
        case EAST:
            return NORTH;
        default:
            return direction;
    }
}
