#include"so2048.h"



/************************************************************/
/* variables */
/************************************************************/
int bestScore = 0; 
int currentScore = 0; 
int **fields;
int row = 4;
int column = 4;
int maxNum = 0;
int blankGrid = 16;

grid gr[16];

/************************************************************/
/* methods implementations */
/************************************************************/
/* set the 2-dim array pointer of the field */
void setField(void *indata, int inrow, int incolumn){
    char i;

    row = inrow;
    column = incolumn;

    fields = (int**)malloc(sizeof(int*) * row); // reform the 1D array to 2D array
    for(char i = 0; i < row; i ++)
        fields[i] = (int*)indata + i * column;

}


/* set the value of the best score */
void setBestScore(int num){ 
    bestScore = num;
    printf("set the best Score\n");
}


/* get the bestScore in the game */
int getBestScore()
{     
    return bestScore;
}


/* get the current Score */
int getCurrentScore() 
{
    return currentScore;
}



/* init the status of the game */
void initGame(){ 
    printf(" in the so2048 C method init()\n");
    currentScore = 0;
    maxNum = 0;
    blankGrid = 16;
    initPanel();
    printf("leave the so2048 C method init()\n");

} 


/* init the numbers of the panel */
void initPanel(){
    char i,j;

    // reset the values of the grids
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            fields[i][j] = 0;

    generateNum();
    generateNum();

}


/* generate a new number in a random position */
void generateNum()
{
    char i,j;
    char len = 0;
    int ind;

    // pick out all the blank grids
    for(i = 0; i < 4; i++)
        for(j = 0; j < 4; j++)
            if(fields[i][j] == 0)
            {
                gr[len].r = i;
                gr[len].c = j;
                len++;
            }

    // choose a blank grid randomly
    ind = randInt()%len;
    fields[gr[ind].r][gr[ind].c] = (1 + randInt()%2)<<1;

    blankGrid--;
}


/* generate an random Integer */
int randInt(){ 
    srand((unsigned)time(NULL));
    return rand();
}


/* when the key 'left' is pressed */
void keyLeft(){
    printf("press key left\n");
    mergeLeft();
    generateNum();
}


/* when the key 'right' is pressed */
void keyRight(){
    printf("press key right\n");
    transposeVertical();
    mergeLeft();
    transposeVertical();
    generateNum();
}


/* transpose the matrix in vertical direction */
void transposeVertical()
{
    char i,j;

    i = 0;
    while(i < 4)
    {
        j = 0;
        while(j < 2)
        {
            fields[i][j] = fields[i][j]^fields[i][3-j];
            fields[i][3-j] = fields[i][j]^fields[i][3-j];
            fields[i][j] = fields[i][j]^fields[i][3-j];
            j++;
        }
        i ++;
    }
}


/* when the key 'up' is pressed */
void keyUp(){
    printf("press key up\n");
    transposeDiag();
    mergeLeft();
    transposeDiag();
    generateNum();
}


/* transpose the matrix around the main diagonal */
void transposeDiag()
{
    char i,j;

    i = 0;
    while(i < 4)
    {
        j = i + 1;
        while(j < 4)
        {
            fields[i][j] = fields[i][j]^fields[j][i];
            fields[j][i] = fields[i][j]^fields[j][i];
            fields[i][j] = fields[i][j]^fields[j][i];
            j++;
        }
        i++;
    }
}


/* when the key 'down' is pressed */
void keyDown(){
    printf("press key down\n");
    transposeViceDiag();
    mergeLeft();
    transposeViceDiag();
    generateNum();
}


/* transpose the matrix around the vice diagonal */
void transposeViceDiag()
{
    char i,j;

    i = 0;
    while(i < 4)
    {
        j = 0;
        while(j < 3 - i)
        {
            fields[i][j] = fields[3-j][3-i]^fields[i][j];
            fields[3-j][3-i] = fields[3-j][3-i]^fields[i][j];
            fields[i][j] = fields[3-j][3-i]^fields[i][j];
            j++;
        }
        i++;
    }
}


/* all numbers move and merge with the left neighbors */
void mergeLeft()
{
    char i,j,k;

    i = 0;
    while(i < 4)
    {
        for(j = 0;j < 4;j++)
        {
            //find the first non-zero grid in the row
            k = j + 1;
            if(fields[i][j] == 0)
            {
                while(k < 4 && fields[i][k] == 0)
                    k++;
                if(k < 4)
                {
                    fields[i][j] = fields[i][k];
                    fields[i][k] = 0;
                    k++;
                }    
            }

            // seek to merge numbers
            while(k < 4)
            {
                // if merge is feasible
                if(fields[i][j] == fields[i][k])
                {
                    // merge
                    fields[i][j] += fields[i][k];
                    fields[i][k] = 0;
                    // the blank grid number grows
                    blankGrid++;
                    // update the score
                    currentScore += 10;
                    if(currentScore > bestScore)
                        bestScore = currentScore;
                    // record the maximal number
                    if(fields[i][j] > maxNum)
                        maxNum = fields[i][j];
                    break;
                }
                else if(fields[i][k] == 0)
                    k++;
                else
                    break;
            }
        }
        i++;
    }
}


/* see if the player wins */
bool isWin()
{
    if(maxNum == 2048)
    {
        printf("win in C\n");
        return true;
    }
    else
        return false;
}


/* see if the player lose */
bool isLost()
{
    if(blankGrid == 0)
    {
        printf("lost in C\n");
        return true;
    }
    else
        return false;
}


