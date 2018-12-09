#ifndef PRINTING_H_INCLUDED
#define PRINTING_H_INCLUDED
//introduction function
char intro(){
    char m;
         printf("\n\tWelcome To Chess Game\n\n \n");
         printf("\t #####     #        #######      ####    ####\n");
         printf("\t#          #        #           #       #   \n");
         printf("\t#          #        #           #       # \n");
         printf("\t#          #####    #######      ###     ###\n");
         printf("\t#          #   #    #               #       #\n");
         printf("\t#          #   #    #               #       #\n");
         printf("\t #####     #   #    #######     ####    ####\n");
        printf("\n   There are some instructions To help you:\n");
        printf("     Type U to undo \n     Type R to redo \n     Type S to save\n");
        printf("   To play write your current place Then enter the place you want to go to\n");
        printf("     Now, Type 's' to start or 'l' to load previous game:");
        scanf(" %c",&m);
        if(m=='s'){
            return 1;
        }
        /*if(m==l){
         load case
        }*/
        else{
           printf(" ERROR : Invalid Input Try Again\n");
           return 0;
        }

}
//-------------------------------------------------------------------------------------------------------------------
//printing board functions
void print_board(struct board_str a[8][8]){
        printf("\n\n\n");
        printf("\t      A         B        C         D        E         F        G         H     \n ");
        printf("\t   -------- * * * * * -------- * * * * * -------- * * * * * -------- * * * * * \n");
        printf("\t  |        |*       *|        |*       *|        |*       *|        |*       *\n");
        printf("\t1 |   %c    |*   %c   *|   %c    |*   %c   *|   %c    |*   %c   *|   %c    |*   %c   *\n",a[0][0].print,a[0][1].print,a[0][2].print,a[0][3].print,a[0][4].print,a[0][5].print,a[0][6].print,a[0][7].print);
        printf("\t  |        |*       *|        |*       *|        |*       *|        |*       *\n");
        printf("\t   -------- * * * * * -------- * * * * * -------- * * * * * -------- * * * * * \n");
        printf("\t  * * * * * -------- * * * * * -------- * * * * * -------- * * * * * -------- \n");
        printf("\t  *       *|        |*       *|        |*       *|        |*       *|        |\n");
        printf("\t2 *   %c   *|   %c    |*   %c   *|   %c    |*   %c   *|   %c    |*   %c   *|   %c    |\n",a[1][0].print,a[1][1].print,a[1][2].print,a[1][3].print,a[1][4].print,a[1][5].print,a[1][6].print,a[1][7].print);
        printf("\t  *       *|        |*       *|        |*       *|        |*       *|        |\n");
        printf("\t  * * * * * -------- * * * * * -------- * * * * * -------- * * * * * -------- \n");
        printf("\t   -------- * * * * * -------- * * * * * -------- * * * * * -------- * * * * * \n");
        printf("\t  |        |*       *|        |*       *|        |*       *|        |*       *\n");
        printf("\t3 |   %c    |*   %c   *|   %c    |*   %c   *|   %c    |*   %c   *|   %c    |*   %c   *\n",a[2][0].print,a[2][1].print,a[2][2].print,a[2][3].print,a[2][4].print,a[2][5].print,a[2][6].print,a[2][7].print);
        printf("\t  |        |*       *|        |*       *|        |*       *|        |*       *\n");
        printf("\t   -------- * * * * * -------- * * * * * -------- * * * * * -------- * * * * * \n");
        printf("\t  * * * * * -------- * * * * * -------- * * * * * -------- * * * * * -------- \n");
        printf("\t  *       *|        |*       *|        |*       *|        |*       *|        |\n");
        printf("\t4 *   %c   *|   %c    |*   %c   *|   %c    |*   %c   *|   %c    |*   %c   *|   %c    |\n",a[3][0].print,a[3][1].print,a[3][2].print,a[3][3].print,a[3][4].print,a[3][5].print,a[3][6].print,a[3][7].print);
        printf("\t  *       *|        |*       *|        |*       *|        |*       *|        |\n");
        printf("\t  * * * * * -------- * * * * * -------- * * * * * -------- * * * * * -------- \n");
        printf("\t   -------- * * * * * -------- * * * * * -------- * * * * * -------- * * * * * \n");
        printf("\t  |        |*       *|        |*       *|        |*       *|        |*       *\n");
        printf("\t5 |   %c    |*   %c   *|   %c    |*   %c   *|   %c    |*   %c   *|   %c    |*   %c   *\n",a[4][0].print,a[4][1].print,a[4][2].print,a[4][3].print,a[4][4].print,a[4][5].print,a[4][6].print,a[4][7].print);
        printf("\t  |        |*       *|        |*       *|        |*       *|        |*       *\n");
        printf("\t   -------- * * * * * -------- * * * * * -------- * * * * * -------- * * * * * \n");
        printf("\t  * * * * * -------- * * * * * -------- * * * * * -------- * * * * * -------- \n");
        printf("\t  *       *|        |*       *|        |*       *|        |*       *|        |\n");
        printf("\t6 *   %c   *|   %c    |*   %c   *|   %c    |*   %c   *|   %c    |*   %c   *|   %c    |\n",a[5][0].print,a[5][1].print,a[5][2].print,a[5][3].print,a[5][4].print,a[5][5].print,a[5][6].print,a[5][7].print);
        printf("\t  *       *|        |*       *|        |*       *|        |*       *|        |\n");
        printf("\t  * * * * * -------- * * * * * -------- * * * * * -------- * * * * * -------- \n");
        printf("\t   -------- * * * * * -------- * * * * * -------- * * * * * -------- * * * * * \n");
        printf("\t  |        |*       *|        |*       *|        |*       *|        |*       *\n");
        printf("\t7 |   %c    |*   %c   *|   %c    |*   %c   *|   %c    |*   %c   *|   %c    |*   %c   *\n",a[6][0].print,a[6][1].print,a[6][2].print,a[6][3].print,a[6][4].print,a[6][5].print,a[6][6].print,a[6][7].print);
        printf("\t  |        |*       *|        |*       *|        |*       *|        |*       *\n");
        printf("\t   -------- * * * * * -------- * * * * * -------- * * * * * -------- * * * * * \n");
        printf("\t  * * * * * -------- * * * * * -------- * * * * * -------- * * * * * -------- \n");
        printf("\t  *       *|        |*       *|        |*       *|        |*       *|        |\n");
        printf("\t8 *   %c   *|   %c    |*   %c   *|   %c    |*   %c   *|   %c    |*   %c   *|   %c    |\n",a[7][0].print,a[7][1].print,a[7][2].print,a[7][3].print,a[7][4].print,a[7][5].print,a[7][6].print,a[7][7].print);
        printf("\t  *       *|        |*       *|        |*       *|        |*       *|        |\n");
        printf("\t  * * * * * -------- * * * * * -------- * * * * * -------- * * * * * -------- \n");

}
//--------------------------------------------------------------------------------------------------


#endif // PRINTING_H_INCLUDED
