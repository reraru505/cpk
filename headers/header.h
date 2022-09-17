#ifndef HEADER
#define HEADER

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

int hash(char *s);

void compile(char *s);
void mksol(char *s);
void addlib(char *s);
void run(char *s);
void car(char *s);


char **lex();
int getcompilemode();
char *getprojname();
char *stripspace(char *c);
void setcompilemode(char **c,char * compilemode);
char * getlibs();

#endif //HEADER
