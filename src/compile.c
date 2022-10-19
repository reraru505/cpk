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

 sprintf(c,"if [ -d \"release/bin\" ]\nthen\n\tgcc -O0 %s -Iheaders -o release/bin/%s\nelse\n\tmkdir release release/bin && gcc -O0 %s -Iheaders -o release/bin/%s\nfi",src,projname,src,projname);

 system(c);

}else if(COMPILEMODE == 1){

 char * placeholder = getlibs();
 
 printf("%s\n",placeholder);

sprintf(c,"if [ -d \"release/bin\" ]\nthen\n\tgcc -O0 %s -Iheaders -Llibs %s -o release/bin/%s\nelse\n\tmkdir release release/bin && gcc -O0 %s -Iheaders -Llibs %s -o release/bin/%s\nfi",src,placeholder,projname,src,placeholder,projname);
  
system(c);

}else if(COMPILEMODE == 2){

    sprintf(c,"if [ -d \"debug/bin\" ]\nthen\n\tgcc %s -Iheaders -g -o debug/bin/%s\nelse\n\tmkdir debug debug/bin && gcc %s -Iheaders -g -o debug/bin/%s\nfi",src,projname,src,projname);

    system(c);

}else if(COMPILEMODE == 3){

 char * placeholder = getlibs();
 
 printf("%s\n",placeholder);

sprintf(c,"if [ -d \"debug/bin\" ]\nthen\n\tgcc %s -Iheaders -Llibs %s -g -o debug/bin/%s\nelse\n\tmkdir debug debug/bin && gcc %s -Iheaders -Llibs %s -g -o debug/bin/%s\nfi",src,placeholder,projname,src,placeholder,projname);
  
system(c);

}
    



}
