#ifndef FUNCTIONS_OF_ELEMENT_H_INCLUDED
#define FUNCTIONS_OF_ELEMENT_H_INCLUDED
// i1:is a character from A to Z ,j1:is a number from 1 to 7 i think 
void pawns(char i1,int j1,char i2,int j2){
int flag=0;
/*check The move of pawns at starting game*/
if(j1==2 &&(i1==65||i1==66||i1==67||i1==68||i1==69||i1==70||i1==71||i1==72)){
    if(((j2-j1)==1)||((j2-j1)==2) && i1==i2){
    flag=1;
    }}
/*check if the move not from stat*/
else if(j1==3||j1==4||j1==5||j1==6 && (j2-j1)==1 && i1==i2){
            /*if(j2==7){
                change it with any piecce
            }*/
    flag=1;
    }
    /*if not be the move of pawns*/
    else{
        flag=0;
    }
/*there are some cases about if he enter for example at start A2 to A1 so it will print repeat again because it wouldn't return any value*/
}
//For black
void pawns_black(char i2,int j2,char i1,int j1){
int flag=0;
/*check The move of pawns at starting game*/
if(j2==2 &&(i2==65||i2==66||i2==67||i2==68||i2==69||i2==70||i2==71||i2==72)){
    if(((j1-j2)==1)||((j1-j2)==2) && i1==i2){
    flag=1;
        }
 }
/*check if the move not from stat*/
else if(j2==3||j2==4||j2==5||j2==6 && (j1-j2)==1 && i1==i2){
            /*if(j1==7){
                change it with any piecce
            }*/
    flag=1;
    }
    /*if not be the move of pawns*/
    else  {
    flag=0;
    }
/*there are some cases about if he enter for example at start A2 to A1 so it will print repeat again because it wouldn't return any value*/
}
//end of pawns without eating

/*//to eat
void pawns_eating(char i1,int j1,char i2,int j2){
    flag=0;
//if peaces  besides each others at stating
if(j1==2 &&(i1==65||i1==66||i1==67||i1==68||i1==69||i1==70||i1==71)){
    if((j2-j1)==1 && (((int)i2-(int)i1)==1)){
        flag=1;
    }//if that index is a last index in the board
    else if(j1==2 && i1==72){
            if((j2-j1==1)&&(((int)i1-(int)i2)==1))
                    flag=1;
            }else{
                flag=0;
    }
}//if peaces  besides each others at game
else if((j1==3||j1==4||j1==5||j1==6)&&(i1==65||i1==66||i1==67||i1==68||i1==69||i1==70||i1==71)){
    if((j2-j1)=1 && (((int)i2-(int)i1)=1){
       flag=1;
       }//if that index is a last index in the board
       else if ((j1==3||j1==4||j1==5||j1==6)&& i1==72){
                if((j2-j1==1)&&(((int)i1-(int)i2)==1)){
                    flag=1;
            }else{
                flag=0;
                 }
        }
    }else{
        flag=0;
        }
}
//for black
//change input to be i2 to i1
void pawns_eating_black(char i2,int j2,char i1,int j1){
    flag=0;
//if peaces  besides each others at stating
if(j2==2 &&(i2==65||i2==66||i2==67||i2==68||i2==69||i2==70||i2==71)){
    if((j1-j2)==1 && (((int)i1-(int)i2)==1)){
        flag=1;
    }//if that index is a last index in the board
    else if(j2==2 && i2==72){
            if((j1-j2==1)&&(((int)i2-(int)i1)==1)){
                    flag=1;
            }else{
                flag=0;
            }
        }
    //if peaces  besides each others at game
else if((j2==3||j2==4||j2==5||j2==6)&&(i2==65||i2==66||i2==67||i2==68||i2==69||i2==70||i2==71)){
    if((j1-j2)=1 && (((int)i1-(int)i2)=1){
       flag=1;
       }//if that index is a last index in the board
       else if ((j2==3||j2==4||j2==5||j2==6)&& i2==72){
                if((j1-j2==1)&&(((int)i2-(int)i1)==1)){
                    flag=1;
                }else{
                flag=0;
                }
        }
    }else{
        flag=0;
        }
}
*/

