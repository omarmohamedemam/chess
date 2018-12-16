#ifndef IF_ONE_EAT_AT_CHECK_H_INCLUDED
#include "checkmate.h"
#include "checkmatehelpers.h"
#include "functions.h"
#define IF_ONE_EAT_AT_CHECK_H_INCLUDED

int eat_@_checkmate(struct board_str a[8][8],struct saved_place save [16]){
        struct s_text m[16];
        int sb_count=0;
                for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                        for(int g=0;g<s_count;g++){
                        if(a[i][j].print !=' '&& a[i][j].color=='b'){
                                int f_num=i+1;
                                char f_ch=j+65;
                            switch(a[i][j].print){
                                case('R')://from black piece to eat white piece
                                    a1=rock_black_k(f_ch,f_num,save[g].s_ch,save[g].s_num);
                                    break;
                                case('N'):
                                    a1=knight_k(f_ch,f_num,save[g].s_ch,save[g].s_num);
                                    break;
                                case('B'):
                                    a1=bishop_black_k(f_ch,f_num,save[g].s_ch,save[g].s_num);
                                    break;
                                case('K'):
                                    a1=king_k(f_ch,f_num,save[g].s_ch,save[g].s_num);
                                    break;
                                case('Q'):
                                    a1=queen_k(f_ch,f_num,save[g].s_ch,save[g].s_num);
                                    break;
                                case('P'):
                                    eat=pawn_eat_k(f_ch,f_num,save[g].s_ch,save[g].s_num,a[i][j].color,colors);
                                     x=pawns_black(f_ch,f_num,save[g].s_ch,save[g].s_num);
                                     a1=eat||x;
                                    break;
                            }
                            int b1 =int check(a,f_ch,f_num,save[g].s_ch,save[g].s_num,a[i][j].print);
                            if(b1 && a1){
                                m[sb_count].letter[0]=save[g].s_ch
                                m[sb_count].num[0]=save[g].s_num
                                m[sb_count+1].letter[1]=f_ch
                                m[sb_count+1].num[1]=f_num
                                sb_count++;
                            }
                        }else if(a[i][j].print !=' '&& a[i][j].color=='w'){
                                int f_num=i+1;
                                char f_ch=j+65;
                            switch(a[i][j].print){
                                case('r'):
                                    a1=rock_black_k(f_ch,f_num,save[g].s_ch,save[g].s_num);
                                    break;
                                case('n'):
                                    a1=knight_k(f_ch,f_num,save[g].s_ch,save[g].s_num);
                                    break;
                                case('b'):
                                    a1=bishop_black_k(f_ch,f_num,save[g].s_ch,save[g].s_num);
                                    break;
                                case('k'):
                                    a1=king_k(f_ch,f_num,save[g].s_ch,save[g].s_num);
                                    break;
                                case('q'):
                                    a1=queen_k(f_ch,f_num,save[g].s_ch,save[g].s_num);
                                    break;
                                case('p'):
                                    eat=pawn_eat_k(f_ch,f_num,save[g].s_ch,save[g].s_num,a[i][j].color,colors);
                                     x=pawns_white(f_ch,f_num,save[g].s_ch,save[g].s_num);
                                     a1=eat||x;
                                    break;
                            }
                            int b1 =int check(a,f_ch,f_num,save[g].s_ch,save[g].s_num,a[i][j].print);
                            if(b1 && a1){
                                m[sb_count].letter[0]=save[g].s_ch
                                m[sb_count].num[0]=save[g].s_num
                                m[sb_count+1].letter[1]=f_ch
                                m[sb_count+1].num[1]=f_num
                                sb_count++;
                            }


                        }
                    }
                }
            }
            return m;
}

#endif // IF_ONE_EAT_AT_CHECK_H_INCLUDED
