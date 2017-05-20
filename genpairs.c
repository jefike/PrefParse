/*
  This function generates the differs-by-one pairs for a given preference
expression by processing the key generated by the parsing functions.

The pairings for all-things-being-equal condition, or the "anything" case is 
shown below:

anything | chicken < shrimp      anything | soup > salad
     0010>0000 2>0                    0000>0100 0>4
     0011>0001 3>1                    0001>0101 1>5
     0110>0100 6>4                    0010>0110 2>6
     0111>0101 7>5                    0011>0111 3>7
     1010>1000 10>8                   1000>1100 8>12
     1011>1001 11>9                   1001>1101 9>13
     1110>1100 14>12                  1010>1110 10>14
     1111>1101 15>13                  1011>1111 11>15

anything | potatoes > pasta      anything | dessert > app
     0001>0000 1>0                    1000>0000 8>0
     0011>0010 3>2                    1001>0001 9>1
     0101>0100 5>4                    1010>0010 10>2
     0111>0110 7>6                    1011>0011 11>3
     1001>1000 9>8                    1100>0100 12>4
     1011>1010 11>10                  1101>0101 13>5
     1101>1100 13>12                  1110>0110 14>6
     1111>1110 15>14                  1111>0111 15>7

The key[8] contains the information for generating the above pairings.
The first 4 values of key (0-3) are the conditional part of the expression.
The remaining 4 values of key (4-7) are the preference part of the expression.

With the base (anything case) conditonal pairings as a starting point, all
other conditionals (chicken | potatoes > pasta, pasta | shrimp > chicken, etc.) 
where the conditional part is not "anything", are generated by adding/subtracting
offsets to the base pairs. The offsets correspond bit position values.

For instance the dessert offset can only be added to values between 0 and 7. 
The appetizer offset can only be subtracted to values 8 to 15. This offset
corresponds to binary numbers where the 4th bit (with value of 2^3).

Similarly, the starter, protein, and side offsets all have values corresponding
to their bit position in a four-bit binary number.
 */
#include "global.h"


