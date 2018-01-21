#ifndef _SO2048_H_
#define _SO2048_H_



/************************************************************/
/* micros */
/************************************************************/
#define true 1
#define false 0
typedef int bool;

typedef struct
{
    unsigned char r;
    unsigned char c;
} grid;


/************************************************************/
/* headerfiles */
/************************************************************/
#include<stdio.h>
#include<time.h> // 与时间种子相关
#include<stdlib.h> // 与rand 相关
#include<malloc.h>

/************************************************************/
/* variables */
/************************************************************/
extern int bestScore; 
extern int currentScore; 
extern int **fields;
extern int row ;
extern int column;
extern int maxNum;



/************************************************************/
/* methods declarations */
/************************************************************/
void setField(void *indata, int row, int column); // set the 2-dim array pointer of the field
void setBestScore(int); // set the value of the best score
int getBestScore(); // get the bestScore in the game
int getCurrentScore(); // get the current Score
void initGame(); //init the status of the game
void initPanel(); // clean the panel and generate the initial numbers
void generateNum();// generate a new number in a random position
int randInt(); // generate an random Integer

void keyLeft(); // when the key 'left' is pressed
void keyRight(); // when the key 'right' is pressed
void keyUp(); // when the key 'up' is pressed
void keyDown(); // when the key 'down' is pressed
void mergeLeft(); // all numbers move and merge with the left neighbors
void transposeVertical(); // transpose the matrix in vertical direction 
void transposeDiag(); // transpose the matrix around the main diagonal 
void transposeViceDiag(); // transpose the matrix around the vice diagonal 


bool isWin(); // see if the player wins
bool isLost(); // see if the player loses 
#endif
