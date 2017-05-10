/*
 Transitive Closure function, which finds and returns the transitive
 closure of a graph. The graph is expected to be given as a 2D array.
 And a 2D array represented the transitive closure is returned.
 */

#include "trans_close.h"

void print_tc(int tc[d][d]){
  for(int i = 0; i < d; ++i){
    for(int j = 0; j< d; ++j)
      printf("%d",tc[i][j]);
    printf("\n");
  }
}
void DFS(int g[][d], int visited[], int v){
  visited[v] = 1;
  
  for(int i = 0; i < d; ++i){
    if(i != v && g[v][i] == 1 && visited[i] == 0)
      DFS(g,visited, i);
  }
}

void trans_close(int g[][d], int t_c[][d]){
  for ( int i = 0; i < d; ++i)
	{
      for( int j = 0; j < d; ++j)
	{
	  t_c[i][j] = 0;;
	}
    }
  for( int i = 0; i < d; ++i){
    DFS(g,t_c[i],i); 
  }
}
    

