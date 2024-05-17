#include <iostream>
#include "../include/tetris.h"
#include <random>
#include <ctime>

using namespace std;

char blocks[N_BLOCKS][ROTATION][SHAPE_HEIGHT][SHAPE_WIDTH] = {
        //I
        {
                {
                        {'1','1','1','1'},
                        {' ',' ',' ',' '},
                        {' ',' ',' ',' '},
                        {' ',' ',' ',' '},
                },
                {
                        {'1',' ',' ',' '},
                        {'1',' ',' ',' '},
                        {'1',' ',' ',' '},
                        {'1',' ',' ',' '},
                },
                {
                        {'1','1','1','1'},
                        {' ',' ',' ',' '},
                        {' ',' ',' ',' '},
                        {' ',' ',' ',' '},
                },
                {
                        {'1',' ',' ',' '},
                        {'1',' ',' ',' '},
                        {'1',' ',' ',' '},
                        {'1',' ',' ',' '},
                },
        },

        //J
        {
                {
                        {'2',' ',' ',' ' },
                        {'2','2','2',' ' },
                        {' ',' ',' ',' ' },
                        {' ',' ',' ',' ' },
                },

                {
                        {'2','2',' ',' ' },
                        {'2',' ',' ',' ' },
                        {'2',' ',' ',' ' },
                        {' ',' ',' ',' ' },
                },

                {
                        {'2','2','2',' ' },
                        {' ',' ','2',' ' },
                        {' ',' ',' ',' ' },
                        {' ',' ',' ',' ' },
                },
                {
                        {' ','2',' ',' ' },
                        {' ','2',' ',' ' },
                        {'2','2',' ',' ' },
                        {' ',' ',' ',' ' },
                }
        },

        //L
        {
                {
                        {'3','3',' ',' '},
                        {' ','3',' ',' ' },
                        {' ','3',' ',' ' },
                        {' ',' ',' ',' '},
                },
                {
                        {' ',' ','3',' '},
                        {'3','3','3',' ' },
                        {' ',' ',' ',' ' },
                        {' ',' ',' ',' '},
                },
                {
                        {'3',' ',' ',' '},
                        {'3',' ',' ',' ' },
                        {'3','3',' ',' ' },
                        {' ',' ',' ',' '},
                },
                {
                        {'3','3','3',' '},
                        {'3',' ',' ',' ' },
                        {' ',' ',' ',' ' },
                        {' ',' ',' ',' '},
                }
        },

        //O
        {
                {
                        {'4','4',' ',' ' },
                        {'4','4',' ',' ' },
                        {' ',' ',' ',' ' },
                        {' ',' ',' ',' ' },
                },
                {
                        {'4','4',' ',' ' },
                        {'4','4',' ',' ' },
                        {' ',' ',' ',' ' },
                        {' ',' ',' ',' ' },
                },
                {
                        {'4','4',' ',' ' },
                        {'4','4',' ',' ' },
                        {' ',' ',' ',' ' },
                        {' ',' ',' ',' ' },
                },
                {
                        {'4','4',' ',' ' },
                        {'4','4',' ',' ' },
                        {' ',' ',' ',' ' },
                        {' ',' ',' ',' ' },
                },
        },

        //S
        {
                {
                        {' ','5','5',' '},
                        {'5','5',' ',' '},
                        {' ',' ',' ',' '},
                        {' ',' ',' ',' '},
                },
                {
                        {'5',' ',' ',' '},
                        {'5','5',' ',' '},
                        {' ','5',' ',' '},
                        {' ',' ',' ',' '},
                },
                {
                        {' ','5','5',' '},
                        {'5','5',' ',' '},
                        {' ',' ',' ',' '},
                        {' ',' ',' ',' '},
                },
                {
                        {'5',' ',' ',' '},
                        {'5','5',' ',' '},
                        {' ','5',' ',' '},
                        {' ',' ',' ',' '},
                },
        },

        //T
        {
                {
                        {' ','6',' ',' '},
                        {'6','6','6',' ' },
                        {' ',' ',' ',' '},
                        {' ',' ',' ',' '},
                },
                {
                        {'6',' ',' ',' '},
                        {'6','6',' ',' ' },
                        {'6',' ',' ',' '},
                        {' ',' ',' ',' '},
                },
                {
                        {'6','6','6',' '},
                        {' ','6',' ',' ' },
                        {' ',' ',' ',' '},
                        {' ',' ',' ',' '},
                },
                {
                        {' ','6',' ',' '},
                        {'6','6',' ',' ' },
                        {' ','6',' ',' '},
                        {' ',' ',' ',' '},
                }
        },

        //|
        {
                {
                        {'7','7',' ',' ' },
                        {' ','7','7',' ' },
                        {' ',' ',' ',' '},
                        {' ',' ',' ',' ' },
                },
                {
                        {' ','7',' ',' ' },
                        {'7','7',' ',' ' },
                        {'7',' ',' ',' '},
                        {' ',' ',' ',' ' },
                },
                {
                        {'7','7',' ',' ' },
                        {' ','7','7',' ' },
                        {' ',' ',' ',' '},
                        {' ',' ',' ',' ' },
                },
                {
                        {' ','7',' ',' ' },
                        {'7','7',' ',' ' },
                        {'7',' ',' ',' '},
                        {' ',' ',' ',' ' },
                }
        }
};

