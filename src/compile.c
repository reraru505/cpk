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

 sprintf(c,"if [ -d \"bin/release\" ]\nthen\n\tgcc -0 %s -Iheaders -o bin/release/%s\nelse\n\tmkdir bin bin/release && gcc -0 %s -Iheaders -o bin/release/%s\nfi",src,projname,src,projname);

 system(c);

}else if(COMPILEMODE == 1){

 char * placeholder = getlibs();
 
 printf("%s\n",placeholder);

sprintf(c,"if [ -d \"bin/releaase\" ]\nthen\n\tgcc -0 %s -Iheaders -Llibs %s -o bin/release/%s\nelse\n\tmkdir bin bin/release && gcc -0 %s -Iheaders -Llibs %s -o bin/release/%s\nfi",src,placeholder,projname,src,placeholder,projname);
  
system(c);

}else if(COMPILEMODE == 2){

    sprintf(c,"if [ -d \"bin/debug\" ]\nthen\n\tgcc %s -Iheaders -g -o bin/debug/%s\nelse\n\tmkdir bin bin/debug && gcc %s -Iheaders -g -o bin/debug/%s\nfi",src,projname,src,projname);

    system(c);

}else if(COMPILEMODE == 3){

 char * placeholder = getlibs();
 
 printf("%s\n",placeholder);

sprintf(c,"if [ -d \"bin/debug\" ]\nthen\n\tgcc %s -Iheaders -Llibs %s -g -o bin/debug/%s\nelse\n\tmkdir bin bin/debug && gcc %s -Iheaders -Llibs %s -g -o bin/debug/%s\nfi",src,placeholder,projname,src,placeholder,projname);
  
system(c);

}
    



}
