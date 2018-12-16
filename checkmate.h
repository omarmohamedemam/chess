#ifndef CHECKMATE_H_INCLUDED
#define CHECKMATE_H_INCLUDED
int eat;
int king_place(struct board_str a[8][8],char kind,char colors,int turn){
    struct saved_place save [16];
    int s_count=0;
    int x1,y1;
    int a1;
    int x;
     if(colors=='b' && kind=='K' && (!turn)){
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(a[i][j].print='K'){
                        x1=i,y1=j;
                        x1=x1+1;
                        y1=(char)(y1+65);
                        break;

                    }
                }
            }
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                        if(a[i][j].print !=' '&& a[i][j].color=='w'){
                                int f_num=i+1;
                                char f_ch=j+65;
                            switch(a[i][j].print){
                                case('r'):
                                    a1=rock_black_k(f_ch,f_num,y1,x1);
                                    break;
                                case('n'):
                                    a1=knight_k(f_ch,f_num,y1,x1);
                                    break;
                                case('b'):
                                    a1=bishop_black_k(f_ch,f_num,y1,x1);
                                    break;
                                case('k'):
                                    a1=king_k(f_ch,f_num,y1,x1);
                                    break;
                                case('q'):
                                    a1=queen_k(f_ch,f_num,y1,x1);
                                    break;
                                case('p'):
                                    eat=pawn_eat_k(f_ch,f_num,y1,x1,a[i][j].color,colors);
                                     x=pawns_white(f_ch,f_num,y1,x1);
                                     a1=eat||x;
                                    break;
                            }
                            int b1 =int check(a,f_ch,f_num,y1,x1,a[i][j].print);
                            if(b1 && a1){
                                save[s_count].s_ch=f_ch;
                                save[s_count].s_num=f_num;
                                s_count++;
                            }
                        }
                }
            }
            if(s_counter>0){
               red();
                printf("Check Mate for T he Black King \n");
                reset();
            }
            else if(s_count==0){
                //get out
            }
        }

     else if(colors=='w' && kind=='k' && turn){
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(a[i][j].print='k'){
                        x1=i,y1=j;

                    }
                }
            }
        }


#endif // CHECKMATE_H_INCLUDED
