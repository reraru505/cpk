#include "header.h"

void run(char *s){
	
  int COMPILEMODE = getcompilemode();

	char* name =  stripspace(getprojname());
	char* command = (char *) calloc(1000,sizeof(char));

	

  if(COMPILEMODE == 0 || COMPILEMODE == 1){
    sprintf(command,"./bin/release/%s",name);
  }else if(COMPILEMODE == 2 || COMPILEMODE == 3){
    sprintf(command,"./bin/debug/%s",name);
  }

	printf("%s\n",command);
	system(command);
}

void car(char *s){

  compile(s);
  
  run(s);
}


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


void addlib(char *s){
  
  FILE *file;

  char ** c = lex();

  setcompilemode(c," 1");
  
  char *fileout = (char *) calloc(10000,sizeof(char));

  int l = 1000;

  for(int i = 0;i < l;i++){strcat(fileout,c[i]);}

  file = fopen("cpkinfo.cpk","w");
   if (file == NULL)
    {
        printf("Could not open file\n");
        return ;
    }

  fprintf(file,"%s",fileout);

  fclose(file);


}



























































































