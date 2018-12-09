#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "initialize.h"
#include "printing.h"
#include "Functions_of_element.h"
int main()
{
    char start =intro();
    char pieces [8][8];
    struct s_text r_scan;
    first_time_board(pieces);
    if(start == 's'){
        clrscr();
        print_board(pieces);
        r_scan=scan_move();
       int x = rock(r_scan.letter[0],r_scan.num[0],r_scan.letter[1],r_scan.num[1]);
       printf("%d",x);
    }
    return 0;
}
