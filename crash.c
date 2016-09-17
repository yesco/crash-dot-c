//; RUN: gcc -fpermissive crash.c && ./a.out 2 3 4 5 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <setjmp.h>

int main(int argc, char **argv) {
  int mem() { long a[(unsigned)999999999999] = {0}; printf("RETURN %d\n", sizeof(a)); return a[0]; };
  printf("Usages: crash 2 3 4 5...\n");
  printf("crashing by %d\n", argc);
  int *i = &argc;
  switch (argc) {
  case 1: main(argc, argv);
  case 2: {typeof(main) *x=NULL; x(argc, argv); }
  case 3: *(char*)NULL = 3;
  case 4: *(char*)argc = NULL;
  case 5: exit(1/0);
  case 6: while(fork());
  case 7: fprintf(NULL, "helo");
  case 8: printf((char*)printf(NULL));
  case 9: for(*i = 0; 10; i++) {
  case 10: *(char*)(&i+*i) = main;
  case 11: printf("."+*i); } break;
  case 12: goto *42;
  case 13: return main;
  case 14: fflush((int)fflush);
  case 15: setjmp((typeof(NULL))longjmp);
  case 16: longjmp(NULL, NULL);
  case 17: printf("%*s", main);
  case 18: sscanf(NULL, "%d", main); main(argc, argv); break;
  case 19: mem();
  case 20: while(*i++ = 3);
  default: main((char)(argc + random()), argv);
  }
}
