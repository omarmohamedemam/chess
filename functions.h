#ifndef FUNCTIONS_H_INCLUDED
#include <ctype.h>
#include "initialize.h"
#define FUNCTIONS_H_INCLUDED

//clear screen function
void clrscr()
{
    system("@cls||clear");
}
 struct s_text scan_move(){
     struct s_text scan;
    printf("Enter your movement:");
    int a[2];
    char b[3];
    for(int i=0 ;i<2;i++){
        scanf(" %c",&b[i]);
        scanf("%d",&a[i]);
    }
    /* in case of promotion
     scanf(" %c",&b[3]);*/
    for(int i=0 ;i<2;i++){
        b[i]=toupper(b[i]);
    }
    for(int i=0 ;i<2;i++){
        scan.num[i]=a[i];
    }
    for(int i=0 ;i<2;i++){
        scan.letter[i]=b[i];
    }
    return scan;


}



#endif // FUNCTIONS_H_INCLUDED
