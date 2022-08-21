#include "header.h"

int main(int argc,char *argv[]){

  void (*mksol_ptr)(char*) = &mksol;
  void (*compile_ptr)(char*) = &compile;

  void (*funarr[1000])(char*);

  funarr[13] = mksol_ptr;


  funarr[hash(argv[1])](argv[2]);

  return 0;

}
