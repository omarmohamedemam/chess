#ifndef CHECKMATEHELPERS_H_INCLUDED
#define CHECKMATEHELPERS_H_INCLUDED
#include "functions.h"
#include "checkmate.h"
int eat;// if the pawn going to eat or not
int pawn; //revers of eat
struct s_text expected_moves_b[100];//moves which will be compared at the end
int expected_move_counter_b;// its counter
struct s_text expected_moves_w[100];//moves which will be compared at the end
int expected_move_counter_w;// its counter
//the same at function of elements put without error massage for checkmate
//-------------------------------------------------------------------------
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
//------------------------------------------------------------------------
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
//-------------------------------------------------------------
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
//---------------------------------------------------------------
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
//-----------------------------------------------------------------
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
//--------------------------------------------------------------------------
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
//------------------------------------------------------------------------------
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
//---------------------------------------------------------------
int check_eat_k(char a,char b){
  int flag=0;
  if(a=='b'&&b=='w'){
    flag =1;
  }
  else if (a=='w'&&b=='b'){
    flag =1;
  }
    return flag;
}
//---------------------------------------------------------------------------
int pawn_eat_k(char i1,int j1,char i2,int j2,char a, char b){
    int flag=0;
    if(abs(i1-i2)==1 && abs(j1-j2)==1){
        int w ;
        w= check_eat_k(a,b);
        if(w==1){
            flag=1;
        }
    }
    return flag;


}
//-----------------------------------------------------------------------
int x;//مش فاحاد ايه بس شكله حاك مهمة
//function check if any element could eat the threat of white king
void eat_test_while_black_under_threat(struct board_str a[8][8],struct saved_place save [16]){//the place of opp.peace
        struct s_text m[16];
        int a1;
        int eat_count=0;
                for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                        if(a[i][j].print !=' '&& a[i][j].color=='b'){
                                int f_num=i+1;
                                char f_ch=j+65;
                            switch(a[i][j].print){
                                case('R')://check if black piece could be eaten from white piece
                                    a1=rock_black_k(f_ch,f_num,save[0].s_ch,save[0].s_num);//place of white peace to black peace
                                    break;
                                case('N'):
                                    a1=knight_k(f_ch,f_num,save[0].s_ch,save[0].s_num);
                                    break;
                                case('B'):
                                    a1=bishop_black_k(f_ch,f_num,save[0].s_ch,save[0].s_num);
                                    break;

                                case('Q'):
                                    a1=queen_k(f_ch,f_num,save[0].s_ch,save[0].s_num);
                                    break;
                                case('P'):
                                    eat=pawn_eat_k(f_ch,f_num,save[0].s_ch,save[0].s_num,a[i][j].color,'w');
                                     x=pawns_black_k(f_ch,f_num,save[0].s_ch,save[0].s_num);
                                     a1=eat||x;
                                    break;
                            }
                            int b1 =way_check(a,f_ch,f_num,save[0].s_ch,save[0].s_num,a[i][j].print);
                            if(b1 && a1){
                                expected_moves_b[expected_move_counter_b].letter[0]=f_ch;
                                expected_moves_b[expected_move_counter_b].num[0]=f_num;
                                expected_moves_b[expected_move_counter_b].letter[1]=save[0].s_ch;
                                expected_moves_b[expected_move_counter_b].num[1]=save[0].s_num;
                                expected_move_counter_b++;
                            }
                        }
                }
            }

}
//----------------------------------------------------------------------------------------------------------------
//function check if any element could eat the threat of black king
void eat_test_while_white_under_threat(struct board_str a[8][8],struct saved_place save [16]){//the place of opp.peace
    int a1;
        struct s_text m[16];
        int eat_count=0;
                for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                        if(a[i][j].print !=' '&& a[i][j].color=='w'){
                                int f_num=i+1;
                                char f_ch=j+65;
                            switch(a[i][j].print){
                                case('r')://check if black piece could be eaten from white piece
                                    a1=rock_black_k(f_ch,f_num,save[0].s_ch,save[0].s_num);//place of white peace to black peace
                                    break;
                                case('n'):
                                    a1=knight_k(f_ch,f_num,save[0].s_ch,save[0].s_num);
                                    break;
                                case('b'):
                                    a1=bishop_black_k(f_ch,f_num,save[0].s_ch,save[0].s_num);
                                    break;
                                case('q'):
                                    a1=queen_k(f_ch,f_num,save[0].s_ch,save[0].s_num);
                                    break;
                                case('p'):
                                    eat=pawn_eat_k(f_ch,f_num,save[0].s_ch,save[0].s_num,a[i][j].color,'b');
                                     x=pawns_white_k(f_ch,f_num,save[0].s_ch,save[0].s_num);
                                     a1=eat||x;
                                    break;
                            }
                            int b1 = way_check(a,f_ch,f_num,save[0].s_ch,save[0].s_num,a[i][j].print);
                           if(b1 && a1){
                                expected_moves_w[expected_move_counter_w].letter[0]=f_ch;
                                expected_moves_w[expected_move_counter_w].num[0]=f_num;
                                expected_moves_w[expected_move_counter_w].letter[1]=save[0].s_ch;
                                expected_moves_w[expected_move_counter_w].num[1]=save[0].s_num;
                                expected_move_counter_w++;
                            }

                }
            }
                }
            if(eat_count>0){
            return  m[eat_count];
        }

}

