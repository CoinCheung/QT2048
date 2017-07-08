#include"debug.h"


/************************************************************/
/* methods implementations */
/************************************************************/
/* print the fields */
void printfield(){
    char i,j;
    for(i = 0; i < row; i++){
        for(j = 0; j < column; j++)
            printf("%d, ",fields[i][j]);
        printf("\n");
    }
}


/* test the randInt() method */
void testRandInt(){
    int num = 0;
    while(1){
        printf("randInt() output is:%d\n",randInt()%2);
        num++;
        if( num == 1000)
            break;
    }
}



/* entrance of the program if debug is implemented */
void main(){
    char i;

    int (*a)[4] = (int**)malloc(sizeof(int)*4*4);
    fields = (int**)malloc(sizeof(int*)*4);
    for(i = 0; i < 4; i++)
        fields[i] = a + i;
    
    row = 4;
    column = 4;
    initGame();
}