bool gameOver(Player_Data_t playerOne, World_Data_t currentGame, char shape[N_BLOCKS][ROTATION][SHAPE_HEIGHT][SHAPE_WIDTH],
              char world[WORLD_HEIGHT][WORLD_WIDTH]) {
    playerOne.y = 0;
    playerOne.x = 3;

    if (isColliding(playerOne.y, playerOne.x, playerOne.rotation, playerOne, currentGame, blocks, world)) {
        return true;
    }
    return false;
}

bool isColliding(int y, int x, int rotation, Player_Data_t playerOne, World_Data_t currentGame, char  shape[N_BLOCKS][ROTATION][SHAPE_HEIGHT][SHAPE_WIDTH],
              char world[WORLD_HEIGHT][WORLD_WIDTH]){
    bool collision = false;

    int shapeRows = SHAPE_HEIGHT;
    int shapeCols = SHAPE_WIDTH;

    for(int i = 0; i < shapeRows;i++){
        for(int j = 0; j < shapeCols; j++){
            if (shape[playerOne.assetIdx][rotation][i][j] != EMPTY_SPACE ) {
                int worldY = y + i;
                int worldX = x + j;

                if (worldX < 0 || worldX >= WORLD_WIDTH || worldY < 0 || worldY >= WORLD_HEIGHT) {
                    return true;
                }

                if(world[worldY][worldX] != EMPTY_SPACE ){
                    return true;
                }
            }
        }
    }

    return false;
}


void placeIt(Player_Data_t playerOne, World_Data_t currentGame, char  shape[N_BLOCKS][ROTATION][SHAPE_HEIGHT][SHAPE_WIDTH],
              char world[WORLD_HEIGHT][WORLD_WIDTH], int& currentScore){

    for(int i = 0; i < SHAPE_HEIGHT; i++){
        for(int j = 0; j < SHAPE_WIDTH; j++){
            if (shape[playerOne.assetIdx][playerOne.rotation][i][j] != EMPTY_SPACE ) {
                int worldX = playerOne.x + j;
                int worldY = playerOne.y + i;
                world[worldY][worldX] = shape[playerOne.assetIdx][playerOne.rotation][i][j];
            }
        }
    }

    int deletedLines = 0;

    for(int i = 0; i < WORLD_HEIGHT; i++) {
        if(isLineComplete(i, world)) {
            deleteLine(i, world);
            deletedLines++;
        }
    }

    if(deletedLines == 0) {
        currentScore += 30;
    }
    else if (deletedLines > 0) {
        updateScore(playerOne, deletedLines, currentScore);
    }

}

bool isLineComplete(int line, char world[WORLD_HEIGHT][WORLD_WIDTH]){
    bool isComplete = true;
    int i = 0;
    while(i < WORLD_WIDTH && isComplete){
        if(world[line][i] == ' '){
            return false;
        }
        i++;
    }
    return isComplete;
}

void deleteLine(int line, char world[WORLD_HEIGHT][WORLD_WIDTH]){
    for(int i = line; i > 0; i--) {
        for(int j = 0; j < WORLD_WIDTH; j++) {
            world[i][j] = world[i-1][j];
        }
    }
    for(int j = 0; j < WORLD_WIDTH; j++) {
        world[0][j] = EMPTY_SPACE;
    }
}

void fallDown(Player_Data_t playerOne, World_Data_t currentGame, char  shape[N_BLOCKS][ROTATION][SHAPE_HEIGHT][SHAPE_WIDTH],
              char world[WORLD_HEIGHT][WORLD_WIDTH], int& currentScore) {

    while (!isColliding(playerOne.y  + 1, playerOne.x, playerOne.rotation, playerOne, currentGame, blocks, world)) {
        playerOne.y++;
    }
    placeIt(playerOne, currentGame, blocks, world, currentScore);
}

void initWorld(char world[WORLD_HEIGHT][WORLD_WIDTH]){
    for(int i = 0; i < WORLD_HEIGHT; i++) {
        for (int j = 0; j < WORLD_WIDTH; j++) {
            world[i][j] = EMPTY_SPACE;
        }
    }
}

//TODO funzione updateScore invocata da deleteLine e da placeIt che aggiorna il punteggio
void updateScore(Player_Data_t playerOne, int lineCleared, int& currentScore) {
    int points[] = {0, 100, 200, 400, 800};

    currentScore += points[lineCleared];
}

//TODO funzione per upgradeLevel controlla il numero di linee o punteggio e aumenta velocità
void upgradeLevel(Player_Data_t& player, World_Data_t& world) {
    int nextLevel = world.level * POINT_PER_LEVEL;
    if(player.score < nextLevel ){
        //We haven't reach the next level yet so we just return;
        return;
    }
    world.level++;
    world.fallSpeed -= SPEED_PER_LEVEL;
    if(world.fallSpeed < FALL_SPEED_LIMIT ){
        world.fallSpeed = FALL_SPEED_LIMIT;
    }
}

//TODO risolvere il problema del crash
int randIndex() {
    static random_device rd;
    static mt19937 gen(rd());
    static uniform_int_distribution<> dis(0, 6);

    int val = dis(gen);
    cout << val << endl;
    return val;
}



void setupNewGames(Player_Data_t& player, World_Data_t& world, char map[WORLD_HEIGHT][WORLD_WIDTH]) {
    player.score = 0;
    player.rotation=0;
    world.level = 1;
    world.fallSpeed= 1000;
    initWorld(map);
    player.assetIdx = randIndex();
   // player.assetIdx = 6;
    world.nextBlock = randIndex();
    player.x = 3;
    player.y =  0;
}

