#include "header.h"


int main(int argc,char *argv[]){

  if (argc == 1){

    printf("Usage :\ncompile {to compile your project } \nrun {to run compiled project}\ncar {compile and run}\naddlib {to add lis to to the project mentioned in .cpk file}\nmksol {to make new solution}\n");
    return 0;
  }

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
