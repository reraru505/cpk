#include "header.h"

void run(char *s){
	
	char* name =  stripspace(getprojname());
	char* command = (char *) calloc(1000,sizeof(char));
	sprintf(command,"./bin/%s",name);
	printf("%s\n",command);
	system(command);
}

void car(char *s){

  compile(s);
  
  char* name =  stripspace(getprojname());
  char* command = (char *) calloc(1000,sizeof(char));
  sprintf(command,"./bin/%s",name);
  printf("%s\n",command);
  system(command);
}

int main(int argc,char *argv[]){

  void (*mksol_ptr)(char*) = &mksol;
  void (*compile_ptr)(char*) = &compile;
  void (*addlib_ptr)(char*) = &addlib;
  void (*run_ptr)(char*) = &run;
  void (*car_ptr)(char*) = &car;
  
  void (*funarr[1000])(char*);

  funarr[hash("mksol")] = mksol_ptr;
  funarr[hash("compile")] = compile_ptr;
  funarr[hash("addlib")] = addlib_ptr;
  funarr[hash("run")] = run_ptr;
  funarr[hash("car")] = car_ptr;
  
  funarr[hash(argv[1])](argv[2]);

  return 0;

}
