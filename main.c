#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "initialize.h"
#include "printing.h"
int main()
{
    char start =intro();
    char pieces [8][8];
    first_time_board(pieces);
    if(start == 's'){
        clrscr();
        print_board(pieces);
        char n[6];
        scan_move(n);
    }
    return 0;
}
