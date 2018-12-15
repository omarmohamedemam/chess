#ifndef CHECKMATEHELPERS_H_INCLUDED
#define CHECKMATEHELPERS_H_INCLUDED
#ifndef FUNCTIONS_OF_ELEMENT_H_INCLUDED
#define FUNCTIONS_OF_ELEMENT_H_INCLUDED
#include "functions.h"
int eat;
int pawn;
// i1:is a character from A to h ,j1:is a number from 1 to 8 i think
int  pawns_black_k(char i1,int j1,char i2,int j2){
int flag=0;
/*check The move of pawns at starting game*/
// why upper......................
if((j1==2) &&(i1==65||i1==66||i1==67||i1==68||i1==69||i1==70||i1==71||i1==72)){
    if((((j2-j1)==1)||((j2-j1)==2)) && i1==i2){
        flag=1;
    }}
/*check if the move not from stat*/
else if((j1==3||j1==4||j1==5||j1==6||j1==7) && (j2-j1)==1 && i1==i2){
            /*if(j2==8){
                change it with any piece like king or >>
            }*/
    flag=1;
    }
    /*if not be the move of pawns*/
    else{
        flag=0;
    }

    pawn=flag;
  return flag;
}
/*there are some cases about if he enter for example at start A2 to A1 so it will print repeat again because it wouldn't return any value*/
// he must print error..................
int pawns_white_k(char i1,int j1,char i2,int j2){
int flag=0;
/*check The move of pawns at starting game*/
// why upper......................
if((j1==7) &&(i1==65||i1==66||i1==67||i1==68||i1==69||i1==70||i1==71||i1==72)){
    if((((j1-j2)==1)||((j1-j2)==2)) && i1==i2){
        flag=1;
    }}
/*check if the move not from stat*/
else if((j1==3||j1==4||j1==5||j1==6||j1==2) && (j1-j2)==1 && i1==i2){
            /*if(j2==1){
                change it with any piece like king or >>
            }*/
    flag=1;
    }
    /*if not be the move of pawns*/
    else{
        flag=0;
    }
    pawn=flag;
  return flag;
}
//end of pawns without eating

//for black
int rock_black_k(char i1,int j1,char i2,int j2){
    int flag=0;
//when the game start
    for(int k=1;k<=8;k++){
//when it is in any place at raw 1 to 8
     if(j1==k&&(i1==65 ||i1==66||i1==67||i1==68||i1==69||i1==70||i1==71 ||i1==72) ){
        for(int i=1;i<8;i++){
            if(abs(j2-j1)==i && i1==i2){
                flag=1;
                break;
            }else if(abs(i1-i2)==i && j1==j2){
                flag=1;
                break;
            }
        }
    }
    }
        return flag;
}
//we will change all alpha char to numbers (integers)
int bishop_black_k(char i1,int j1,char i2,int j2){
//at start
int flag=0;
    for(int k=1;k<=8;k++){
        if(j1==k&&(i1==65 || i1==66||i1==67||i1==68||i1==69 || i1==70||i1==71|| i1==72)){
            for(int i=1;i<8;i++){
                if(abs(j2-j1)==i && abs((int)i2-(int)i1)==i){
                        flag=1;
                        break;
                }
            }

    }
    }

        return flag;
}
int king_k(char i1,int j1,char i2,int j2){
    int flag=0;
    for(int k=1;k<=8;k++){
        if(j1==k){
            if((abs(j2-j1)==1 && abs((int )i2-(int)i1==1))){
                        flag=1;
                        break;
            }else if(abs(j2-j1)==1 && i1==i2){
                        flag=1;
                        break;
            }else if(abs((int)i2-(int)i1)==1&&j1==j2){
                        flag=1;
                        break;
            }else {
                if(abs(j2-j1)==1 &&abs((int)i2-(int)i1)==1){
                        flag=1;
                        break;
                }

            }
        }
    }
        return flag;
}//queen is a rook + bishop
int queen_k(char i1,int j1,char i2,int j2){
int flag=0;
    for(int k=1;k<=8;k++){
        if(j1==k &&(i1==65 || i1==66||i1==67||i1==68||i1==69 || i1==70||i1==71|| i1==72)){
            for(int i=1;i<8;i++){
                if(abs(j2-j1)==i && abs((int)i2-(int)i1)==i){
                        flag=1;
                        break;
                }else if(abs(j2-j1)==i && i1==i2){
                    flag=1;
                    break;
                }else if(abs(i1-i2)==i && j1==j2){
                    flag=1;
                    break;
                }
            }

    }
    }
        return flag;


}// i wish u to revise it :/
int knight_k(char i1,int j1,char i2,int j2){
    int flag=0;
    //we must reject the element when it out put the board
    for(int k=1;k<=8;k++){
        if((j1==k &&( i1==65|| i1==66|| i1==67|| i1==68|| i1==69|| i1==70|| i1==71| i1==72))){
            if(abs(j2-j1)==2 && (abs((int)i2-(int)i1)==1)){
                flag=1;
                break;
            }else{
                 if((abs((int)i2-(int)i1)==2 && abs(j2-j1)==1)){
                     flag=1;
                     break;
                     }
                }
        }
    }
        return flag;
}
int pawn_eat_k(char i1,int j1,char i2,int j2,char a, char b){
    int flag=0;
    if(abs(i1-i2)==1 && abs(j1-j2)==1){
        int w ;
        w= check_eat(a,b);
        if(w==1){
            flag=1;
        }
    }
    return flag;


}
#endif // FUNCTIONS_OF_ELEMENT_H_INCLUDED



#endif // CHECKMATEHELPERS_H_INCLUDED
