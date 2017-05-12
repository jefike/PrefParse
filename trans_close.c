/*
 Transitive Closure function, which finds and returns the transitive
 closure of a graph. The graph is expected to be given as a 2D array.
 And a 2D array represented the transitive closure is returned.
 */

#include "global.h"

void print_tc(int tc[V][V]){
  printf("Transitive Closure:\n");
  for(int i = 0; i < V; ++i){
    for(int j = 0; j< V; ++j){
      printf("%d ",tc[i][j]);
    }
    printf("\n");
  }
}
void DFS(int g[][V], int visited[], int v){
  visited[v] = 1;
  
  for(int i = 0; i < V; ++i){
    if(i != v && g[v][i] == 1 && visited[i] == 0)
      DFS(g,visited, i);
  }
}

void trans_close(int g[][V], int t_c[][V]){
  for ( int i = 0; i < V; ++i)
	{
      for( int j = 0; j < V; ++j)
	{
	  t_c[i][j] = 0;;
	}
    }
  for( int i = 0; i < V; ++i){
    DFS(g,t_c[i],i); 
  }
}
    

