#ifndef MAP_DIRECTION_H
#define MAP_DIRECTION_H
typedef enum {
    NORTH,
    SOUTH,
    WEST,
    EAST
} MapDirection;
void MapDirection_toString(MapDirection direction);
MapDirection MapDirection_next(MapDirection direction);
MapDirection MapDirection_previous(MapDirection direction);
#endif /* MAP_DIRECTION_H */