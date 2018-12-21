#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include <ctype.h>
#include <windows.h>
#include "initialize.h"
#include "Checks.h"
#include "Functions_of_element.h"
#define MAX_MOVES 5500
int undo_counter;
int redo=0;
struct s_text undo[MAX_MOVES]={0};
struct s_text s_p[MAX_MOVES]={0};
int sp;
int i;
int promtoion_flag;
int un=0;// if undo is done or not
int happen=0;// count undo happened
int pro_un;// if there are promotion of undo
int eat;// if the pawn going to eat or not
int pawn=1; //revers of eat
int text_check; //right text input
char black_lost[16]={                };
char white_lost[16]={                };
int undos=0;
int undos1=0;
int b_lost=0;//black lost counter
int w_lost=0;//white lost counter
int comp=0;
int comp1=0;
char cl;
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
// count save game times
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
                if(undo_counter>0){
                        if(s_p[sp-1].letter[1]==undo[undo_counter-1].letter[1]&&s_p[sp-1].num[1]== undo[undo_counter-1].num[1]){
                              if(cl=='w'){
                                      undos=1;
                                      move_pieces(e,undo[undo_counter-1].letter[1],undo[undo_counter-1].num[1],undo[undo_counter-1].letter[0],undo[undo_counter-1].num[0]);
                                    undo_counter--;
                                        happen++;
                                        un=1;
                              } else if (cl=='b'){
                                        undos=1;
                                      move_pieces(e,undo[undo_counter-1].letter[1],undo[undo_counter-1].num[1],undo[undo_counter-1].letter[0],undo[undo_counter-1].num[0]);
                                    undo_counter--;
                                        happen++;
                                        un=1;
                              }

                        }
             /* if(w_lost>0 &&comp==0 ){
                        undos=1;
                          move_pieces(e,undo[undo_counter-1].letter[1],undo[undo_counter-1].num[1],undo[undo_counter-1].letter[0],undo[undo_counter-1].num[0]);
                        undo_counter--;
                            happen++;
                            un=1;
                        }else if(b_lost>0 &&comp1==0 ){
                        undos=1;
                          move_pieces(e,undo[undo_counter-1].letter[1],undo[undo_counter-1].num[1],undo[undo_counter-1].letter[0],undo[undo_counter-1].num[0]);
                        undo_counter--;
                            happen++;
                            un=1;
                        }*/
                        else{
                            undos1=1;
                           move_pieces(e,undo[undo_counter-1].letter[1],undo[undo_counter-1].num[1],undo[undo_counter-1].letter[0],undo[undo_counter-1].num[0]);
                            undo_counter--;
                                happen++;
                                un=1;
                        }
                 }

        }
        else if(t[0]=='r'||t[0]=='R'){
                if(happen>0){
                        redo=1;
                    undo_counter++;
                move_pieces(e,undo[undo_counter-1].letter[0],undo[undo_counter-1].num[0],undo[undo_counter-1].letter[1],undo[undo_counter-1].num[1]);
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
        }else if(abs(t[0]-t[2])==1){
            //this case for pawn which eat and also promotion
            b[0]=t[0];
            a[0]=(int)t[1]-48;
            b[1]=t[2];
            a[1]=(int)t[3]-48;
            b[2]=t[4];
            scan.letter[2]=b[2];
            un=0;
        }

    }
    for(int i=0 ;i<3;i++){
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
            black_lost[b_lost]=e[v][w].print;
            b_lost++;
            //comp1=1;
             red();
            printf("Opps! The Other Player Took piece Of your Pieces\n");
            reset();
            Sleep(500);

           // }
        }
       else if(e[v][w].print!=' '&& e[v][w].color=='w'){
               /* if(undos1==1&&((e[v][w].print=='p' && v+1==7)||(e[v][w].print=='r' && v+1==8)||(e[v][w].print=='n' && v+1==8)||(e[v][w].print=='b' && v+1==8)||(e[v][w].print=='q' && v+1==8)||(e[v][w].print=='k' && v+1==8))){
                    e[v][w].print=e[v][w].print;
                    e[v][w].available=e[v][w].available;
                     e[v][w].color= e[v][w].color;
                     i=i+1;

                   //change turn >>

                }else{*/
               white_lost[w_lost]=e[v][w].print;
               w_lost++;

                red();
                printf("Opps! The Other Player Took piece Of your Pieces\n");
                reset();
                Sleep(500);
                //}
        }
      else if(e[v][w].print==' '&& e[z][x].color=='b'&& undos==1&&!promtoion_flag){//to take the value of eaten peace
                      if(w_lost>0 ){
                          e[v][w].print=e[z][x].print;
                          e[v][w].color= e[z][x].color;
                           e[v][w].available= e[z][x].available;
                         e[z][x].print=white_lost[w_lost-1];
                          e[z][x].color= 'w';
                         white_lost[w_lost-1]=' ';
                         w_lost--;
                         comp=1;
                         }
      }else if(e[v][w].print==' '&& e[z][x].color=='w'&& undos==1&&!promtoion_flag){
                        if(b_lost>0){
                          e[v][w].print=e[z][x].print;
                          e[v][w].color= e[z][x].color;
                         e[z][x].print=black_lost[b_lost-1];
                          e[z][x].color='b';
                             black_lost[b_lost-1]=' ';
                             b_lost--;
                             comp1=1;
                     }
      }else if(e[v][w].print==' '&& e[z][x].color=='b'&&(undos||!undos) && promtoion_flag==1){
                            if(w==x){
                            e[z][x].print=' ';
                            e[z][x].color='n';
                            e[z][x].available=0;
                            e[v][w].print='P';
                            e[v][w].color='b';
                            e[v][w].available=1;
                            }else {
                            e[z][x].print=white_lost[b_lost-1];
                            e[z][x].color='w';
                            e[z][x].available=1;
                            e[v][w].print='P';
                            e[v][w].color='b';
                            e[v][w].available=1;
                            white_lost[w_lost-1]=' ';
                            }

promtoion_flag=0;
                         //w_lost=0;
comp=1;
comp1=1;
      }else if(e[v][w].print==' '&& e[z][x].color=='w'&&(undos||!undos)&& promtoion_flag==1){

                            if(x==w){
                            e[z][x].print=' ';
                            e[z][x].color='n';
                            e[z][x].available=0;
                            e[v][w].print='p';
                            e[v][w].color='w';
                            e[v][w].available=1;
                            }else {
                            e[z][x].print=black_lost[b_lost-1];
                            e[z][x].color='b';
                            e[z][x].available=1;
                            e[v][w].print='p';
                            e[v][w].color='w';
                            e[v][w].available=1;
                            black_lost[b_lost-1]=' ';
                            }
                            promtoion_flag=0;
                                comp1=1;
                                comp=1;
                                //b_lost=0;
       }else if(e[v][w].print==' '&& e[z][x].color=='b'&& redo==1&&!promtoion_flag){

                          e[v][w].print=e[z][x].print;
                          e[v][w].color= e[z][x].color;
                           e[v][w].available= e[z][x].available;
                         e[z][x].print=white_lost[w_lost-1];
                          e[z][x].color= 'w';
                         white_lost[w_lost-1]=' ';
                         w_lost--;
                         comp=1;
       }else if(e[v][w].print==' '&& e[z][x].color=='w'&& redo==1&&!promtoion_flag){
                                     e[v][w].print=e[z][x].print;
                          e[v][w].color= e[z][x].color;
                         e[z][x].print=black_lost[b_lost-1];
                          e[z][x].color='b';
                             black_lost[b_lost-1]=' ';
                             b_lost--;
                             comp1=1;

       }
        if(undos1==1){
            e[v][w].print=e[z][x].print;
             e[z][x].print=' ';
             int temp =e[v][w].available;
            e[v][w].available=e[z][x].available;
             e[z][x].available=temp;
            char temp1 = e[v][w].color;
             e[v][w].color=e[z][x].color;
           e[z][x].color=temp1;
             clrscr();
       /* if(w_lost>0||b_lost>0){
                comp=1;
             comp1=1;
             }else{*/
           /* if(white_lost[w_lost+1]==' '){
                comp=1;
            }else if(black_lost[b_lost+1]==' '){
                comp1=1;
            }else{
             comp=0;
             comp1=0;
            }*/
        }
        if(undos1==0 && undos==0){
            if(white_lost[w_lost-1]==e[v][w].print){
                s_p[sp].letter[1]=c;
                s_p[sp].num[1]=d;
                sp++;
                cl='w';
            }else if(black_lost[b_lost-1]==e[v][w].print){
                s_p[sp].letter[1]=c;
                s_p[sp].num[1]=d;
                sp++;
                cl='b';
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

        }
undos1=0;
undos=0;



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
    if(kind==' '){
        printf("Error ");
    }else{
            red();
        printf("It's Not Your Turn\n");
        a=0;
    reset();
    }
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
/*int save_move_p(char i2,int j2,int promo){

    pro_undo[pro_counter].letter[1]=i2;
    pro_undo[pro_counter].num[1]=j2;
    pro_counter++;

    return 0;

}*/
int save_move_a(char i1,int j1,char i2,int j2){
    undo[undo_counter].letter[0]=i1;
    undo[undo_counter].letter[1]=i2;
    undo[undo_counter].num[0]=j1;
    undo[undo_counter].num[1]=j2;
    undo_counter++;

    return 0;

}
//------------------------------------------------------------------------------
#endif // FUNCTIONS_H_INCLUDED
