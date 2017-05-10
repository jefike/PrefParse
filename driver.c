#include "global.h"

int main(){
  int cur_tok = yylex();
  int key[8] = {0,0,0,0,0,0,0,0};
  int G[V][V];
  memset(G,0,sizeof(int)*(V*V));
  
  while(cur_tok != DONE){
    parse(cur_tok, G, key);
    cur_tok = yylex();
  }
#ifdef DEBUG
  printf("G After Parsing:\n");
  for (int i = 0; i < V; ++i)
    {
      for(int j = 0; j < V; ++j)
	printf("%d ",G[i][j]);

      printf("\n");
    }
#endif
  return 0;
}
