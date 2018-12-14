#ifndef CHECKMATES_H_INCLUDED
#define CHECKMATES_H_INCLUDED
#include "check.h"
int flag=0;
//assume that the black player played to a[o][p]
int o,p//place of certain peace
int x,y//the place of white king
//first we will search for white king
int king_w_check_mate(char kind,char colors,int color){
 if(colors=='w'&& kind=='k'){
       if(color==1){
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(a[i][j]=='k'){
                        x=i,y=j;
                    }
                }
            }
        }else if(color==0){
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(a[i][j]=='k'){
                        x=i,y=j;
                    }
                }
            }
        }

    }
    //we want to check what is the black peace
    if(a[o][p]=='R')//here we assume that the place of a[o][p] == rook
    a1=rock_black(o,p,x,y);//check if the rook can kill or check the king
    //there are check about there are any one block it from ordinary check
    if(a1==1){// there is check
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(a[i][j]==' ' && king(x,y,i,j)==1 &&/*no any peace of black can check mate it*/ ){//check if there are free way and king can move to it
//here i should play and complete game
flag=1;
                    }else if(a[i][j]==' ' && king(x,y,i,j)==0){//if he cant move
                        if(/*white peaces can block from (o,p to x,y there is loop and check all element can go there)*/){//can his peaces to protect him
                            flag=1;
                        }else{
                                    // say check mate
                                    flag=0;
                        }


                    }else if(a[i][j]==' ' && king(x,y,i,j)==1 ){
                        if(/*black any peaces can go to this i and j */){
                            if(/*white peaces can block*/){
                                //complete
                                flag=1;
                            }else{
                            //check mate
                            flag=0;
                            }
                        }


                    }

                }
            }


    }
    if (flag==0){
        printf("Game over")
    }
}
//


#endif // CHECKMATES_H_INCLUDED
