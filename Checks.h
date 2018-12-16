#ifndef CHECKS_H_INCLUDED
#define CHECKS_H_INCLUDED
int eat;// if the pawn going to eat or not
//check the way of move is free or not and the next cell also
int way_check(struct board_str e[8][8],char i1,int j1,char i2,int j2,char r){
        int flag=0;
        int w=i2-'A';
        int v=j2-1;
        int x=i1-'A';
        int z=j1-1;
      //for pawns
      if(r=='p'||r=='P'){
                if(e[v][w].print==' '){
           if(v>z && v-z>1){
                for(int i=z+1;i<v ;i++){//check the way for row (if he want to go to second row we must check way )
                    if(e[i][x].print==' '){
                        flag=1;
                    }
                    else{
                        flag=0;
                        break;
                    }
                }
           }
           else if(z>v&& z-v>1){
            for(int i=z-1;i>v ;i--){//check the way for row (if he want to go to second row we must check way )
                    if(e[i][x].print==' '){
                        flag=1;
                    }
                    else{
                        flag=0;
                        break;
                    }
                }
           }
           else if( abs(v-z)==1){
                flag=1;
           }


        }
        else if((e[v][w].color!= e[z][x].color)&& (e[v][w].print!=' ') && eat)
            if( abs(v-z)==1){
                flag=1;
           }
      }


    //for rook
    if(r=='r'||r=='R'){
            if(e[v][w].print==' ' ||(e[v][w].color!= e[z][x].color)){

           if(i1==i2){
                if(v>z && v-z>1){
             for(int i=z+1;i<v ;i++){//check for rows
                if(e[i][x].print==' '){
                   flag=1;
                }
                else{
                    flag=0;
                    break;
                }
            }
                }
                else if(v<z && z-v>1){
                for(int i=z-1;i>v ;i--){//check for rows
                    if(e[i][x].print==' '){
                   flag=1;
                }
                    else{
                        flag=0;
                    break;
                }
            }
                }
                else if( abs(v-z)==1){
                    flag=1;
            }
                }
           else if(j1==j2){
                        if(w>x && w-x>1){
                    for(int i=x+1;i<w ;i++){//check the way at col
                        if(e[z][i].print==' '){
                            flag=1;
                        }

                        else{
                            flag=0;
                            break;
                        }
                        }
                    }
                    else if(w<x && x-w>1){
                         for(int i=x-1;i>w ;i--){//check the way at col
                        if(e[z][i].print==' '){
                            flag=1;
                            }
                            else{
                                flag=0;
                                break;
                            }
                        }
                    }
                        else if( abs(w-x)==1){
                            flag=1;
                        }
                    }

                }
                }
    if(r=='n'||r=='N'){
           //for knight
           if(e[v][w].print==' ' ||(e[v][w].color!= e[z][x].color)){

             flag=1;//he don't need to check more because it jumps
           }
            else{
                    flag=0;
            }
    }
    if(r=='k'||r=='K'){
           //for king
           if(e[v][w].print==' ' ||(e[v][w].color!= e[z][x].color)){
                flag=1;
           }
            else{
                    flag=0;
                }
    }
    if(r=='b'||r=='B'){
                if(e[v][w].print==' ' ||(e[v][w].color!= e[z][x].color)){

                        if(v>z && w>x && abs(v-z)>1 && abs(w-x)>1 ){
                            for(int i=z+1, j=x+1; (i<v&&j<w) ;i++,j++){//check for rows
                                if(e[i][j].print==' '){
                                    flag=1;
                                }
                                else{
                                    flag=0;
                                    break;
                                }
                            }
                        }
                        else if(v>z && w<x && abs(v-z)>1 && abs(w-x)>1){
                            for(int i=z+1, j=x-1;(i<v&&j>w) ;i++,j--){//check for rows
                                if(e[i][j].print==' '){
                                    flag=1;
                                }
                                else{
                                    flag=0;
                                    break;
                                }
                            }
                        }
                        else if(v<z && w<x && abs(v-z)>1 && abs(w-x)>1){
                            for(int i=z-1, j=x-1;(i>v&&j>w) ;i--,j--){//check for rows
                                if(e[i][j].print==' '){
                                    flag=1;
                                }
                                else{
                                    flag=0;
                                    break;
                                }
                            }
                        }
                        else if(v<z && w>x && abs(v-z)>1 && abs(w-x)>1){
                            for(int i=z-1, j=x+1;(i>v&&j<w) ;i--,j++){//check for rows
                                if(e[i][j].print==' '){
                                    flag=1;
                                }
                                else{
                                    flag=0;
                                    break;
                                }
                            }
                        }
                        else if(abs(v-z)==1 && abs(w-x)==1){
                            flag=1;
                        }
                }
    }
     if(r=='q'||r=='Q'){
                if(e[v][w].print==' ' ||(e[v][w].color!= e[z][x].color)){
                                 if(i1==i2){
                if(v>z && v-z>1){
             for(int i=z+1;i<v ;i++){//check for rows
                if(e[i][x].print==' '){
                   flag=1;
                }
                else{
                    flag=0;
                    break;
                }
            }
                }
                else if(v<z && z-v>1){
                for(int i=z-1;i>v ;i--){//check for rows
                    if(e[i][x].print==' '){
                   flag=1;
                }
                    else{
                        flag=0;
                    break;
                }
            }
                }
                else if( abs(v-z)==1){
                    flag=1;
            }
                }
           else if(j1==j2){
                        if(w>x && w-x>1){
                    for(int i=x+1;i<w ;i++){//check the way at col
                        if(e[z][i].print==' '){
                            flag=1;
                        }

                        else{
                            flag=0;
                            break;
                        }
                        }
                    }
                    else if(w<x && x-w>1){
                         for(int i=x-1;i>w ;i--){//check the way at col
                        if(e[z][i].print==' '){
                            flag=1;
                            }
                            else{
                                flag=0;
                                break;
                            }
                        }
                    }
                        else if( abs(w-x)==1){
                            flag=1;
                        }
                    }

                        else if(v>z && w>x && abs(v-z)>1 && abs(w-x)>1 ){
                            for(int i=z+1, j=x+1; (i<v&&j<w) ;i++,j++){//check for rows
                                if(e[i][j].print==' '){
                                    flag=1;
                                }
                                else{
                                    flag=0;
                                    break;
                                }
                            }
                        }
                        else if(v>z && w<x && abs(v-z)>1 && abs(w-x)>1){
                            for(int i=z+1, j=x-1;(i<v&&j>w) ;i++,j--){//check for rows
                                if(e[i][j].print==' '){
                                    flag=1;
                                }
                                else{
                                    flag=0;
                                    break;
                                }
                            }
                        }
                        else if(v<z && w<x && abs(v-z)>1 && abs(w-x)>1){
                            for(int i=z-1, j=x-1;(i>v&&j>w) ;i--,j--){//check for rows
                                if(e[i][j].print==' '){
                                    flag=1;
                                }
                                else{
                                    flag=0;
                                    break;
                                }
                            }
                        }
                        else if(v<z && w>x && abs(v-z)>1 && abs(w-x)>1){
                            for(int i=z-1, j=x+1;(i>v&&j<w) ;i--,j++){//check for rows
                                if(e[i][j].print==' '){
                                    flag=1;
                                }
                                else{
                                    flag=0;
                                    break;
                                }
                            }
                        }
                        else if(abs(v-z)==1 && abs(w-x)==1){
                            flag=1;
                        }
                }
    }

return flag;
}
//-----------------------------------------------------------------------
//checking the special move  for the pawn
int check_eat(char a,char b){
  int flag=0;
  if(a=='b'&&b=='w'){
    flag =1;
  }
  else if (a=='w'&&b=='b'){
    flag =1;
  }
    if(flag==0){
        red();
        printf("Error : Invalid move \n");
        reset();
    }
    return flag;
}
//----------------------------------------------------------------------+
//checking the promotion case
int check_promo(char kind , char colore,char i1,int j1,char i2,int j2){
    int flag=0;
    if((i1==i2) && ((j2==1 && colore=='w')||(j2==8 && colore=='b')) && (kind=='p'||kind=='P')){
        flag =1;
    }
    return flag;
}
//--------------------------------------------------------------------------

#endif // CHECKS_H_INCLUDED
