#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <ctype.h>
#include <windows.h>
#include "initialize.h"
#include "Checks.h"
#include "Functions_of_element.h"
#define MAX_MOVES 5500
struct s_text undo[MAX_MOVES];
int undo_counter=0;// count save game times
int un=0;// if undo is done or not
int happen=0;// count undo happened
int pro_un;// if there are promotion of undo
int eat;// if the pawn going to eat or not
int pawn=1; //revers of eat
int text_check; //right text input
char black_lost[16]={                };
char white_lost[16]={                };
int t=0;//black lost counter
int k=0;//white lost counter
struct board_str move_pieces(struct board_str e[8][8],char a,int b,char c,int d);

void gotoxy(int x, int y) {
static HANDLE h = NULL;
if(!h) h = GetStdHandle(STD_OUTPUT_HANDLE);
COORD c = { x, y };
SetConsoleCursorPosition(h,c);
}
//clear screen function
void clrscr()
{
    system("@cls||clear");
}
//------------------------------------------------------------------------------------------
// scan the input and contribute it as the different input
 struct s_text scan_move(struct board_str e[8][8]){
     struct s_text scan;
    printf("\t\t\tEnter your movement:");
    int flag=0;
    char t[100];
    scanf("%s",&t);
    int a[2];
    char b[3];
    if(strlen(t)==4){
        b[0]=t[0];
        a[0]=(int)t[1]-48;
        b[1]=t[2];
        a[1]=(int)t[3]-48;
        un=0;
    }
    else if(strlen(t)==1){
        if(t[0]=='u'||t[0]=='U'){
            move_pieces(e,undo[undo_counter-1].letter[1],undo[undo_counter-1].num[1],undo[undo_counter-1].letter[0],undo[undo_counter-1].num[0]);
            undo_counter--;
            happen++;
            un=1;
        }
        else if(t[0]=='r'||t[0]=='R'){
                if(happen>0){
                    undo_counter++;
                move_pieces(e,undo[undo_counter].letter[0],undo[undo_counter].num[0],undo[undo_counter].letter[1],undo[undo_counter].num[1]);
                }
                else{
                    red();
                    printf("ERROR: You Must Do Undo To Be Able To Re-Do\n");
                    reset();
                    Sleep(500);
                }

        }
        else if(t[0]=='q'||t[0]=='Q'){
            //APPLAY quit
        }
        else if(t[0]=='s'||t[0]=='S'){
            //APPLAY save
        }
        else{
            flag=0;
        }
    }else if (strlen(t)==5){
        //promotion case
        if(t[0]==t[2]){
            b[0]=t[0];
            a[0]=(int)t[1]-48;
            b[1]=t[2];
            a[1]=(int)t[3]-48;
            b[2]=t[4];
            scan.letter[2]=b[2];
            un=0;
        }

    }
    for(int i=0 ;i<2;i++){
        b[i]=toupper(b[i]);
    }
    //check logic
         //check boundaries
             if( b[0]>64 && b[0]<73 && b[1]>64 && b[1]<73 && a[0]>0 && a[0]<9 &&  a[1]>0 && a[1]<9 ){
                flag=1;
            }
            //moving to the out put
    if(flag==1 ){
       for(int i=0 ;i<2;i++){
            scan.num[i]=a[i];
        }
        for(int i=0 ;i<2;i++){
            scan.letter[i]=b[i];
        }
        text_check=1;
        return scan;

    }
    else if((!un) && (flag==0)){
            red();
        printf("ERROR: Invalid Input\n");
    reset();
        text_check=0;
    }
}
//-------------------------------------------------------------------------------------------------
//move pieces and its all values
struct board_str move_pieces(struct board_str e[8][8],char a,int b,char c,int d){
        int w=c-'A';
        int v=d-1;
        int x=a-'A';
        int z=b-1;
        if(e[v][w].print!=' '&& e[v][w].color=='b'){
            black_lost[t]=e[v][w].print;
            t++;
             red();
            printf("Opps! The Other Player Took piece Of your Pieces\n");
            reset();
            Sleep(500);
        }
        if(e[v][w].print!=' '&& e[v][w].color=='w'){
           white_lost[k]=e[v][w].print;
           k++;
            red();
            printf("Opps! The Other Player Took piece Of your Pieces\n");
            reset();
            Sleep(500);
        }
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
//give the value of turn 0 for the white and 1 for the black
int whose_turn(int counter){
    int a;
    printf("\t\t\tThis is:");
    if (counter%2==0){
        printf("   White Player Turn\n");
        a=0;
    }
    else if (counter%2!=0){
        printf("   Black Player Turn\n");
        a=1;
    }
    else if(counter==0){
        a=0;
    }
    return a;
}
//------------------------------------------------------------------------------------------------------
//takes the move and check if it's your turn or not the send you to your function in functions-of_elements.h
int element_check(char kind,char colors,char colore,int color,char i1,int j1,char i2,int j2){
    int a;
    int w,v,x,z;
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
                    a=bishop(i1,j1,i2,j2);
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
                    eat =pawn_eat(i1,j1,i2,j2,colors,colore);
                     w =pawns_black(i1,j1,i2,j2);
                    a=w||eat;
                    break;
                case('p'):
                    eat =pawn_eat(i1,j1,i2,j2,colors,colore);
                     x=pawns_white(i1,j1,i2,j2);
                     a=eat||x;
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
//------------------------------------------------------------------------
//keep the turn printed on
void fixed_turn(int a){
    if(a%2==0){
        yellow();
        printf("\t\t\t\tWHITE PLAYER IS PLAYING\n");
        reset();
    }
    else if(a%2!=0){
        yellow();
        printf("\t\t\t\tBLACK PLAYER IS PLAYING\n");
        reset();
    }
}
//----------------------------------------------------------------------------
//make the promotion
void make_promo(struct board_str e[8][8],char i2,int j2,char n){
    if(j2==8){
        e[j2-1][((int)i2-'A')].print=toupper(n);
    }
    else if(j2==1){
        e[j2-1][((int)i2-'A')].print=tolower(n);
    }
    yellow();
        printf("Congratulations! You've Promoted your Pawn\n");
    reset();
    Sleep(500);
}
//------------------------------------------------------------------
//saves every move
int save_move(char i1,int j1,char i2,int j2,int promo){
    undo[undo_counter].letter[0]=i1;
    undo[undo_counter].letter[1]=i2;
    undo[undo_counter].num[0]=j1;
    undo[undo_counter].num[1]=j2;
    if(promo ==1){
        return 1;
    }
    undo_counter++;

    return 0;

}
//------------------------------------------------------------------------------
#endif // FUNCTIONS_H_INCLUDED
