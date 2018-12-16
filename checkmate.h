#ifndef CHECKMATE_H_INCLUDED
#define CHECKMATE_H_INCLUDED
#include "checkmatehelpers.h"
#include "if_one_eat_at_check.h"
int eat;// if the pawn going to eat or not
struct s_text expected_moves[100];//moves which will be compared at the end
int expected_move_counter;// its counter
int king_place(struct board_str a[8][8],char kind,char colors,int turn){
    expected_move_counter=0;//to start check
    struct saved_place save [16];//array to save pieces which make check
    //its counter
    int s_count=0;
    int x1,y1;//place of the king
    int a1;//flag1
    int x;//flag 2
     if(colors=='b' && kind=='K' && (!turn)){
            //nested loops to find the king
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(a[i][j].print=='K'){
                        x1=i,y1=j;
                        x1=x1+1;
                        y1=(char)(y1+65);
                        break;

                    }
                }
            }
//finding the white pieces and see who could eat the king and save it
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                        if(a[i][j].print !=' '&& a[i][j].color=='w'){
                                int f_num=i+1;
                                char f_ch=j+65;
                            switch(a[i][j].print){
                                case('r'):
                                    a1=rock_black_k(f_ch,f_num,y1,x1);
                                    break;
                                case('n'):
                                    a1=knight_k(f_ch,f_num,y1,x1);
                                    break;
                                case('b'):
                                    a1=bishop_black_k(f_ch,f_num,y1,x1);
                                    break;
                                case('k'):
                                    a1=king_k(f_ch,f_num,y1,x1);
                                    break;
                                case('q'):
                                    a1=queen_k(f_ch,f_num,y1,x1);
                                    break;
                                case('p'):
                                    eat=pawn_eat_k(f_ch,f_num,y1,x1,a[i][j].color,colors);
                                     x=pawns_white_k(f_ch,f_num,y1,x1);
                                     a1=eat||x;
                                    break;
                            }
                            int b1 = way_check(a,f_ch,f_num,y1,x1,a[i][j].print);
                            //save it
                            if(b1 && a1){
                                save[s_count].s_ch=f_ch;
                                save[s_count].s_num=f_num;
                                s_count++;
                            }
                        }
                }
            }
            // telling that there is an check
            if(s_count>0){
               red();
                printf("Black King IS in Danger :( \n");
                reset();
            }
            else if(s_count==0){
                //king is safe
                return 0;
            }
        // check who could eat the threat and save it
            else if(s_count ==1){
                eat_test_while_black_under_threat(a,save);
            }
        }

     /*else if(colors=='w' && kind=='k' && turn){
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(a[i][j].print='k'){
                        x=i,y=j;

                    }
                }
            }
        }*/

}
#endif // CHECKMATE_H_INCLUDED
