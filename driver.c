/*
    Main/Driver function. Declares and initializes matrices and calls
    the parse function.
*/
#include "global.h"


int main(){
  int cur_tok = yylex();
  int key[8] = {0,0,0,0,0,0,0,0}; // Parsing key
  int G[V][V];     // Meal Matrix
  int t_c[V][V];  // Transitive Closure of Meal Matrix
  memset(G,0,sizeof(int)*(V*V));
  memset(t_c,0,sizeof(int)*(V*V));
  
  while(cur_tok != DONE){
    parse(cur_tok, G, key);
    cur_tok = yylex();
  }
#ifdef DEBUG
  printf("\nG After Parsing:\n");
  for (int i = 0; i < V; ++i)
    {
      for(int j = 0; j < V; ++j)
	printf("%d ",G[i][j]);

      printf("\n");
    }
#endif
  trans_close(G,t_c);
  print_tc(t_c);
  return 0;
}
