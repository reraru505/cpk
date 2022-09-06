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

// void compile(char *s){

  
//     printf("COMPILEMODE is %d\n",getcompilemode()); //DEBUG
    
//     int COMPILEMODE = getcompilemode();
    
//     char *c = (char*) calloc(10000,sizeof(char));
    
//     char *projname = stripspace(getprojname());
    
//     printf("Project name is ]%s[",projname);
    
// /*    
//     switch (COMPILEMODE){
//       case 0:
// 	system(c);
// 	break;
//       case 1:
//     }
// */

// if(COMPILEMODE == 0){

//  sprintf(c,"if [ -d  \"bin\" ]\nthen\n\tif [ -d \"src/**\" ]\n\t\tthen\n\t\t\tgcc src/*.c src/**/*.c -Iheaders -o bin/%s\n\t\telse\n\t\t\tgcc src/*.c -Iheaders -o bin/%s\n\t\tfi\nelse\n\tif [ -d \"src/**\" ]\n\t\tthen\n \t\t\tmkdir bin && gcc src/*.c src/**/*.c -Iheaders -o bin/%s\n\t\telse\n\t\t\tmkdir bin && gcc src/*.c -Iheaders -o bin/%s\n\n\t\tfi\nfi",projname,projname,projname,projname);

//  system(c);

// }else if(COMPILEMODE == 1){

//  char * placeholder = getlibs();

// sprintf(c,"if [ -d  \"bin\" ]\nthen\n\tif [ -d \"src/*/\" ]\n\t\tthen\n\t\t\tgcc src/*.c src/**/*.c -Iheaders -Llibs %s -o bin/%s\n\t\telse\n\t\t\tgcc src/*.c -Iheaders -Llibs %s -o bin/%s\n\t\tfi\nelse\n\tif [ -d \"src/*/\" ]\n\t\tthen\n \t\t\tmkdir bin && gcc src/*.c src/**/*.c -Iheaders -Llibs %s -o bin/%s\n\t\telse\n\t\t\tmkdir bin && gcc src/*.c -Iheaders -Llibs %s -o bin/%s\n\n\t\tfi\nfi",placeholder,projname,placeholder,projname,placeholder,projname,placeholder,projname);
  
// system(c);

// }
    



//}

void addlib(char *s){
  
  FILE *file;

  char ** c = lex();

  setcompilemode(c," 1");
  
  char *fileout = (char *) calloc(10000,sizeof(char));

  int l = 1000;//sizeof(c)/sizeof(c[0]);

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



























































































