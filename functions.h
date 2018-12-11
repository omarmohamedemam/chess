#ifndef FUNCTIONS_H_INCLUDED
#include <ctype.h>
#include "initialize.h"
#include "Functions_of_element.h"
#define FUNCTIONS_H_INCLUDED
int text_check;
//clear screen function
void clrscr()
{
    system("@cls||clear");
}
//------------------------------------------------------------------------------------------
 struct s_text scan_move(){
     struct s_text scan;
    printf("\t\tEnter your movement:");
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
        text_check=1;
        return scan;

    }
    else{
            red();
        printf("ERROR: Invalid Input\n");
    reset();
        text_check=0;
    }
}
//-------------------------------------------------------------------------------------------------
struct board_str move_pieces(struct board_str e[8][8],char a,int b,char c,int d){
        int w=c-'A';
        int v=d-1;
        int x=a-'A';
        int z=b-1;
        e[v][w].print=e[z][x].print;
        e[z][x].print=' ';
        int temp =e[v][w].available;
        e[v][w].available=e[z][x].available;
        e[z][x].available=temp;
        char temp1 = e[v][w].color;
        e[v][w].color=e[z][x].color;
        e[z][x].color=temp1;
        clrscr();
        return e[8][8];
}
//----------------------------------------------------------------------------------------------------
int whose_turn(int counter){
    int a;
    printf("This is:\n");
    if (counter%2==0){
        printf("\tWhite Player Turn\n");
        a=0;
    }
    else if (counter%2!=0){
        printf("\tBlack Player Turn\n");
        a=1;
    }
    else if(counter==0){
        a=0;
    }
    return a;
}
//------------------------------------------------------------------------------------------------------
int first_check(char kind,char colors,int color,char i1,int j1,char i2,int j2){
    int a;
    if((colors=='b' && color==1 )||(colors=='w' && color==0)){
            switch(kind){
                case('R'):
                case('r'):
                    a=rock_black(i1,j1,i2,j2);
                    break;
                case('N'):
                case('n'):
                    a=knight(i1,j1,i2,j2);
                    break;
                case('B'):
                case('b'):
                    a=bishop_black(i1,j1,i2,j2);
                    break;
                case('K'):
                case('k'):
                    a=king(i1,j1,i2,j2);
                    break;
                case('Q'):
                case('q'):
                    a=queen(i1,j1,i2,j2);
                    break;
                case('P'):
                    a=pawns_black(i1,j1,i2,j2);
                    break;
                case('p'):
                    a=pawns_white(i1,j1,i2,j2);
                    break;
            }

    }
    else{
            red();
        printf("It's Not Your Turn\n");
        a=0;
    reset();
    }
return a;

}


#endif // FUNCTIONS_H_INCLUDED