//----------------------------------------------------------------------------------------------
void white_king_move(struct board_str a[8][8],char xx, int yy){
    int m,n;
    int m_end,n_end;
    // to handle all special positions for the king
    if(xx=='A'&&yy==1){
        m=0;
        n=0;
        m_end=1;
        n_end=1;
    }
    else if(xx=='H'&&yy==1){
        m=-1;
        n=0;
        m_end=0;
        n_end=1;
    }
    else if(xx=='A'&&yy==8){
        m=1;
        n=-1;
        m_end=1;
        n_end=0;
    }
    else if(xx=='H'&&yy==8){
        m=-1;
        n=-1;
        m_end=0;
        n_end=0;
    }
    else if(xx=='A'&&yy>1&&yy<8){
        m=0;
        n=-1;
        m_end=1;
        n_end=1;
    }
    else if(xx>'A'&&xx<'H'&&yy==1){
        m=-1;
        n=0;
        m_end=1;
        n_end=1;
    }
    else {
        m=-1;
        n=-1;
        m_end=1;
        n_end=1;
    }
    //king moves
    for(int mm=m;mm<=m_end;m++){
        for(int nn=n;nn<=n_end;n++){
                int to_num =yy+nn;
                char to_ch =xx+mm;
            //available move
            int t =way_check(a,xx,yy,to_ch,to_num,'k');
            int a1;
            if(t==1){
                    char sw =a[to_num-1][to_ch-65].color;
                    a[to_num-1][to_ch-65].color ='w';

                    //find who could eat him
                for(int i=0;i<8;i++){
                    for(int j=0;j<8;j++){
                            if(a[i][j].print !=' '&& a[i][j].color=='b'){
                                    int f_num=i+1;
                                    char f_ch=j+65;
                                switch(a[i][j].print){
                                    case('R'):
                                        a1=rock_black_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('N'):
                                        a1=knight_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('B'):
                                        a1=bishop_black_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('K'):
                                        a1=king_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('Q'):
                                        a1=queen_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('P'):
                                        eat=pawn_eat_k(f_ch,f_num,to_ch,to_num,a[i][j].color,'w');
                                         x=pawns_white_k(f_ch,f_num,to_ch,to_num);
                                         a1=eat||x;
                                        break;
                                }
                                int b1 = way_check(a,f_ch,f_num,to_ch,to_num,a[i][j].print);
            // if no one save move
                                if(a1&& b1){
                                     expected_moves_w[expected_move_counter_w].letter[0]=xx;
                                    expected_moves_w[expected_move_counter_w].num[0]=yy;
                                    expected_moves_w[expected_move_counter_w].letter[1]=to_ch;
                                    expected_moves_w[expected_move_counter_w].num[1]=to_num;
                                    expected_move_counter_w++;
                                }
                        }
                    }
                }
            a[to_num-1][to_ch-65].color=sw;
            }
        }
    }


}
//-----------------------------------------------------------------------------------------
void black_king_move(struct board_str a[8][8],char xx, int yy){
    int m,n;
    int m_end,n_end;
    // to handle all special positions for the king
    if(xx=='A'&&yy==1){
        m=0;
        n=0;
        m_end=1;
        n_end=1;
    }
    else if(xx=='H'&&yy==1){
        m=-1;
        n=0;
        m_end=0;
        n_end=1;
    }
    else if(xx=='A'&&yy==8){
        m=1;
        n=-1;
        m_end=1;
        n_end=0;
    }
    else if(xx=='H'&&yy==8){
        m=-1;
        n=-1;
        m_end=0;
        n_end=0;
    }
    else if(xx=='A'&&yy>1&&yy<8){
        m=0;
        n=-1;
        m_end=1;
        n_end=1;
    }
    else if(xx>'A'&&xx<'H'&&yy==1){
        m=-1;
        n=0;
        m_end=1;
        n_end=1;
    }
    else {
        m=-1;
        n=-1;
        m_end=1;
        n_end=1;
    }
    int e_count=0;
    //king moves
    for( int mm=m;mm<=m_end;mm++){
        for(int nn=n;nn<=n_end;nn++){
                int to_num =yy+nn;
                char to_ch =xx+mm;
            //available move
            int t =way_check(a,xx,yy,to_ch,to_num,'K');
            int a1;
            if(t==1){
                    char sw =a[to_num-1][to_ch-65].color;
                    a[to_num-1][to_ch-65].color ='b';
                    //find who could eat him
                for(int i=0;i<8;i++){
                    for(int j=0;j<8;j++){
                            if(a[i][j].print !=' '&& a[i][j].color=='w'){
                                    int f_num=i+1;
                                    char f_ch=j+65;
                                switch(a[i][j].print){
                                    case('r'):
                                        a1=rock_black_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('n'):
                                        a1=knight_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('b'):
                                        a1=bishop_black_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('k'):
                                        a1=king_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('q'):
                                        a1=queen_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('p'):
                                        eat=pawn_eat_k(f_ch,f_num,to_ch,to_num,a[i][j].color,'b');
                                         x=pawns_white_k(f_ch,f_num,to_ch,to_num);
                                         a1=eat||x;
                                        break;
                                }
                                int b1 = way_check(a,f_ch,f_num,to_ch,to_num,a[i][j].print);
            // if no one save move
                                if(a1&& b1){
                                     e_count++;


                                }
                                a[to_num-1][to_ch-65].color=sw;
                        }
                    }
                }
                if(e_count==0){
                    expected_moves_b[expected_move_counter_b].letter[0]=xx;
                    expected_moves_b[expected_move_counter_b].num[0]=yy;
                    expected_moves_b[expected_move_counter_b].letter[1]=to_ch;
                    expected_moves_b[expected_move_counter_b].num[1]=to_num;
                    expected_move_counter_b++;
                }
            }
        }
    }


}
//-----------------------------------------------------------------
int compare_b(struct s_text input){
    int a=0;
    for(int i=0;i<expected_move_counter_b;i++){
        if(input.letter[0]==expected_moves_b[i].letter[0] && input.letter[1]==expected_moves_b[i].letter[1] && input.num[0]== expected_moves_b[i].num[0] && input.num[1]== expected_moves_b[i].num[1]){
            a=1;
            break;
        }
    }
    return a;
}
int compare_w(struct s_text input){
    int a=0;
    for(int i=0;i<expected_move_counter_w;i++){
        if(input.letter[0]==expected_moves_w[i].letter[0] && input.letter[1]==expected_moves_w[i].letter[1] && input.num[0]== expected_moves_w[i].num[0] && input.num[1]== expected_moves_w[i].num[1]){
            a=1;
            break;
        }
    }
    return a;
}
//------------------------------------------------------------------------
int block_white(char i1,int j1,char i2,int j2){// i1 and j1 this is the place of pieces , i2 j2 is for the place of king
    //for rook
    if(i1==i2){
            if(j2>j1){
                j1=j1;
            }else if(j1>j2){
                int temp =j1;
                j1=j2;
                j2=temp;
            }
    for(int k=j1+1;k<j2;k++){
         for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                        if(a[i][j].print !=' '&& a[i][j].color=='w'){
                                int f_num=i+1;
                                char f_ch=j+65;
                            switch(a[i][j].print){
                                case('r')://check if black piece could be eaten from white piece
                                    a1=rock_black_k(f_ch,f_num,i2,k);//place of white peace to black peace
                                    break;
                                case('n'):
                                    a1=knight_k(f_ch,f_num,i2,k);
                                    break;
                                case('b'):
                                    a1=bishop_black_k(f_ch,f_num,i2,k);
                                    break;
                                case('q'):
                                    a1=queen_k(f_ch,f_num,i2,k);
                                    break;
                                case('p'):
                                    eat=pawn_eat_k(f_ch,f_num,i2,k,a[i][j].color,'b');
                                     x=pawns_white_k(f_ch,f_num,i2,k);
                                     a1=eat||x;
                                    break;
                            }
                            int b1 = way_check(a,f_ch,f_num,i2,k,a[i][j].print);
                           if(b1 && a1){ //here the saving !
                                expected_moves_w[expected_move_counter_w].letter[0]=f_ch;
                                expected_moves_w[expected_move_counter_w].num[0]=f_num;
                                expected_moves_w[expected_move_counter_w].letter[1]=i2;
                                expected_moves_w[expected_move_counter_w].num[1]=k;
                                expected_move_counter_w++;
                            }

                    }
                }
            }
        }
    }else if(j2==j1){
        if(i2>i1){
            i1=i1;
            i2=i2;
        }else if(i1>i2){
            int temp=i1;
            i1=i2;
            i2=temp;
        }
        for(int k=i1+1;k<i2;k++){
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                        if(a[i][j].print !=' '&& a[i][j].color=='w'){
                                int f_num=i+1;
                                char f_ch=j+65;
                            switch(a[i][j].print){
                                case('r')://check if black piece could be eaten from white piece
                                    a1=rock_black_k(f_ch,f_num,k,j2);//place of white peace to black peace
                                    break;
                                case('n'):
                                    a1=knight_k(f_ch,f_num,k,j2);
                                    break;
                                case('b'):
                                    a1=bishop_black_k(f_ch,f_num,k,j2);
                                    break;
                                case('q'):
                                    a1=queen_k(f_ch,f_num,k,j2);
                                    break;
                                case('p'):
                                    eat=pawn_eat_k(f_ch,f_num,k,j2,a[i][j].color,'b');
                                     x=pawns_white_k(f_ch,f_num,k,j2);
                                     a1=eat||x;
                                    break;
                            }
                            int b1 = way_check(a,f_ch,f_num,k,j2,a[i][j].print);
                           if(b1 && a1){ //here the saving !
                                expected_moves_w[expected_move_counter_w].letter[0]=f_ch;
                                expected_moves_w[expected_move_counter_w].num[0]=f_num;
                                expected_moves_w[expected_move_counter_w].letter[1]=k;
                                expected_moves_w[expected_move_counter_w].num[1]=j2;
                                expected_move_counter_w++;
                            }

                    }
                }
            }
        }
    }

}
///Bishop///
for(int w=1;w<8;w++){
    if(j2>j1 &&i1>i2){
        if((j2-j1)==w && (i1-i2)==w){
            for (int k=j1+w;k<j2;k++){
               for(int l=i2+w;l<i1;l++){
                for(int i=0;i<8;i++){
                    for(int j=0;j<8;j++){
                        if(a[i][j].print !=' '&& a[i][j].color=='w'){
                                int f_num=i+1;
                                char f_ch=j+65;
                            switch(a[i][j].print){
                                case('r')://check if black piece could be eaten from white piece
                                    a1=rock_black_k(f_ch,f_num,l,k);//place of white peace to black peace
                                    break;
                                case('n'):
                                    a1=knight_k(f_ch,f_num,l,k);
                                    break;
                                case('b'):
                                    a1=bishop_black_k(f_ch,f_num,l,k);
                                    break;
                                case('q'):
                                    a1=queen_k(f_ch,f_num,l,k);
                                    break;
                                case('p'):
                                    eat=pawn_eat_k(f_ch,f_num,l,k,a[i][j].color,'b');
                                     x=pawns_white_k(f_ch,f_num,l,k);
                                     a1=eat||x;
                                    break;
                            }
                            int b1 = way_check(a,f_ch,f_num,l,k,a[i][j].print);
                           if(b1 && a1){ //here the saving !
                                expected_moves_w[expected_move_counter_w].letter[0]=f_ch;
                                expected_moves_w[expected_move_counter_w].num[0]=f_num;
                                expected_moves_w[expected_move_counter_w].letter[1]=l;
                                expected_moves_w[expected_move_counter_w].num[1]=k;
                                expected_move_counter_w++;
                                    }

                                }
                            }
                        }
                    }
                }
            }
        }else if(j2>j1 && i2>i1){
                if((j2-j1)==w && (i2-i1)==w){
            for (int k=j1+w;k<j2;k++){
               for(int l=i1+w;l<i2;l++){
                for(int i=0;i<8;i++){
                    for(int j=0;j<8;j++){
                        if(a[i][j].print !=' '&& a[i][j].color=='w'){
                                int f_num=i+1;
                                char f_ch=j+65;
                            switch(a[i][j].print){
                                case('r')://check if black piece could be eaten from white piece
                                    a1=rock_black_k(f_ch,f_num,l,k);//place of white peace to black peace
                                    break;
                                case('n'):
                                    a1=knight_k(f_ch,f_num,l,k);
                                    break;
                                case('b'):
                                    a1=bishop_black_k(f_ch,f_num,l,k);
                                    break;
                                case('q'):
                                    a1=queen_k(f_ch,f_num,l,k);
                                    break;
                                case('p'):
                                    eat=pawn_eat_k(f_ch,f_num,l,k,a[i][j].color,'b');
                                     x=pawns_white_k(f_ch,f_num,l,k);
                                     a1=eat||x;
                                    break;
                            }
                            int b1 = way_check(a,f_ch,f_num,l,k,a[i][j].print);
                           if(b1 && a1){ //here the saving !
                                expected_moves_w[expected_move_counter_w].letter[0]=f_ch;
                                expected_moves_w[expected_move_counter_w].num[0]=f_num;
                                expected_moves_w[expected_move_counter_w].letter[1]=l;
                                expected_moves_w[expected_move_counter_w].num[1]=k;
                                expected_move_counter_w++;
                                    }

                                }
                            }
                        }
                    }
                }
            }
        }
    }
    ///for queen///
    if(i1==i2){
        if(j2>j1){
            j1=j1;
        }else if(j1>j2){
            int temp =j1;
            j1=j2;
            j2=temp;
        }
        for(int k=j1+1;k<j2;k++){
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(a[i][j].print !=' '&& a[i][j].color=='w'){
                            int f_num=i+1;
                            char f_ch=j+65;
                        switch(a[i][j].print){
                            case('r')://check if black piece could be eaten from white piece
                                a1=rock_black_k(f_ch,f_num,i2,k);//place of white peace to black peace
                                break;
                            case('n'):
                                a1=knight_k(f_ch,f_num,i2,k);
                                break;
                            case('b'):
                                a1=bishop_black_k(f_ch,f_num,i2,k);
                                break;
                            case('q'):
                                a1=queen_k(f_ch,f_num,i2,k);
                                break;
                            case('p'):
                                eat=pawn_eat_k(f_ch,f_num,i2,k,a[i][j].color,'b');
                                    x=pawns_white_k(f_ch,f_num,i2,k);
                                    a1=eat||x;
                                break;
                            }
                           int b1 = way_check(a,f_ch,f_num,i2,k,a[i][j].print);
                               if(b1 && a1){ //here the saving !
                                  expected_moves_w[expected_move_counter_w].letter[0]=f_ch;
                                  expected_moves_w[expected_move_counter_w].num[0]=f_num;
                                  expected_moves_w[expected_move_counter_w].letter[1]=i2;
                                  expected_moves_w[expected_move_counter_w].num[1]=k;
                                  expected_move_counter_w++;
                            }

                    }
                }
            }
        }
    }else if(j2==j1){
        if(i2>i1){
            i1=i1;
            i2=i2;
        }else if(i1>i2){
            int temp=i1;
            i1=i2;
            i2=temp;
        }
        for(int k=i1+1;k<i2;k++){
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                        if(a[i][j].print !=' '&& a[i][j].color=='w'){
                                int f_num=i+1;
                                char f_ch=j+65;
                            switch(a[i][j].print){
                                case('r')://check if black piece could be eaten from white piece
                                    a1=rock_black_k(f_ch,f_num,k,j2);//place of white peace to black peace
                                    break;
                                case('n'):
                                    a1=knight_k(f_ch,f_num,k,j2);
                                    break;
                                case('b'):
                                    a1=bishop_black_k(f_ch,f_num,k,j2);
                                    break;
                                case('q'):
                                    a1=queen_k(f_ch,f_num,k,j2);
                                    break;
                                case('p'):
                                    eat=pawn_eat_k(f_ch,f_num,k,j2,a[i][j].color,'b');
                                     x=pawns_white_k(f_ch,f_num,k,j2);
                                     a1=eat||x;
                                    break;
                            }
                            int b1 = way_check(a,f_ch,f_num,k,j2,a[i][j].print);
                           if(b1 && a1){ //here the saving !
                                expected_moves_w[expected_move_counter_w].letter[0]=f_ch;
                                expected_moves_w[expected_move_counter_w].num[0]=f_num;
                                expected_moves_w[expected_move_counter_w].letter[1]=k;
                                expected_moves_w[expected_move_counter_w].num[1]=j2;
                                expected_move_counter_w++;
                            }

                    }
                }
            }
        }
    }
    else{
        for(int w=1;w<8;w++){
            if(j2>j1 &&i1>i2){
                if((j2-j1)==w && (i1-i2)==w){
                    for (int k=j1+w;k<j2;k++){
                       for(int l=i2+w;l<i1;l++){
                        for(int i=0;i<8;i++){
                            for(int j=0;j<8;j++){
                                if(a[i][j].print !=' '&& a[i][j].color=='w'){
                                        int f_num=i+1;
                                        char f_ch=j+65;
                                    switch(a[i][j].print){
                                        case('r')://check if black piece could be eaten from white piece
                                            a1=rock_black_k(f_ch,f_num,l,k);//place of white peace to black peace
                                            break;
                                        case('n'):
                                            a1=knight_k(f_ch,f_num,l,k);
                                            break;
                                        case('b'):
                                            a1=bishop_black_k(f_ch,f_num,l,k);
                                            break;
                                        case('q'):
                                            a1=queen_k(f_ch,f_num,l,k);
                                            break;
                                        case('p'):
                                            eat=pawn_eat_k(f_ch,f_num,l,k,a[i][j].color,'b');
                                             x=pawns_white_k(f_ch,f_num,l,k);
                                             a1=eat||x;
                                            break;
                                    }
                                    int b1 = way_check(a,f_ch,f_num,l,k,a[i][j].print);
                                   if(b1 && a1){ //here the saving !
                                        expected_moves_w[expected_move_counter_w].letter[0]=f_ch;
                                        expected_moves_w[expected_move_counter_w].num[0]=f_num;
                                        expected_moves_w[expected_move_counter_w].letter[1]=l;
                                        expected_moves_w[expected_move_counter_w].num[1]=k;
                                        expected_move_counter_w++;
                                            }

                                        }
                                    }
                                }
                            }
                        }
                    }
                }else if(j2>j1 && i2>i1){
                        if((j2-j1)==w && (i2-i1)==w){
                        for (int k=j1+w;k<j2;k++){
                           for(int l=i1+w;l<i2;l++){
                            for(int i=0;i<8;i++){
                                for(int j=0;j<8;j++){
                                    if(a[i][j].print !=' '&& a[i][j].color=='w'){
                                            int f_num=i+1;
                                            char f_ch=j+65;
                                        switch(a[i][j].print){
                                            case('r')://check if black piece could be eaten from white piece
                                                a1=rock_black_k(f_ch,f_num,l,k);//place of white peace to black peace
                                                break;
                                            case('n'):
                                                a1=knight_k(f_ch,f_num,l,k);
                                                break;
                                            case('b'):
                                                a1=bishop_black_k(f_ch,f_num,l,k);
                                                break;
                                            case('q'):
                                                a1=queen_k(f_ch,f_num,l,k);
                                                break;
                                            case('p'):
                                                eat=pawn_eat_k(f_ch,f_num,l,k,a[i][j].color,'b');
                                                 x=pawns_white_k(f_ch,f_num,l,k);
                                                 a1=eat||x;
                                                break;
                                        }
                                        int b1 = way_check(a,f_ch,f_num,l,k,a[i][j].print);
                                       if(b1 && a1){ //here the saving !
                                            expected_moves_w[expected_move_counter_w].letter[0]=f_ch;
                                            expected_moves_w[expected_move_counter_w].num[0]=f_num;
                                            expected_moves_w[expected_move_counter_w].letter[1]=l;
                                            expected_moves_w[expected_move_counter_w].num[1]=k;
                                            expected_move_counter_w++;
                                                }

                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
    }
}
int block_black(char i1,int j1,char i2,int j2){
        //for rook
    if(i1==i2){
            if(j1>j2){
                j2=j2;
            }else if(j2>j1){
                int temp =j2;
                j2=j1;
                j1=temp;
            }
    for(int k=j2+1;k<j1;k++){
             for(int i=0;i<8;i++){
                    for(int j=0;j<8;j++){
                            if(a[i][j].print !=' '&& a[i][j].color=='b'){
                                    int f_num=i+1;
                                    char f_ch=j+65;
                                switch(a[i][j].print){
                                    case('R'):
                                        a1=rock_black_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('N'):
                                        a1=knight_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('B'):
                                        a1=bishop_black_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('K'):
                                        a1=king_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('Q'):
                                        a1=queen_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('P'):
                                        eat=pawn_eat_k(f_ch,f_num,to_ch,to_num,a[i][j].color,'w');
                                         x=pawns_black_k(f_ch,f_num,to_ch,to_num);
                                         a1=eat||x;
                                        break;
                                }
                                int b1 = way_check(a,f_ch,f_num,to_ch,to_num,a[i][j].print);
            // if no one save move
                                if(a1&& b1){
                                     expected_moves_w[expected_move_counter_w].letter[0]=xx;
                                    expected_moves_w[expected_move_counter_w].num[0]=yy;
                                    expected_moves_w[expected_move_counter_w].letter[1]=to_ch;
                                    expected_moves_w[expected_move_counter_w].num[1]=to_num;
                                    expected_move_counter_w++;
                                }
                        }
                    }
                }
    }else if(j2==j1){
        if(i2>i1){
            i1=i1;
            i2=i2;
        }else if(i1>i2){
            int temp=i1;
            i1=i2;
            i2=temp;
        }
        for(int k=i1+1;k<i2;k++){
                 for(int i=0;i<8;i++){
                    for(int j=0;j<8;j++){
                            if(a[i][j].print !=' '&& a[i][j].color=='b'){
                                    int f_num=i+1;
                                    char f_ch=j+65;
                                switch(a[i][j].print){
                                    case('R'):
                                        a1=rock_black_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('N'):
                                        a1=knight_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('B'):
                                        a1=bishop_black_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('K'):
                                        a1=king_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('Q'):
                                        a1=queen_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('P'):
                                        eat=pawn_eat_k(f_ch,f_num,to_ch,to_num,a[i][j].color,'w');
                                         x=pawns_black_k(f_ch,f_num,to_ch,to_num);
                                         a1=eat||x;
                                        break;
                                }
                                int b1 = way_check(a,f_ch,f_num,to_ch,to_num,a[i][j].print);
            // if no one save move
                                if(a1&& b1){
                                     expected_moves_w[expected_move_counter_w].letter[0]=xx;
                                    expected_moves_w[expected_move_counter_w].num[0]=yy;
                                    expected_moves_w[expected_move_counter_w].letter[1]=to_ch;
                                    expected_moves_w[expected_move_counter_w].num[1]=to_num;
                                    expected_move_counter_w++;
                                }
                        }
                    }
                }

}
///Bishop///
for(int w=1;w<8;w++){
    if(j1>j2 &&i1>i2){
        if((j1-j2)==w && (i1-i2)==w){
            for (int k=j2+w;k<j1;k++){
               for(int l=i2+w;l<i1;l++){
                    for(int i=0;i<8;i++){
                        for(int j=0;j<8;j++){
                            if(a[i][j].print !=' '&& a[i][j].color=='b'){
                                    int f_num=i+1;
                                    char f_ch=j+65;
                                switch(a[i][j].print){
                                    case('R'):
                                        a1=rock_black_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('N'):
                                        a1=knight_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('B'):
                                        a1=bishop_black_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('K'):
                                        a1=king_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('Q'):
                                        a1=queen_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('P'):
                                        eat=pawn_eat_k(f_ch,f_num,to_ch,to_num,a[i][j].color,'w');
                                         x=pawns_black_k(f_ch,f_num,to_ch,to_num);
                                         a1=eat||x;
                                        break;
                                }
                                int b1 = way_check(a,f_ch,f_num,to_ch,to_num,a[i][j].print);
            // if no one save move
                                if(a1&& b1){
                                     expected_moves_w[expected_move_counter_w].letter[0]=xx;
                                    expected_moves_w[expected_move_counter_w].num[0]=yy;
                                    expected_moves_w[expected_move_counter_w].letter[1]=to_ch;
                                    expected_moves_w[expected_move_counter_w].num[1]=to_num;
                                    expected_move_counter_w++;
                                }
                        }
                    }
                }
        }else if(j1>j2 && i2>i1){
           if((j1-j2)==w && (i2-i1)==w){
                for (int k=j2+w;k<j1;k++){
                    for(int l=i1+w;l<i2;l++){
                       for(int i=0;i<8;i++){
                            for(int j=0;j<8;j++){
                                if(a[i][j].print !=' '&& a[i][j].color=='b'){
                                    int f_num=i+1;
                                    char f_ch=j+65;
                                switch(a[i][j].print){
                                    case('R'):
                                        a1=rock_black_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('N'):
                                        a1=knight_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('B'):
                                        a1=bishop_black_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('K'):
                                        a1=king_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('Q'):
                                        a1=queen_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('P'):
                                        eat=pawn_eat_k(f_ch,f_num,to_ch,to_num,a[i][j].color,'w');
                                         x=pawns_black_k(f_ch,f_num,to_ch,to_num);
                                         a1=eat||x;
                                        break;
                                }
                                int b1 = way_check(a,f_ch,f_num,to_ch,to_num,a[i][j].print);
            // if no one save move
                                if(a1&& b1){
                                     expected_moves_w[expected_move_counter_w].letter[0]=xx;
                                    expected_moves_w[expected_move_counter_w].num[0]=yy;
                                    expected_moves_w[expected_move_counter_w].letter[1]=to_ch;
                                    expected_moves_w[expected_move_counter_w].num[1]=to_num;
                                    expected_move_counter_w++;
                                    }
                                }
                            }
                        }
                    }
                }
           }
    }
    //for queen
            //for rook
    if(i1==i2){
            if(j1>j2){
                j2=j2;
            }else if(j2>j1){
                int temp =j2;
                j2=j1;
                j1=temp;
            }
    for(int k=j2+1;k<j1;k++){
             for(int i=0;i<8;i++){
                    for(int j=0;j<8;j++){
                            if(a[i][j].print !=' '&& a[i][j].color=='b'){
                                    int f_num=i+1;
                                    char f_ch=j+65;
                                switch(a[i][j].print){
                                    case('R'):
                                        a1=rock_black_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('N'):
                                        a1=knight_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('B'):
                                        a1=bishop_black_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('K'):
                                        a1=king_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('Q'):
                                        a1=queen_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('P'):
                                        eat=pawn_eat_k(f_ch,f_num,to_ch,to_num,a[i][j].color,'w');
                                         x=pawns_black_k(f_ch,f_num,to_ch,to_num);
                                         a1=eat||x;
                                        break;
                                }
                                int b1 = way_check(a,f_ch,f_num,to_ch,to_num,a[i][j].print);
            // if no one save move
                                if(a1&& b1){
                                     expected_moves_w[expected_move_counter_w].letter[0]=xx;
                                    expected_moves_w[expected_move_counter_w].num[0]=yy;
                                    expected_moves_w[expected_move_counter_w].letter[1]=to_ch;
                                    expected_moves_w[expected_move_counter_w].num[1]=to_num;
                                    expected_move_counter_w++;
                                }
                        }
                    }
                }
    }else if(j2==j1){
        if(i2>i1){
            i1=i1;
            i2=i2;
        }else if(i1>i2){
            int temp=i1;
            i1=i2;
            i2=temp;
        }
        for(int k=i1+1;k<i2;k++){
                 for(int i=0;i<8;i++){
                    for(int j=0;j<8;j++){
                            if(a[i][j].print !=' '&& a[i][j].color=='b'){
                                    int f_num=i+1;
                                    char f_ch=j+65;
                                switch(a[i][j].print){
                                    case('R'):
                                        a1=rock_black_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('N'):
                                        a1=knight_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('B'):
                                        a1=bishop_black_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('K'):
                                        a1=king_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('Q'):
                                        a1=queen_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('P'):
                                        eat=pawn_eat_k(f_ch,f_num,to_ch,to_num,a[i][j].color,'w');
                                         x=pawns_black_k(f_ch,f_num,to_ch,to_num);
                                         a1=eat||x;
                                        break;
                                }
                                int b1 = way_check(a,f_ch,f_num,to_ch,to_num,a[i][j].print);
            // if no one save move
                                if(a1&& b1){
                                     expected_moves_w[expected_move_counter_w].letter[0]=xx;
                                    expected_moves_w[expected_move_counter_w].num[0]=yy;
                                    expected_moves_w[expected_move_counter_w].letter[1]=to_ch;
                                    expected_moves_w[expected_move_counter_w].num[1]=to_num;
                                    expected_move_counter_w++;
                                }
                        }
                    }
                }

}
///Bishop///
for(int w=1;w<8;w++){
    if(j1>j2 &&i1>i2){
        if((j1-j2)==w && (i1-i2)==w){
            for (int k=j2+w;k<j1;k++){
               for(int l=i2+w;l<i1;l++){
                    for(int i=0;i<8;i++){
                        for(int j=0;j<8;j++){
                            if(a[i][j].print !=' '&& a[i][j].color=='b'){
                                    int f_num=i+1;
                                    char f_ch=j+65;
                                switch(a[i][j].print){
                                    case('R'):
                                        a1=rock_black_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('N'):
                                        a1=knight_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('B'):
                                        a1=bishop_black_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('K'):
                                        a1=king_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('Q'):
                                        a1=queen_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('P'):
                                        eat=pawn_eat_k(f_ch,f_num,to_ch,to_num,a[i][j].color,'w');
                                         x=pawns_black_k(f_ch,f_num,to_ch,to_num);
                                         a1=eat||x;
                                        break;
                                }
                                int b1 = way_check(a,f_ch,f_num,to_ch,to_num,a[i][j].print);
            // if no one save move
                                if(a1&& b1){
                                     expected_moves_w[expected_move_counter_w].letter[0]=xx;
                                    expected_moves_w[expected_move_counter_w].num[0]=yy;
                                    expected_moves_w[expected_move_counter_w].letter[1]=to_ch;
                                    expected_moves_w[expected_move_counter_w].num[1]=to_num;
                                    expected_move_counter_w++;
                                }
                        }
                    }
                }
        }else if(j1>j2 && i2>i1){
           if((j1-j2)==w && (i2-i1)==w){
                for (int k=j2+w;k<j1;k++){
                    for(int l=i1+w;l<i2;l++){
                       for(int i=0;i<8;i++){
                            for(int j=0;j<8;j++){
                                if(a[i][j].print !=' '&& a[i][j].color=='b'){
                                    int f_num=i+1;
                                    char f_ch=j+65;
                                switch(a[i][j].print){
                                    case('R'):
                                        a1=rock_black_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('N'):
                                        a1=knight_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('B'):
                                        a1=bishop_black_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('K'):
                                        a1=king_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('Q'):
                                        a1=queen_k(f_ch,f_num,to_ch,to_num);
                                        break;
                                    case('P'):
                                        eat=pawn_eat_k(f_ch,f_num,to_ch,to_num,a[i][j].color,'w');
                                         x=pawns_black_k(f_ch,f_num,to_ch,to_num);
                                         a1=eat||x;
                                        break;
                                }
                                int b1 = way_check(a,f_ch,f_num,to_ch,to_num,a[i][j].print);
            // if no one save move
                                if(a1&& b1){
                                     expected_moves_w[expected_move_counter_w].letter[0]=xx;
                                    expected_moves_w[expected_move_counter_w].num[0]=yy;
                                    expected_moves_w[expected_move_counter_w].letter[1]=to_ch;
                                    expected_moves_w[expected_move_counter_w].num[1]=to_num;
                                    expected_move_counter_w++;
                                    }
                                }
                            }
                        }
                    }
                }
           }
    }
}
#endif // CHECKMATEHELPERS_H_INCLUDED
