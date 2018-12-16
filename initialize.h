#ifndef INITIALIZE_H_INCLUDED
#define INITIALIZE_H_INCLUDED
//structure of board elements
struct board_str{

    char print;// shape
    int available;// 0 if not , 1 if available
    char color;// b for black w for white n for non

};
//------------------------------------------------------------------------------------------------------------------------
//setting value for the board
 struct board_str first_time_board (struct board_str b[8][8]){
      struct board_str a[8][8]  = {{{'R',1,'b'},{'N',1,'b'},{'B',1,'b'},{'Q',1,'b'},{'K',1,'b'},{'B',1,'b'},{'N',1,'b'},{'R',1,'b'}},
                                   {{'P',1,'b'},{'P',1,'b'},{'P',1,'b'},{'P',1,'b'},{'P',1,'b'},{'P',1,'b'},{'P',1,'b'},{'P',1,'b'}},
                                   {{' ',0,'n'},{' ',0,'n'},{' ',0,'n'},{' ',0,'n'},{' ',0,'n'},{' ',0,'n'},{' ',0,'n'},{' ',0,'n'}},
                                   {{' ',0,'n'},{' ',0,'n'},{' ',0,'n'},{' ',0,'n'},{' ',0,'n'},{' ',0,'n'},{' ',0,'n'},{' ',0,'n'}},
                                   {{' ',0,'n'},{' ',0,'n'},{' ',0,'n'},{' ',0,'n'},{' ',0,'n'},{' ',0,'n'},{' ',0,'n'},{' ',0,'n'}},
                                   {{' ',0,'n'},{' ',0,'n'},{' ',0,'n'},{' ',0,'n'},{' ',0,'n'},{' ',0,'n'},{' ',0,'n'},{' ',0,'n'}},
                                   {{'p',1,'w'},{'p',1,'w'},{'p',1,'w'},{'p',1,'w'},{'p',1,'w'},{'p',1,'w'},{'p',1,'w'},{'p',1,'w'}},
                                   {{'r',1,'w'},{'n',1,'w'},{'b',1,'w'},{'q',1,'w'},{'k',1,'w'},{'b',1,'w'},{'n',1,'w'},{'r',1,'w'}}};
// moving to the returned array
    for (int i = 0; i < 8; i++) {
      for(int j =0;j<8;j++){
        b[i][j]=a[i][j];
      }
   }
    return b[8][8];
}
//-------------------------------------------------------------------------------
struct s_text {      //scanned text structure
    int num[2];
    char letter[3];

};
//----------------------------------------------------------------------------
//structure for one place (a1) used in check mate
struct saved_place{
    int s_num;
    char s_ch;
};
//---------------------------------------------------------------------------------------------------------------------------


#endif // INITIALIZE_H_INCLUDED
