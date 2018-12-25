#ifndef CHECKMATE_H_INCLUDED
#define CHECKMATE_H_INCLUDED
#include "checkmatehelpers.h"
int checkmate=0;
int eat;// if the pawn going to eat or not
struct s_text expected_moves_b[100];//moves which will be compared at the end
int expected_move_counter_b;// its counter
struct s_text expected_moves_w[100];//moves which will be compared at the end
int expected_move_counter_w;// its counter
int mate_check(struct board_str a[8][8],char kind,char colors){
    int ret;
    struct saved_place save [16];//array to save pieces which make check
    //its counter
    int s_count=0;
    int x1;
    char y1;//place of the king
    int a1;//flag1
    int x;//flag 2
     if(colors=='b' && kind=='K' ){
                expected_move_counter_b=0;//to start check
            //nested loops to find the king
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(a[i][j].print=='K'){
                        x1=i,y1=j;
                        x1=x1+1;
                        y1=(char)(y1+65);
                        i=j=8;
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

            if(s_count==0){
                //king is safe
                ret =0;
            }
        // check who could eat the threat and save it
            else if(s_count ==1){
                red();
                printf("Black King IS in Danger :( \n");
                reset();
                eat_test_while_black_under_threat(a,save);
                black_king_move(a,y1,x1);
                block_black(a,save[0].s_ch,save[0].s_num,y1,x1);
                ret= 1;

            }
            // telling that there is an check
            else if(s_count>1){
               red();
                printf("Black King IS in Danger :( \n");
                reset();
                black_king_move(a,y1,x1);
                ret= 1;
            }
        }
        //--------------------------------------------------------
        //the white time

     if(colors=='w' && kind=='k' ){
            //nested loops to find the king
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(a[i][j].print=='k'){
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
                        if(a[i][j].print !=' '&& a[i][j].color=='b'){
                                int f_num=i+1;
                                char f_ch=j+65;
                            switch(a[i][j].print){
                                case('R'):
                                    a1=rock_black_k(f_ch,f_num,y1,x1);
                                    break;
                                case('N'):
                                    a1=knight_k(f_ch,f_num,y1,x1);
                                    break;
                                case('B'):
                                    a1=bishop_black_k(f_ch,f_num,y1,x1);
                                    break;
                                case('K'):
                                    a1=king_k(f_ch,f_num,y1,x1);
                                    break;
                                case('Q'):
                                    a1=queen_k(f_ch,f_num,y1,x1);
                                    break;
                                case('P'):
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

            if(s_count==0){
                //king is safe
                return 0;
            }
        // check who could eat the threat and save it
            else if(s_count ==1){
                red();
                printf("White King IS in Danger :( \n");
                reset();
                eat_test_while_white_under_threat(a,save);
                white_king_move(a,y1,x1);
                block_white(a,save[0].s_ch,save[0].s_num,y1,x1);
                ret= 1;


            }
            // telling that there is an check
            else if(s_count>1){
               red();
                printf("Black King IS in Danger :( \n");
                reset();
                white_king_move(a,y1,x1);
                ret= 1;
            }
        }
        //------------------------------------
        if(expected_move_counter_b==0 && colors=='b' && kind=='K'  && s_count>0){
                red();
                printf("Check Mate \n");
                reset();
                checkmate=1;
                    red();
                    printf("Black King IS Dead :( \n");
                    reset();
        }
        else if(expected_move_counter_w==0 && colors=='w' && kind=='k'  && s_count>0){
            red();
                printf("Check Mate \n");
                reset();
                checkmate=1;
                    red();
                    printf("White King IS Dead :( \n");
                    reset();
        }
        return ret;

}
#endif // CHECKMATE_H_INCLUDED
