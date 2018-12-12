#ifndef CHECKS_H_INCLUDED
#define CHECKS_H_INCLUDED
//مبداياً 
//there are some mistakes we will fix again 
int check(struct board_str e[8][8],char a,int b,char c,int d){
        int flag=0,q;
        int w=c-'A';
        int v=d-1;
        int x=a-'A';
        int z=b-1;
        e[v][w].print
        e[v][w].color
        e[z][x].color
      //for pawns
        if(e[v][w].print==' ' ||(e[v][w].color!= e[z][x].color)){
            for(int i=z;i<v ;i++){//check the way for row (if he want to go to second row we must check way )
                if(e[i][x].print!=' '){
                   q= pawns_black();
                }
            }

        }

    //for rook
            if(e[v][w].print==' ' ||(e[v][w].color!= e[z][x].color)){
           if(i1==i2){
             for(int i=z;i<v ;i++){//check for rows
                if(e[i][x].print!=' '){
                   q= rock();
                }
            }
           }else{
                if(j1==j2){
                    for(int i=x;i<w ;i++){//check the way at col
                        if(e[z][i].print!=' '){
                            q= rock();
                }
            }
                }

           }
           //for knight
           if(e[v][w].print==' ' ||(e[v][w].color!= e[z][x].color)){

             q= knight();//he don't need to check more because it jumps


           }
           //for king
           if(e[v][w].print==' ' ||(e[v][w].color!= e[z][x].color)){
           if(i1==i2){
             for(int i=z;i<v ;i++){//check the way at rows
                if(e[i][x].print!=' '){
                   q= king();
                }
            }
           }else{
                if(j1==j2){
                    for(int i=x;i<w ;i++){//check the way at col
                        if(e[z][i].print!=' '){
                            q= king();
                }
            }
                }


           }
    }

#endif // CHECKS_H_INCLUDED
