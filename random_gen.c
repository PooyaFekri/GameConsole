#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game_console.h"
extern char deathblock;
extern int randomness;
struct dimension map_size;
extern char **game_map;
extern int rain_x,rain_y;
void random_gen(int n,char b){
    int counter1 = 0,ran_x,ran_y;
    srand(randomness);
    randomness++;
    if (deathblock == b) {
        ran_x = (rand() % (map_size.x - 2)) + 1;
        while (counter1<n) {
            if (game_map[1][ran_x] == ' ') {
                game_map[1][ran_x] = b;
                rain_x = ran_x;
                rain_y = 1;
                counter1++;
            } else {
                srand(randomness);
                randomness++;
            }
        }
        return;
    }else {
        while (counter1<n){
            ran_x = (rand() % (map_size.x - 2)) + 1;
            ran_y = (rand() % (map_size.y - 2)) + 1;
            if (game_map[ran_y][ran_x] == ' ') {
                game_map[ran_y][ran_x] = b;
                counter1++;
            } else {
                srand(randomness);
                randomness++;
            }
        }
    }
}