void rock(char i1,int j1,char i2,int j2){
    int flag=0;
    //when the game start
if((j1==1 && i1==72)||(j1==1 && i1==65)){
    /*if((abs(j2-j1)==1 || abs(j2-j1)==2 || abs(j2-j1)==3 || abs(j2-j1)==4 || abs(j2-j1)==5 || abs(j2-j1)==6 || abs(j2-j1)==7) && i1=i2){
        flag1;
    }else if((abs(i1-i2)==1 || abs(i1-i2)==2 || abs(i1-i2)==3 || abs(i1-i2)==4 || abs(i1-i2)==5 || abs(i1-i2)==6 || abs(i1-i2)==7 ) && j1=j2){
    flag=1;
    }else{
    flag=0;
    }*/
}//when it is in any place at raw 1
else if(j1==1&&(i1==66||i1==67||i1==68||i1==69||i1==70||i1==71) ){
    if((abs(j2-j1)==1 || abs(j2-j1)==2 || abs(j2-j1)==3 || abs(j2-j1)==4 || abs(j2-j1)==5 || abs(j2-j1)==6 || abs(j2-j1)==7) && i1==i2){
        flag=1;
    }else if((abs(i1-i2)==1 || abs(i1-i2)==2 || abs(i1-i2)==3 || abs(i1-i2)==4 || abs(i1-i2)==5 || abs(i1-i2)==6 || abs(i1-i2)==7 ) && j1==j2){
    flag=1;
    }
}//when it is in any place at raw 2
else if(j1==2&&(i1==66||i1==67||i1==68||i1==69||i1==70||i1==71) ){
    if((abs(j2-j1)==1 || abs(j2-j1)==2 || abs(j2-j1)==3 || abs(j2-j1)==4 || abs(j2-j1)==5 || abs(j2-j1)==6 || abs(j2-j1)==7) && i1==i2){
        flag=1;
    }else if((abs(i1-i2)==1 || abs(i1-i2)==2 || abs(i1-i2)==3 || abs(i1-i2)==4 || abs(i1-i2)==5 || abs(i1-i2)==6 || abs(i1-i2)==7 ) && j1==j2){
    flag=1;
    }
}//when it is in any place at raw 3
else if(j1==3&&(i1==66||i1==67||i1==68||i1==69||i1==70||i1==71) ){
    if((abs(j2-j1)==1 || abs(j2-j1)==2 || abs(j2-j1)==3 || abs(j2-j1)==4 || abs(j2-j1)==5 || abs(j2-j1)==6 || abs(j2-j1)==7) && i1==i2){
        flag=1;
    }else if((abs(i1-i2)==1 || abs(i1-i2)==2 || abs(i1-i2)==3 || abs(i1-i2)==4 || abs(i1-i2)==5 || abs(i1-i2)==6 || abs(i1-i2)==7 ) && j1==j2){
    flag=1;
    }
}//when it is in any place at raw 4
else if(j1==4&&(i1==66||i1==67||i1==68||i1==69||i1==70||i1==71) ){
    if((abs(j2-j1)==1 || abs(j2-j1)==2 || abs(j2-j1)==3 || abs(j2-j1)==4 || abs(j2-j1)==5 || abs(j2-j1)==6 || abs(j2-j1)==7) && i1==i2){
        flag=1;
    }else if((abs(i1-i2)==1 || abs(i1-i2)==2 || abs(i1-i2)==3 || abs(i1-i2)==4 || abs(i1-i2)==5 || abs(i1-i2)==6 || abs(i1-i2)==7 ) && j1==j2){
    flag=1;
    }
}//when it is in any place at raw 5
else if(j1==5&&(i1==66||i1==67||i1==68||i1==69||i1==70||i1==71) ){
    if((abs(j2-j1)==1 || abs(j2-j1)==2 || abs(j2-j1)==3 || abs(j2-j1)==4 || abs(j2-j1)==5 || abs(j2-j1)==6 || abs(j2-j1)==7) && i1==i2){
        flag=1;
    }else if((abs(i1-i2)==1 || abs(i1-i2)==2 || abs(i1-i2)==3 || abs(i1-i2)==4 || abs(i1-i2)==5 || abs(i1-i2)==6 || abs(i1-i2)==7 ) && j1==j2){
    flag=1;
    }
}//when it is in any place at raw 6
else if(j1==6&&(i1==66||i1==67||i1==68||i1==69||i1==70||i1==71) ){
    if((abs(j2-j1)==1 || abs(j2-j1)==2 || abs(j2-j1)==3 || abs(j2-j1)==4 || abs(j2-j1)==5 || abs(j2-j1)==6 || abs(j2-j1)==7) && i1==i2){
        flag=1;
    }else if((abs(i1-i2)==1 || abs(i1-i2)==2 || abs(i1-i2)==3 || abs(i1-i2)==4 || abs(i1-i2)==5 || abs(i1-i2)==6 || abs(i1-i2)==7 ) && j1==j2){
    flag=1;
    }
}//when it is in any place at raw 7
else if(j1==7&&(i1==66||i1==67||i1==68||i1==69||i1==70||i1==71) ){
    if((abs(j2-j1)==1 || abs(j2-j1)==2 || abs(j2-j1)==3 || abs(j2-j1)==4 || abs(j2-j1)==5 || abs(j2-j1)==6 || abs(j2-j1)==7) && i1==i2){
        flag=1;
    }else if((abs(i1-i2)==1 || abs(i1-i2)==2 || abs(i1-i2)==3 || abs(i1-i2)==4 || abs(i1-i2)==5 || abs(i1-i2)==6 || abs(i1-i2)==7 ) && j1==j2){
            flag=1;
    }
}//when it isn't in any place at chess
else{
flag=0;
}
}
//for black
void rock_black(char i1,int j1,char i2,int j2){
    int flag=0;
    //when the game start
if((j1==1 && i1==72)||(j1==1 && i1==65)){
    /*if((abs(j2-j1)==1 || abs(j2-j1)==2 || abs(j2-j1)==3 || abs(j2-j1)==4 || abs(j2-j1)==5 || abs(j2-j1)==6 || abs(j2-j1)==7) && i1=i2){
        flag1;
    }else if((abs(i1-i2)==1 || abs(i1-i2)==2 || abs(i1-i2)==3 || abs(i1-i2)==4 || abs(i1-i2)==5 || abs(i1-i2)==6 || abs(i1-i2)==7 ) && j1=j2){
    flag=1;
    }else{
    flag=0;
    }*/
}//when it is in any place at raw 1
else if(j2==1 &&(i2==66||i2==67||i2==68||i2==69||i2==70||i2==71)){
    if((abs(j2-j1)==1 || abs(j2-j1)==2 || abs(j2-j1)==3 || abs(j2-j1)==4 || abs(j2-j1)==5 || abs(j2-j1)==6 || abs(j2-j1)==7) && i1==i2){
        flag=1;
    }else if((abs(i1-i2)==1 || abs(i1-i2)==2 || abs(i1-i2)==3 || abs(i1-i2)==4 || abs(i1-i2)==5 || abs(i1-i2)==6 || abs(i1-i2)==7 ) && j1==j2){
    flag=1;
    }
}//when it is in any place at raw 2
else if(j2==2&&(i2==66||i2==67||i2==68||i2==69||i2==70||i2==71) ){
    if((abs(j2-j1)==1 || abs(j2-j1)==2 || abs(j2-j1)==3 || abs(j2-j1)==4 || abs(j2-j1)==5 || abs(j2-j1)==6 || abs(j2-j1)==7) && i1==i2){
        flag=1;
    }else if((abs(i1-i2)==1 || abs(i1-i2)==2 || abs(i1-i2)==3 || abs(i1-i2)==4 || abs(i1-i2)==5 || abs(i1-i2)==6 || abs(i1-i2)==7 ) && j1==j2){
    flag=1;
    }
}//when it is in any place at raw 3
else if(j2==3&&(i2==66||i2==67||i2==68||i2==69||i2==70||i2==71) ){
    if((abs(j2-j1)==1 || abs(j2-j1)==2 || abs(j2-j1)==3 || abs(j2-j1)==4 || abs(j2-j1)==5 || abs(j2-j1)==6 || abs(j2-j1)==7) && i1==i2){
        flag=1;
    }else if((abs(i1-i2)==1 || abs(i1-i2)==2 || abs(i1-i2)==3 || abs(i1-i2)==4 || abs(i1-i2)==5 || abs(i1-i2)==6 || abs(i1-i2)==7 ) && j1==j2){
    flag=1;
    }
}//when it is in any place at raw 4
else if(j2==4&&(i2==66||i2==67||i2==68||i2==69||i2==70||i2==71) ){
    if((abs(j2-j1)==1 || abs(j2-j1)==2 || abs(j2-j1)==3 || abs(j2-j1)==4 || abs(j2-j1)==5 || abs(j2-j1)==6 || abs(j2-j1)==7) && i1==i2){
        flag=1;
    }else if((abs(i1-i2)==1 || abs(i1-i2)==2 || abs(i1-i2)==3 || abs(i1-i2)==4 || abs(i1-i2)==5 || abs(i1-i2)==6 || abs(i1-i2)==7 ) && j1==j2){
    flag=1;
    }
}//when it is in any place at raw 5
else if(j2==5&&(i2==66||i2==67||i2==68||i2==69||i2==70||i2==71) ){
    if((abs(j2-j1)==1 || abs(j2-j1)==2 || abs(j2-j1)==3 || abs(j2-j1)==4 || abs(j2-j1)==5 || abs(j2-j1)==6 || abs(j2-j1)==7) && i1==i2){
        flag=1;
    }else if((abs(i1-i2)==1 || abs(i1-i2)==2 || abs(i1-i2)==3 || abs(i1-i2)==4 || abs(i1-i2)==5 || abs(i1-i2)==6 || abs(i1-i2)==7 ) && j1==j2){
    flag=1;
    }
}//when it is in any place at raw 6
else if(j2==6&&(i2==66||i2==67||i2==68||i2==69||i2==70||i2==71) ){
    if((abs(j2-j1)==1 || abs(j2-j1)==2 || abs(j2-j1)==3 || abs(j2-j1)==4 || abs(j2-j1)==5 || abs(j2-j1)==6 || abs(j2-j1)==7) && i1==i2){
        flag=1;
    }else if((abs(i1-i2)==1 || abs(i1-i2)==2 || abs(i1-i2)==3 || abs(i1-i2)==4 || abs(i1-i2)==5 || abs(i1-i2)==6 || abs(i1-i2)==7 ) && j1==j2){
    flag=1;
    }
}//when it is in any place at raw 7
else if(j1==7&&(i1==66||i1==67||i1==68||i1==69||i1==70||i1==71) ){
    if((abs(j2-j1)==1 || abs(j2-j1)==2 || abs(j2-j1)==3 || abs(j2-j1)==4 || abs(j2-j1)==5 || abs(j2-j1)==6 || abs(j2-j1)==7) && i1==i2){
        flag=1;
    }else if((abs(i1-i2)==1 || abs(i1-i2)==2 || abs(i1-i2)==3 || abs(i1-i2)==4 || abs(i1-i2)==5 || abs(i1-i2)==6 || abs(i1-i2)==7 ) && j1==j2){
            flag=1;
    }
}//when it isn't in any place at chess
else{
flag=0;
}
}
//end of rock
#endif // FUNCTIONS_OF_ELEMENT_H_INCLUDED
