#include "header.h"

void mksol(char *s){

  int len = strlen(s);
  
  char s2[500];
  
  FILE *file;

  char C[1024];

  

  sprintf(C,"mkdir %s %s/src %s/headers",s,s,s);


  system(C);
  
  sprintf(s2,"%s/cpkinfo.cpk",s);

  file = fopen(s2,"w");
   if (file == NULL)
    {
        printf("Could not open file\n");
        return ;
    }

  fprintf(file,"SOLNAME = %s\nCOMPILEMODE = 0\n",s);

  fclose(file);

  

  
}

void compile(char *s){

  if(strlen(s) == 0){
    system("./cpkshelldep/compile.sh");
  }else{
    printf("please try without args");
  }
}
