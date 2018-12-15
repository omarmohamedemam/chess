#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"
#include "initialize.h"
#include "printing.h"
#include "Checks.h"
#include "Functions_of_element.h"
#include <windows.h>
#include<conio.h>
int pro_un;
int un;
int main()
{
    int start =intro();
    struct board_str pieces [8][8];
    struct s_text r_scan;
    first_time_board(pieces);
   while(start!=1){
        Sleep(800);
        clrscr();
        start =intro();
   }
        clrscr();
        print_board(pieces);
        for(int i =0 ;i<20;i++){
             fixed_turn(i);
            int z=whose_turn(i);
            r_scan=scan_move(pieces);
            if(un ==1 ){
                yellow();
                printf("You've Just made undo / redo \n");
                Sleep(500);
                reset();
                clrscr();
               print_board(pieces);
              continue;
            }
            int e=0;
            int w=0;
            int p=0;
            if(text_check){
                  e=first_check(pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].print,pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].color,pieces[(r_scan.num[1]-1)][(int)(r_scan.letter[1]-'A')].color,z,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1]);
                  p=check_promo(pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].print,pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].color,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1]);
                  w=check(pieces,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1],pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].print);
                      if(w==0){
                            red();
                            printf("Error : Invalid move Some Thing Block Your Way \n");
                            reset();
                        }
            }
            if(e && text_check && w/*for boundaries */){
                move_pieces(pieces,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1]);
                print_board(pieces);
                if(p==1){
                    make_promo(pieces,r_scan.letter[1],r_scan.num[1],r_scan.letter[2]);
                }
                pro_un=save_move(r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1],p);
            }
            else{
                while(((!e) && (!w))||(w^e)){
                    Sleep(500);
                    clrscr();
                    print_board(pieces);
                    fixed_turn(i);
                    red();
                    printf("\t\t\tTry Again,Please\n");
                    reset();
                     r_scan=scan_move(pieces);
                    if(un ==1 ){
                        yellow();
                        printf("You've Just made undo\n");
                        Sleep(500);
                        reset();
                        clrscr();
                        print_board(pieces);
                        continue;
                    }
                     if(text_check){

                        e=first_check(pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].print,pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].color,pieces[(r_scan.num[1]-1)][(int)(r_scan.letter[1]-'A')].color,z,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1]);
                         p=check_promo(pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].print,pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].color,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1]);
                        w=check(pieces,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1],pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].print);
                     }

                }
                if(e==1 && w==1){
                     move_pieces(pieces,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1]);
                    print_board(pieces);
                    if(p==1){
                    make_promo(pieces,r_scan.letter[1],r_scan.num[1],r_scan.letter[2]);
                    }
                    pro_un=save_move(r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1],p);
                }

            }

        }


    return 0;
}
