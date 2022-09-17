#include "header.h"



void compile(char *s){


    system ("find src -name \"*.c\" > tmp.txt");

    FILE *cfiles = fopen("tmp.txt","r");

    if(cfiles == NULL){                                  
    printf("NO confing file in this directory");                    
    return ;                                       
    }                                         
                                            
    char *src;                                        
    long numbytes;                                    
                                            
    fseek(cfiles, 0L, SEEK_END);                               
    numbytes = ftell(cfiles);                                  
    fseek(cfiles, 0L, SEEK_SET);                               
                                            
    src = (char*)calloc(numbytes, sizeof(char));                      
    if(src == NULL){                                  
    printf("file read error");                              
    return ;};                                     
                                            
    fread(src, sizeof(char), numbytes, cfiles);                        
    fclose(cfiles);

    for (long i = 0; i < numbytes;i++){
        if(src[i] == '\n'){
            src[i] = ' ';
        }
    }
  
    printf("COMPILEMODE is %d\n",getcompilemode()); //DEBUG
    
    int COMPILEMODE = getcompilemode();
    
    char *c = (char*) calloc(10000,sizeof(char));
    
    char *projname = stripspace(getprojname());
    
    printf("Project name is ]%s[",projname);
    

if(COMPILEMODE == 0){

 sprintf(c,"if [ -d \"bin\" ]\nthen\n\tgcc %s -Iheaders -o bin/%s\nelse\n\tmkdir bin && gcc %s -Iheaders -o bin/%s\nfi",src,projname,src,projname);

 system(c);

}else if(COMPILEMODE == 1){

 char * placeholder = getlibs();
 
 printf("%s\n",placeholder);

sprintf(c,"if [ -d \"bin\" ]\nthen\n\tgcc %s -Iheaders -Llibs %s -o bin/%s\nelse\n\tmkdir bin && gcc %s -Iheaders -Llibs %s -o bin/%s\nfi",src,placeholder,projname,src,placeholder,projname);
  
system(c);

}
    



}
