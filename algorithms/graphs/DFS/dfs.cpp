#include <bits/stdc++.h>

using namespace std;

int vertice, edge;
vector < vector <int> > graph(10e6+100);
vector <bool> processed(10e6+100);

//depth-first search
void DFS(int node){
   processed[node]=true;

   for(auto son : graph[node]){

      if(!processed[son]){
         cout << son << " ";
         processed[son]=true;
         DFS(son);
      }
   }
}

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   cin >> vertice >> edge;

   //initializing a graph
   for(int i=0; i<edge; i++){
      int from, to;
      cin >> from >> to;

      graph[from].push_back(to);
      graph[to].push_back(from);
   }

   cout << "1 ";
   DFS(1);
   cout << endl;

   return 0;
}