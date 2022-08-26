#include "header.h"

char **lex(){									    
										    
  FILE *f = fopen("cpkinfo.cpk","r");						    
  if(f == NULL){								    
    printf("NO confing file in this directory");				    
    return 0;									    
  }										    
										    
  char *str;									    
  long numbytes;								    
										    
  fseek(f, 0L, SEEK_END);							    
  numbytes = ftell(f);								    
  fseek(f, 0L, SEEK_SET);							    
										    
  str = (char*)calloc(numbytes, sizeof(char));   				    
  if(str == NULL){								    
    printf("file read error");							    
    return 0;};									    
										    
  fread(str, sizeof(char), numbytes, f);					    
  fclose(f);									    
										    
  printf("%s",str); //Debug							    
										    
//  char **c = (char**) malloc(1000 * sizeof(char*));				    
//  for(int i = 0 ; i < 1000;i++){						    
//    c[i] = (char*) malloc(100 * sizeof(char));				    
//										    
//}										    
  char **c = (char **) calloc(1000, sizeof(char *));				    
  for(int i = 0;i < 1000;i++){							    
    c[i] = (char*) calloc(100,sizeof(char));					    
  }										    
										    
  // char c[100][100];								    
  int i = 0;									    
  int j = 0;									    
  int k = 0;									    
  int l = 0;									    
  										    
  while(i < numbytes){								    
    if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t' ){			    
      printf("whitespase found\n");						    
      while(j < i){								    
	c[k][l] = str[j];							    
	printf("c[%d][%d] is set to str[%d]\n",k,l,j);				    
	j++;									    
	l++;									    
      }										    
      i++;									    
      l = 0;									    
      k++;									    
    }										    
    i++;									    
  }										    
										    
 										    
										    
  printf("printing array\n");							    
										    
  for(int i = 0; i < k ; i++){ 							    
    printf("%s\n",c[i]);		//DEBUG					    
   }										    
										    
  return c;									    
										    
										    
}										    
										    
										    
int getcompilemode(){								    
										    
  char **c  = lex();								    
										    
  int index = 0;								    
  int i = 1;									    
  while(index < 100){								    
    printf("Getcompilemode loop run\n");					    
    if(!strcmp(c[index],"\nCOMPILEMODE") || !strcmp(c[index],"COMPILEMODE")){	    
      										    
      break;									    
    }										    
										    
    index++;									    
  }										    
										    
  //printf("]%s[",);								    
  										    
  int returnval = atoi(c[index + 2]);

  return returnval;
  										    
										    
}										    


char *getprojname(){

  char **c  = lex();								    
										    
  int index = 0;								    
  int i = 1;									    
  while(index < 100){								    
    printf("Getprojectname loop run\n");					    
    if(!strcmp(c[index],"\nSOLNAME") || !strcmp(c[index],"SOLNAME")){	    
      										    
      break;									    
    }										    
										    
    index++;									    
  }										    
	printf("c[index] is %s",c[index + 1]);  
  return c[index + 2];		

}

char *stripspace(char *c){

	int l = strlen(c);
	char *retval = (char*) calloc(50,sizeof(char));
	int j = 0;
	for(int i = 0;i < l;i++){
	if(!isspace(c[i])){
		retval[j] = c[i];
		j++;
	}
	}
	
	return retval;
}