void generate_pairs(int key[8], food course, int g[][V]){
  //offset variables for dessert, app, potatoes, pasta, soup
  //salad, shrimp, and chicken.
  int d,a,po,pa,so,sa,sh,c;
#ifdef DEBUG
  printf("Key is: %d %d %d %d | %d %d %d %d\n",key[0],key[1],key[2],key[3],
	 key[4],key[5],key[6],key[7]);
#endif
  switch(key[0]){ //dessert and appetizer offsets.
  case 3:
    d = 8; a = 0;
    break;
  case 2:
    d = 0; a = 8;
    break;
  case 0:
    d = 0; a = 0;
    break;
  }

  switch(key[1]){ // soup and salad offsets.
  case 3:
    so = 0; sa = 4;
    break;
  case 2:
    so = 4; sa = 0;
    break;
  case 0:
    so = 0; sa = 0;
    break;
  }
  switch(key[2]){ // shimp and chicken offsets.
  case 3:
    sh = 2; c = 0;
    break;
  case 2:
    sh = 0; c = 2;
    break;
  case 0:
    sh = 0; c = 0;
    break;
  }

  switch(key[3]){ // potatoes and pasta offsets.
  case 3:
    po = 1; pa = 0;
    break;
  case 2:
    po = 0; pa = 1;
    break;
  case 0:
    po = 0; pa = 0;
    break;
  }

      
  switch(course)
    {
    case OPTIONAL:
      if(key[4] == 1){ //dessert > appetizer
	g[8+sa+sh+po][0+sa+sh+po] = 1;
	g[9+sa+sh-pa][1+sa+sh-pa] = 1;
	g[10+sa-c+po][2+sa-c+po] = 1;
	g[11+sa-c-pa][3+sa-c-pa] = 1;
	g[12-so+sh+po][4-so+sh+po] = 1;
	g[13-so+sh-pa][5-so+sh-pa] = 1;
	g[14-so-c+po][6-so-c+po] = 1;
	g[15-so-c-pa][7-so-c-pa] = 1;
      }
      else if(key[4] == 0){ // appetizer > dessert
	g[0+sa+sh+po][8+so+sh+po] = 1;
	g[1+sa+sh-pa][9+so+sh-pa] = 1;
	g[2+sa+c+po][10+sa-c+po] = 1;
	g[3+sa-c-pa][11+sa-c-pa] = 1;
	g[4-so+sh+po][12-so+sh+po] = 1;
	g[5-so+sh-pa][13-so+sh-pa] = 1;
	g[6-so-c+po][14-so-c+po] = 1;
	g[7-so-c-pa][15-so-c-pa] = 1;
      }
      break;
    case STARTER:
      if(key[5] == 0){ // soup > salad
	g[0+d+sh+po][4+d+sh+po] = 1;
	g[1+d+sh-pa][5+d+sh-pa] = 1;
	g[2+d-c+po][6+d-c+po] = 1;
	g[3+d-c-pa][7+d-c-pa] = 1;
	g[8-a+sh+po][12-a+sh+po] = 1;
	g[9-a+sh-pa][13-a+sh-pa] = 1;
	g[10-a-c+po][14-a-c+po] = 1;
	g[11-a-c-pa][15-a-c-pa] = 1;
      }
      else if(key[5] == 1){ // salad > soup
	g[4+d+sh+po][0+d+sh+po] = 1;
	g[5+d+sh-pa][1+d+sh-pa] = 1;
	g[6+d-c+po][2+d-c+po] = 1;
	g[7+d-c-pa][3+d-c-pa] = 1;
	g[12-a+sh+po][8-a+sh+po] = 1;
	g[13-a+sh-pa][9-a+sh-pa] = 1;
	g[14-a-c+po][10-a-c+po] = 1;
	g[15-a-c-pa][11-a-c-pa] = 1;
      }
      break;
    case PROTEIN:
      if(key[6] == 1){  // shrimp > chicken
	g[2+d+sa+po][0+d+sa+po] = 1;
	g[3+d+sa-pa][1+d+sa-pa] = 1;
	g[6+d-so+po][4+d-so+po] = 1;
	g[7+d-so-pa][5+d-so-pa] = 1;
	g[10-a+sa+po][8-a+sa+po] = 1;
	g[11-a+sa-pa][9-a+sa-pa] = 1;
	g[14-a-so+po][12-a-so+po] = 1;
	g[15-a-so-pa][13-a-so-pa] = 1;
      }
      else if(key[6] == 0){ // chicken > shrimp
	g[0+d+sa+po][2+d+sa+po] = 1;
	g[1+d+sa-pa][3+d+sa-pa] = 1;
	g[4+d-so+po][6+d-so+po] = 1;
	g[5+d-so-pa][7+d-so-pa] = 1;
	g[8-a+sa+po][10-a+sa+po] = 1;
	g[9-a+sa-pa][11-a+sa-pa] = 1;
	g[12-a-so+po][14-a-so+po] = 1;
	g[13-a-so-pa][15-a-so-pa] = 1;
      }
      
      break;
    case SIDE:
      if(key[7] == 1){ // potatoes > pasta
	g[1+d+sa+sh][0+d+sa+sh] = 1;
	g[3+d+sa-c][2+d+sa-c] = 1;
	g[5+d-so+sh][4+d-so+sh] = 1;
	g[7+d-so-c][6+d-so-c] = 1;
	g[9-a+sa+sh][8-a+sa+sh] = 1;
	g[11-a+sa-c][10-a+sa-c] = 1;
	g[13-a-so+sh][12-a-so+sh] = 1;
	g[15-a-so-c][14-a-so-c] = 1;
      }
      else if(key[7] == 0){ // pasta > potatoes
	g[0+d+sa+sh][1+d+sa+sh] = 1;
	g[2+d+sa-c][3+d+sa-c] = 1;
	g[4+d-so+sh][5+d-so+sh] = 1;
	g[6+d-so-c][7+d-so-c] = 1;
	g[8-a+sa+sh][9-a+sa+sh] = 1;
	g[10-a+sa-c][11-a+sa-c] = 1;
	g[12-a-so+sh][13-a-so+sh] = 1;
	g[14-a-so-c][15-a-so-c] = 1;
      }
      break;
    default:
      printf("Error: invalid course parameter.");
      exit(1);
    }
}
