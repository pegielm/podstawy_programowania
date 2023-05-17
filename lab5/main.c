#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "animal.h"
#include "map_direction.h"
#include "move_direction.h"
#include "vector.h"
#include "rectangular_map.h"
void printmap(RectangularMap *map){
    for(int i = map->rows-1; i >=0; i--){
        for(int j = 0; j <map->columns; j++){
            Vector position = {j, i};
            if(RectangularMap_isPositionOccupied(map, position)){
                //print index of animal
                for(int k = 0; k < map->numAnimals; k++){
                    if(Animal_isAt(map->animals[k], position)){
                        printf("%d", k);
                    }
                }
            }
            else{
                printf(".");
            }
        }
        printf("\n");
    }
}
int main(){
    RectangularMap map;
    RectangularMap_init(&map, 10, 10);
    RectangularMap_addAnimal(&map, (Animal){{0, 0}, NORTH});
    RectangularMap_addAnimal(&map, (Animal){{0, 1}, NORTH});
    RectangularMap_addAnimal(&map, (Animal){{5, 5}, NORTH});
    bool run = true;
    while(run){
        //scan line of text from stdin
        printf(">");
        char line[100];
        scanf("%s", line);
        //check if line is "quit"
        if(strcmp(line, "quit") == 0){
            run = false;
        }
        if(strcmp(line, "print") == 0){
            printmap(&map);
        }
        if(strcmp(line, "add")== 0){
            printf("add\nx:");
            int x;
            scanf("%d", &x);
            printf("y:");
            int y;
            scanf("%d", &y);
            MapDirection orientation;
            orientation = NORTH;
            Animal animal = {{x, y}, orientation};
            RectangularMap_addAnimal(&map, animal);
        }
        else{
            RectangularMap_executeMoves(&map, line);
        }
    }

    
    return 0;
}