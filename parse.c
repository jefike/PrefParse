/*
  Key: 8-bit binary number.
  1-bit: side, pasta = 0, potatoes = 1
  2-bit: protein, chicken = 0, shrimp = 1
  4-bit: starter, soup = 0, salad = 1
  8-bit: Optional, app = 0, dessert = 1

Examples: 
anything | chicken < shrimp   00000010
anything | soup > salad       0000
anything | potatoes > pasta   00000001
anything | dessert > app      1000
chicken  | dessert > app      00201000                
  0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 
0                
1    
2 1  
3
4
5
6
7
8                         
9
10
11                                 
12
13
14
15
Eight pairs for first rule:

*/
#include "global.h"

void parse(int tok, int G[][V], int key[8]){
  int next_tok;
  
  switch(tok){
  case ANY:
    //already all zeros. Do nothing.
    break;
  case CHK:
    key[2] = 2;
    break;
  case SHR:
    key[2] = 3;
    break;
  case PAS:
    key[0] = 2;
    break;
  case POT:
    key[0] = 3;
    break;
  case APP:
    key[3] = 2;
    break;
  case DES:
    key[3] = 3;
    break;
  case SOU:
    key[1] = 2;
    break;
  case SAL:
    key[1] = 3;
    break;
  case '|':
    next_tok = yylex();
    parse2(key, next_tok);
    break;
  default:
    printf("Error: invalid start of preference expression.\n");
    exit(1);
  }//end switch
}
