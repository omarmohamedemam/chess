#ifndef INITIALIZE_H_INCLUDED
#define INITIALIZE_H_INCLUDED

char first_time_board (char b[8][8]){
     char a [8][8]={{'R','N','B','Q','K','B','N','R'},
                        {'P','P','P','P','P','P','P','P'},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {' ',' ',' ',' ',' ',' ',' ',' '},
                        {'p','p','p','p','p','p','p','p'},
                        {'r','n','b','q','k','b','n','r'}
                        } ;
    for (int i = 0; i < 8; i++) {
      for(int j =0;j<8;j++){
        b[i][j]=a[i][j];
      }
   }

    return b;
}
struct s_text {
    int num[2];
    char letter[3];

};

#endif // INITIALIZE_H_INCLUDED
