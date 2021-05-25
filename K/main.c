#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include "k.h"
#include "ui.h"
#include "hof.h"
#include <string.h>

int main(){

struct game game = {
    .board = {
        {'K', ' ', 'J', ' '},
        {'H', ' ', 'H', ' '},
        {' ', ' ', ' ', 'F'},
        {'J', 'E', ' ', ' '}
    },
    .score = 0
};

add_random_tile(&game);

printf("is won: %d\n", is_game_won(game));

struct game game2 = {
    .board = {
        {'A', 'B', 'C', 'D'},
        {'E', 'F', 'G', 'H'},
        {'I', 'J', 'K', 'A'},
        {'B', 'C', 'D', 'E'}
    },
    .score = 0
};

printf("is won: %d\n", is_game_won(game2));
struct game game55 = {
    .board = {
        {'B', 'A', 'C', 'D'},
        {' ', 'F', 'G', 'H'},
        {'I', 'J', 'D', 'A'},
        {'B', 'C', ' ', 'E'}
    },
    .score = 0
};

printf("is move possible: %d\n", is_move_possible(game55));
printf("\n");

struct game game3 = {
    .board = {
        {'A', 'D', 'C', 'D'},
        {'C', 'F', 'G', 'H'},
        {'I', 'J', 'B', 'A'},
        {'B', 'A', 'D', 'E'}
    },
    .score = 0
};

printf("is move possible: %d\n", is_move_possible(game3));

printf("\n");

struct game game4 = {
    .board = {
    {'B', 'E', 'D', 'A'},
    {'J', 'G', 'C', 'G'},
    {'G', 'C', 'D', 'I'},
    {'F', 'I', 'A', 'F'}
    },
    .score = 0
};

//render(game4);
printf("is move possible: %d\n", is_move_possible(game4)); 

struct game game5 = {
    .board = {
        {'B', 'A', ' ', 'D'},
        {' ', 'C', ' ', 'E'},
        {' ', 'A', ' ', ' '},
        {'B', 'A', 'D', 'E'}
 },
    .score = 8161
};
render(game5);

bool result = update(&game5, -1, 0);


printf("result is %d\n",result );
 
struct player list[10];

 printf("\n");
 
 load(list);
 
printf("save: %d\n\n", save(list,10));

struct player player = {.name="Bill", .score=330};
int size=2;
struct player hof[10] = {
    {.score=  866, .name="Samuel"},
    {.score=  766, .name="Manager"}
};
printf("size %d \n",size );

 int number2=add_player(hof,&size,player);

 printf("number : %d\n", number2);

 
	return 0;
}

