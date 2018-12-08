#ifndef FUNCTIONS_H_INCLUDED
#include <ctype.h>
#define FUNCTIONS_H_INCLUDED

//clear screen function
void clrscr()
{
    system("@cls||clear");
}
char scan_move(char a[6]){
    printf("Enter your movement:");
    char r[6];
    for(int i=0 ;i<6;i++){
        scanf(" %c",r[i]);
    }
    for(int i=0 ;i<6;i++){
        r[i]=tolower(r[i]);
    }
    if(r[0]>'h' || r[3]>'h' || r[0]<'a' ||r[3]<'a' || r[1]>'8' || r[1]<'1' || r[4]<'1' || r[4]>'8'){
        scan_move(a);
    }
    a=r;
    return a;


}



#endif // FUNCTIONS_H_INCLUDED
