#include "header.h"

int main(int argc,char *argv[]){

  void (*mksol_ptr)(char*) = &mksol;
  void (*compile_ptr)(char*) = &compile;
  //void (*lex_ptr)(char*) = &lex;
  
  void (*funarr[1000])(char*);

  funarr[hash("mksol")] = mksol_ptr;
  funarr[hash("compile")] = compile_ptr;
  //  funarr[hash("lex")] = lex_ptr;

  
  funarr[hash(argv[1])](argv[2]);

  return 0;

}
