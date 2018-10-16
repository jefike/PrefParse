/*

  Parse Function. Parses the first portion of the preference expression
  and sets the first four values in the key. Then calls parse2() when the
  '|' token is encountered.
  
  Key: 8-bit binary number.
  1-bit: side, pasta = 0, potatoes = 1
  2-bit: protein, chicken = 0, shrimp = 1
  4-bit: starter, soup = 0, salad = 1
  8-bit: optional, app = 0, dessert = 1
  16-bit: side, pasta = 2, potatoes = 3, no-pref = 0
  32-bit: protein, chicken = 2, shrimp = 3, no-pref = 0
  64-bit: starter, soup = 2, salad = 3, no-pref = 0
  128-bit: optional, app = 2, dessert = 3, no-pref = 0

Examples: 
anything | chicken < shrimp               00000010
anything | soup > salad                   00000000
anything | potatoes > pasta               00000001
anything | dessert > app                  00001000
chicken  | dessert > app                  00201000                
dessert chicken potatoes | salad > soup   30230100 
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
    key[3] = 2;
    break;
  case POT:
    key[3] = 3;
    break;
  case APP:
    key[0] = 2;
    break;
  case DES:
    key[0] = 3;
    break;
  case SOU:
    key[1] = 2;
    break;
  case SAL:
    key[1] = 3;
    break;
  case '|':
    next_tok = yylex();
    parse2(key, next_tok, G);
    memset(key,0,sizeof(int)*8);
    break;
  default:
    printf("Error: invalid start of preference expression.\n");
    exit(1);
  }//end switch
}
