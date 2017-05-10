#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
  Define tokens for meal.
 */
#define ANY 256  // anything
#define CHK 257  // chicken
#define SHR 258  // shrimp
#define PAS 259  // pasta
#define POT 260  // potatoes
#define APP 261  // appetizer
#define DES 262  // dessert
#define SOU 263  // soup
#define SAL 264  // salad
#define DONE 265 //EOF
#define V 16 // static size of the graph adjacency matrix.

typedef enum MENU {
  OPTIONAL,
  STARTER,
  PROTEIN,
  SIDE
}food;

void parse2(int key[8], int next_tok, int g[][V]);
void generate_pairs(int key[8], food course, int g[][V]);
void parse(int tok, int G[][V], int key[8]);

extern int yylex();
