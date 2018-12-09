#ifndef FUNCTIONS_H_INCLUDED
#include <ctype.h>
#include "initialize.h"
#define FUNCTIONS_H_INCLUDED

//clear screen function
void clrscr()
{
    system("@cls||clear");
}
//------------------------------------------------------------------------------------------
 struct s_text scan_move(){
     struct s_text scan;
    printf("Enter your movement:");
    int flag=0;
    int a[2];
    char b[3];
    for(int i=0 ;i<2;i++){
        scanf(" %c",&b[i]);
        scanf("%1d",&a[i]);
    }
    /* in case of promotion
     scanf(" %c",&b[3]);*/
    for(int i=0 ;i<2;i++){
        b[i]=toupper(b[i]);
    }
    //check logic
       //if digit $3 if alpha
            //check boundaries
             if( b[0]>64 && b[0]<73 && b[1]>64 && b[1]<73 && a[0]>0 && a[0]<9 &&  a[1]>0 && a[1]<9 ){
                flag=1;
            }
    if(flag==1){
       for(int i=0 ;i<2;i++){
            scan.num[i]=a[i];
        }
        for(int i=0 ;i<2;i++){
            scan.letter[i]=b[i];
        }
        return scan;
    }
    else{
        printf("ERROR: Invalid Input\n");
    }
}
//-------------------------------------------------------------------------------------------------
struct board_str move_pieces(struct board_str e[8][8],char a,int b,char c,int d){
        int w=c-'A';
        int v=d-1;
        int x=a-'A';
        int z=b-1;
        e[w][v].print=e[x][z].print;
        e[x][z].print=' ';
        char k =e[w][v].print;
        int temp =e[w][v].available;
        e[w][v].available=e[x][z].available;
        e[x][z].available=temp;
        char temp1 = e[w][v].color;
        e[w][v].color=e[x][z].color;
        e[x][z].color=temp1;
        clrscr();
        return e[8][8];
}


#endif // FUNCTIONS_H_INCLUDED
