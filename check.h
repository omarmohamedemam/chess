#ifndef CHECK_H_INCLUDED

#define CHECK_H_INCLUDED

 int counter_R,counter_N,counter_B,counter_P;
    int x1,y1,x2y2,x3,y3,x4,y4,x5,y5;
    int x11,y11,x22,y22,x33,y33,x44,y44,x55,y55;
    /*king at black box (x1,y1),queen at black box (x2,y2),rook at black box (x3,y3),bishop at black box (x4,y4),knight at black box (x5,y5)
    pawns at black box (x6,y6)*/
    //rook at 2 places put it in arr
    //rook at 1 place (x3,y3) for black (x33,y33) for white
    //bishop at 2 places put it in arr
    //bishop at 1 place (x4,y4) for black (x44,y44) for white
    //knight at 2 places put it in arr
    //knight at 1 place (x5,y5) for black (x55,y55) for white
    int f[2];
int king_b_place(char kind,char colors,int color,int x,int y){
    int flag=0;
    int a;
     if(colors=='b' && kind=='K'){
        if(color==1){
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(a[i][j]='K'){
                        x1=i,y1=j;
                        f[0]=x1;
                        f[1]=y1;
                        flag=1;
                    }
                }
            }
        }else if(color==0){
                for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(a[i][j]='K'){
                        x11=i,y11=j;
                        flag=1;

                    }
                }
            }

        }
     }
}
 //for queen
 int e[2];
 int queen_b_place(char kind,char colors,int color){
     int a;
     if(colors=='b' && kind=='Q'){
        if(color==1){
            for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(a[i][j]='Q'){
                        x2=i,y2=j;
                        e[0]=x2;
                        e[1]=y2;
                        flag=1;


                    }
                }
            }
        }else if(color==0){
                for(int i=0;i<8;i++){
                for(int j=0;j<8;j++){
                    if(a[i][j]='Q'){
                        x22=i,y22=j;
                        flag=1;


                    }
                }
            }

        }
     }
 }
 //rook
 int rook_b_place(char kind,char colors,int color,counter_R){
     int rook_arr[4]={0};
     int a;
     k=0,h=k+1;
      if(colors=='b' && kind=='R'){
            if(counter_R==2){
                if(color==1){
                    for(int i=0;i<8;i++){
                        for(int j=0;j<8;j++){
                            if(a[i][j]='R'){
                                rook_arr[k++]=i;
                                rook_arr[h++]=j;
                                flag=1;


                            }
                        }

                    }

                }else if(color==0){
                        for(int i=0;i<8;i++){
                            for(int j=0;j<8;j++){
                                if(a[i][j]='R'){
                                rook_arr[k++]=i;
                                rook_arr[h++]=j;
                                flag=1;
                                 }
                            }
                        }
                }
            }else if(counter_R==1){
                    if(color==1){
                        for(int i=0;i<8;i++){
                            for(int j=0;j<8;j++){
                                if(a[i][j]='R'){
                                    x3=i,y3=j;
                                    flag=1;
                                }
                            }
                        }
                    }else if(color==0){
                        for(int i=0;i<8;i++){
                            for(int j=0;j<8;j++){
                                if(a[i][j]='R'){
                                    x33=i,y33=j;
                                    flag=1;
                                }
                            }
                        }

                    }
            }

      }
 }
  //for knight
  int knight_b_place(char kind,char colors,int color,counter_N){
      int knight_arr[4]={0};
      int flag=0;
      k=0,h=k+1;
        if(colors=='b' && kind=='N'){
            if(counter_N==2){
                if(color==1){
                    for(int i=0;i<8;i++){
                        for(int j=0;j<8;j++){
                            if(a[i][j]='N'){
                                knight_arr[k++]=i;
                                knight_arr[h++]=j;
                                flag=1;
                            }
                        }
                    }

                }else if(color==0){
                        for(int i=0;i<8;i++){
                            for(int j=0;j<8;j++){
                                if(a[i][j]='N'){
                                knight_arr[k++]=i;
                                knight_arr[h++]=j;
                                }
                            }
                        }

                }
            }else if(counter_N==1){
                if(color==1){
                    for(int i=0;i<8;i++){
                        for(int j=0;j<8;j++){
                            if(a[i][j]='N'){
                                x5=i,y5=j;
                                flag=1;
                            }
                        }
                    }
                }else if(color==0){
                        for(int i=0;i<8;i++){
                            for(int j=0;j<8;j++){
                                if(a[i][j]='N'){
                                    x55=i,y55=j;
                                    flag=1;
                                }
                            }
                        }

                    }
            }

      }
  }//for bishop
  int bishop_b_place(char kind,char colors,int color,counter_B){
      int bishop_arr[4]={0};
      int k=0,h=k+1;
          if(colors=='b' && kind=='B'){
            if(counter_B==2){
                if(color==1){
                    for(int i=0;i<8;i++){
                        for(int j=0;j<8;j++){
                            if(a[i][j]='B'){
                                bishop_arr[k++]=i;
                                bishop_arr[h++]=j;

                            }
                        }
                    }
                }else if(color==0){
                        for(int i=0;i<8;i++){
                            for(int j=0;j<8;j++){
                                if(a[i][j]='B'){
                                bishop_arr[k++]=i;
                                bishop_arr[h++]=j;
                                }
                            }
                        }
                    }
            }else if(counter_B==1){
                if(color==1){
                    for(int i=0;i<8;i++){
                        for(int j=0;j<8;j++){
                            if(a[i][j]='B'){
                                x4=i,y4=j;
                                flag=1;
                            }
                        }
                    }
                }else if(color==0){
                        for(int i=0;i<8;i++){
                            for(int j=0;j<8;j++){
                                if(a[i][j]='B'){
                                    x44=i,y44=j;
                                    flag=1;
                                }
                            }
                        }

                    }
            }

      }
  }
  int pawns_b_place(char kind,char colors,int color,counter_P){
      int pawns_arr[8]={0};
          int t=0,r=t+1;
          if(colors=='b' && kind=='P'){
                for(int k=1;k<=8;k++){
                if(counter_P==i){
                    if(color==1){
                        for(int i=0;i<8;i++){
                            for(int j=0;j<8;j++){
                                if(a[i][j]='P'){
                                    pawns_arr[t++]=i;
                                    pawns_arr[r++]=j;

                                }
                            }
                        }
                    }else if(color==0){
                            for(int i=0;i<8;i++){
                                for(int j=0;j<8;j++){
                                    if(a[i][j]='B'){
                                   pawns_arr[t++]=i;
                                    pawns_arr[r++]=j;
                                    }
                                }
                            }
                        }
                }
          }
      }

  }

}


#endif // CHECK_H_INCLUDED
