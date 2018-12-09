#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "functions.h"
#include "initialize.h"
#include "printing.h"
#include "Functions_of_element.h"
#include <windows.h>

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
        r_scan=scan_move();
        move_pieces(pieces,r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1]);
        print_board(pieces);
    return 0;
}
