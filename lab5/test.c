#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "animal.h"
#include "map_direction.h"
#include "move_direction.h"
#include "vector.h"
#include "rectangular_map.h"
#include "assert.h"
int main (){
    printf("test\n");
    printf("##################### TEST VECTOR #####################\n");
    Vector vector1 = {1, 2};
    Vector vector2 = {3, 4};
    Vector vector3 = {1, 2};
    Vector resoult0 = {4, 6};
    Vector check = Vector_add(vector1, vector2);
    assert(Vector_equals(resoult0, check));
    printf("test add vector: PASSED\n");
    check = Vector_subtract(vector2, vector1);
    Vector resoult1 = {2, 2};
    assert(Vector_equals(resoult1, check));
    printf("test subtract vector: PASSED\n");
    check = Vector_upperRight(vector1, vector2);
    Vector resoult2 = {3, 4};
    assert(Vector_equals(resoult2, check));
    printf("test upperRight vector: PASSED\n");
    check = Vector_lowerLeft(vector1, vector2);
    Vector resoult3 = {1, 2};
    assert(Vector_equals(resoult3, check));
    printf("test lowerLeft vector: PASSED\n");
    check = Vector_opposite(vector1);
    Vector resoult4 = {-1, -2};
    assert(Vector_equals(resoult4, check));
    printf("test opposite vector: PASSED\n");
    assert(Vector_equals(vector1, vector3));
    printf("test equals vector: PASSED\n");
    assert(Vector_precedes(vector1, vector2));
    printf("test precedes vector: PASSED\n");
    assert(Vector_follows(vector2, vector1));
    printf("test follows vector: PASSED\n");


    printf("##################### TEST MAP DIRECTION #####################\n");
    MapDirection direction1 = NORTH;
    assert(MapDirection_next(direction1) == EAST);
    printf("test next map direction: PASSED\n");
    assert(MapDirection_previous(direction1) == WEST);
    printf("test previous map direction: PASSED\n");


    printf("##################### TEST ANIMAL #####################\n");
    Animal animal1 = {{1, 2}, NORTH};
    bool check1 = Animal_isAt(animal1, vector1);
    assert(check1);
    printf("test isAt animal: PASSED\n");
    Animal_move(&animal1, FORWARD);
    Vector resoult5 = {1, 3};
    assert(Vector_equals(resoult5, animal1.position));
    printf("test move animal: PASSED\n");
    Animal_move(&animal1, BACKWARD);
    assert(Vector_equals(vector1, animal1.position));
    printf("test move animal: PASSED\n");
    

    printf("##################### TEST RECTANGULAR MAP #####################\n");
    RectangularMap map;
    RectangularMap_init(&map, 10, 10);
    RectangularMap_addAnimal(&map, (Animal){{0, 0}, NORTH});
    RectangularMap_addAnimal(&map, (Animal){{0, 1}, NORTH});
    RectangularMap_addAnimal(&map, (Animal){{1, 2}, NORTH});
    assert(RectangularMap_isPositionOccupied(&map, vector1));
    printf("test isPositionOccupied rectangular map: PASSED\n");
    RectangularMap_addAnimal(&map, (Animal){{1, 2}, NORTH});
    assert(!RectangularMap_addAnimal(&map, (Animal){{1, 2}, NORTH}));
    printf("test add animal rectangular map: PASSED\n");
    



    return 0;
}