#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"
#include "initialize.h"
#include "printing.h"
#include "Functions_of_element.h"
#include <windows.h>
#include<conio.h>

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
            int z=whose_turn(i);
            r_scan=scan_move();
            int e=0;
            if(text_check){
                  e=first_check(pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].print,pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].color,z,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1]);
            }
            if(e && text_check/*for boundaries */){
                move_pieces(pieces,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1]);
                print_board(pieces);
            }
            else{
                while(!e){
                    Sleep(800);
                    clrscr();
                    print_board(pieces);
                    red();
                    printf("Try Again,Please\n");
                    reset();
                     r_scan=scan_move();
                     if(text_check){
                        e=first_check(pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].print,pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].color,z,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1]);
                     }
                }
                if(e==1){
                     move_pieces(pieces,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1]);
                    print_board(pieces);
                }

            }

        }


    return 0;
}
