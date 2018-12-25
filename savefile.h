#ifndef SAVEFILE_H_INCLUDED
#define SAVEFILE_H_INCLUDED
void savefile(char *q ,struct board_str e[8][8]){
FILE * fsave;
fsave=fopen("save.txt","wb");

fwrite(e, sizeof(char), 800, fsave);
fclose(fsave);
printf("game has been saved\n");
}





void loadfile(char *q ,struct board_str e[8][8],struct board_str m){
FILE * fsave;
fsave=fopen("save.txt","rb");


fread(e, sizeof(char), 800, fsave);


fclose(fsave);
printf("game has been loaded\n");
}

#endif // SAVEFILE_H_INCLUDED
