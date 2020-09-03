#include <bits/stdc++.h>

using namespace std;

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int vertice, edge;
   cin >> vertice >> edge;
   vector < vector <int> > graph(vertice+1);

   //initializing a graph
   for(int i=0; i<edge; i++){
      int from, to;
      cin >> from >> to;

      graph[from].push_back(to);
      graph[to].push_back(from);
   }

   //breadth-firts search
   int source=1;
   vector <bool> processed(vertice+1);
   queue <int> queueGraph;
   queueGraph.push(source);
   processed[source]=true;

   cout << source << " ";
   while(!queueGraph.empty()){
      int dad = queueGraph.front();
      queueGraph.pop();

      for(auto son : graph[dad]){

         if(!processed[son]){
            cout << son << " ";
            queueGraph.push(son);
            processed[son]=true;
         }
      }
   }
   cout << endl;

   return 0;
}