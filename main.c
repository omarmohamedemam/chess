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
//------------------------------------------------------
int pro_un;
int un;
//----------------------------------------------------------
int main()
{
    int check_white =0;//for check mate
    int check_black =0;//for check mate
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
        for(int i =0 ;checkmate ==0;i++){
            //print the turn and set its value
             fixed_turn(i);
            int z=whose_turn(i);
        if( check_black==1){
    // scan move
                while( check_black==1){
                        fixed_turn(i);
                        r_scan=scan_move(pieces);
                    int q =compare_b(r_scan);
                if(q==0){
                    yellow();
                    printf("Error This Move May Make you lost\t\t");
                    reset();
                    red();
                    printf("Try Again \n");
                    reset();

                }
                else{
                    check_black=0;
                    continue;

                }
                }


            }
            else if( check_white==1){
    // scan move
                while( check_white==1){
                        fixed_turn(i);
                        r_scan=scan_move(pieces);
                    int q =compare_w(r_scan);
                if(q==0){
                    yellow();
                    printf("Error This Move May Make you lost\t\t");
                    reset();
                    red();
                    printf("Try Again \n");
                    reset();

                }
                else{
                    check_white=0;
                    continue;
                }
                }

            }
            else{
                // scan move
                r_scan=scan_move(pieces);

            }

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
            int promtoion_flag=0;
        //only in case of right text
            if(text_check){
                  element_flag=element_check(pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].print,pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].color,pieces[(r_scan.num[1]-1)][(int)(r_scan.letter[1]-'A')].color,z,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1]);
                  promtoion_flag=check_promo(pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].print,pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].color,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1]);
                  way_flag=way_check(pieces,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1],pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].print);
                        if(way_flag==0){
                                if(pieces[(r_scan.num[0]-1)][(int)(r_scan.letter[0]-'A')].print==' '){
                                        yellow();
                                    printf ("You cant Move The space"  );
                                reset();
                                }else{
                                    if(element_flag==1){
                                        red();
                                        printf("Error : Invalid move Some Thing Block Your Way \n");
                                        reset();
                                    }

                                }
                        }
            }
            //if all were good
            if(element_flag && text_check && way_flag   /*for boundaries */){
                    // apply move which contain clear
                move_pieces(pieces,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1]);
            //print board again
                print_board(pieces);
            // check checkmate
                  check_black = mate_check(pieces,'K','b');

                  check_white =  mate_check(pieces,'k','w');
                  if(check_black ==1 && i%2!=0){
                    checkmate=1;
                     red();
                    printf("Check Mate \n");
                    printf("Black King IS Dead :( \n");
                    reset();
                  }
                  else if(check_white==1 && i%2==0){
                    checkmate=1;
                    red();
                    printf("Check Mate \n");
                    printf("White King IS Dead :( \n");
                    reset();
                  }

                  //case of check

            //making the promotion and save it
                if(promtoion_flag==1){
                    make_promo(pieces,r_scan.letter[1],r_scan.num[1],r_scan.letter[2]);
                    clrscr();
                    print_board(pieces);

                }
                pro_un=save_move(r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1],promtoion_flag);
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
                                 //case of check
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
                                        yellow();
                                    printf ("You cant Move The space"  );
                                reset();
                                }else{
                                    if(element_flag==1){

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
                    print_board(pieces);
                                // check checkmate according to counter
                                   // check checkmate
                  check_black = mate_check(pieces,'K','b');

                  check_white =  mate_check(pieces,'k','w');
                  if(check_black ==1 && i%2!=0){
                    checkmate=1;
                     red();
                    printf("Check Mate \n");
                    printf("Black King IS Dead :( \n");
                    reset();
                  }
                  else if(check_white==1 && i%2==0){
                    checkmate=1;
                    red();
                    printf("Check Mate \n");
                    printf("White King IS Dead :( \n");
                    reset();
                  }

                    //check promotion
                    if(promtoion_flag==1){
                    make_promo(pieces,r_scan.letter[1],r_scan.num[1],r_scan.letter[2]);
                    clrscr();
                    print_board(pieces);
                    }
                    pro_un=save_move(r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1],promtoion_flag);
                }

            }

        }


    return 0;
}

