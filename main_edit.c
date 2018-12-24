// huge including (libraries,header,.....etc)
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include<conio.h>
#include "functions.h"
#include "initialize.h"
#include "printing.h"
#include "Checks.h"
#include "Functions_of_element.h"
#include "checkmate.h"
#include "checkmatehelpers.h"
#include "savefile.h"
//------------------------------------------------------
int un;
int undo_counter=0;
int pro_counter=0;
int sp=0;
int promtoion_flag=0;
int u_count;
int sp_1=0;
int i=0;
//----------------------------------------------------------
int main()
{
int undo_counter;
    //first use [intro - ask to start - keep playing till s]
    int start =intro();
    // initialize and set values
    struct board_str pieces [8][8];
    struct s_text r_scan;
    first_time_board(pieces);
   while(start!=1){
        Sleep(800);
        clrscr();
        start =intro();
   }
   //--------------------------------
   //print the board first time
        clrscr();
        print_board(pieces);
    // the global loop must end with checkmate
        for( i =0 ;i<50;i++){
            //print the turn and set its value
             fixed_turn(i);
            int z=whose_turn(i);
        // scan move
            r_scan=scan_move(pieces);
        //telling in case of undo
            if(un ==1 ){
                yellow();
                printf("You've Just made undo / redo \n");
                Sleep(500);
                reset();
                clrscr();
               print_board(pieces);
              continue;
            }
        //test flags
            int element_flag=0;
            int way_flag=0;

        //only in case of right text
            if(text_check){
                  element_flag=element_check(pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].print,pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].color,pieces[(r_scan.num[1]-1)][(int)(r_scan.letter[1]-'A')].color,z,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1]);
                  promtoion_flag=check_promo(pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].print,pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].color,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1]);
                  way_flag=way_check(pieces,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1],pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].print);

                        if(way_flag==0){
                                if(pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].print==' '){
                                    printf ("You cant Move In The space :)");
                                }else{
                                    if(element_flag==1){//to make the move in right places
                            red();
                            printf("Error : Invalid move Some Thing Block Your Way \n");//print it only when block.
                            reset();
                                    }
                                }
                        }
            }
            //if all were good
            if(element_flag && text_check && way_flag   /*for boundaries */){
                    // apply move which contain clear
                move_pieces(pieces,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1]);
                happen=0;
                save_move_a(r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1]);
            //print board again
                print_board(pieces);
            // check checkmate according to counter
                if(i%2==0){
                    king_place(pieces,'K','b',i);
                }
                else if(i%2 != 0){
                    king_place(pieces,'k','w',i);
                }
            //making the promotion and save it
                if(promtoion_flag==1){
                    make_promo(pieces,r_scan.letter[1],r_scan.num[1],r_scan.letter[2]);
                    promd=r_scan.letter[2];
                    clrscr();
                    print_board(pieces);
                    save_move_p(r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1],promtoion_flag);
                    promtoion_flag==0;
                }



            }
            //in case of wrong input
            else{
                    //loop till the both are true
                while(((!element_flag) && (!way_flag))||(way_flag^element_flag)){

                    // telling him his fault-----------------------
                    Sleep(500);
                    clrscr();
                    print_board(pieces);
                    fixed_turn(i);
                    red();
                    printf("\t\t\tTry Again,Please\n");
                    reset();
                    //------------------------scan again
                     r_scan=scan_move(pieces);
                     // undo case again
                    if(un ==1 ){
                        yellow();
                        printf("You've Just made undo\n");
                        Sleep(500);
                        reset();
                        clrscr();
                        print_board(pieces);
                        continue;
                    }

                    //-------------------------
                    //if the scanned is true for the next time
                     if(text_check){

                        element_flag=element_check(pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].print,pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].color,pieces[(r_scan.num[1]-1)][(int)(r_scan.letter[1]-'A')].color,z,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1]);
                         promtoion_flag=check_promo(pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].print,pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].color,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1]);
                        way_flag=way_check(pieces,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1],pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].print);
                     }
                        if(way_flag==0){
                                if(pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].print==' '){
                                    printf ("You cant Move In The space :)");
                                }else{
                                    if(element_flag==1){//to make the move in right places
                            red();
                            printf("Error : Invalid move Some Thing Block Your Way \n");
                            reset();
                                    }
                                }

                        }


                }
                //move it
                if(element_flag==1 && way_flag==1){
                     move_pieces(pieces,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1]);
                    save_move_a(r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1]);
                    print_board(pieces);
                    //check promotion
                    if(promtoion_flag==1){
                        make_promo(pieces,r_scan.letter[1],r_scan.num[1],r_scan.letter[2]);
                       clrscr();
                        print_board(pieces);
                        save_move_p(r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1],promtoion_flag);
                    }


                }

            }

        }


    return 0;
}
