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

  
    printf("COMPILEMODE is %d\n",getcompilemode()); //DEBUG
    
    int COMPILEMODE = getcompilemode();

    switch (COMPILEMODE){
      case 0:
	system("if [ -d  \"bin\" ]\nthen\ngcc src/*.c -Iheaders -o bin/cpk\nelse\nmkdir bin && gcc src/*.c -Iheaders -o bin/cpk\nfi");
	break;
    }



}


























































































