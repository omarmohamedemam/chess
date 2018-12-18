#ifndef SAVEFILE_H_INCLUDED
#define SAVEFILE_H_INCLUDED
void savefile(char *q ,struct board_str e[8][8],struct board_str m){
FILE * fsave;
fsave=fopen("C:\\Users\\Game.bin","wb");
fwrite(&e,sizeof(m),1,fsave);
fclose(fsave);
}





void loadfile(char *q ,struct board_str e[8][8],struct board_str m){
FILE * fsave;
fsave=fopen("C:\\Users\\Game.bin","rb");
fwrite(&e,sizeof(m),1,fsave);
fclose(fsave);
}

#endif // SAVEFILE_H_INCLUDED
