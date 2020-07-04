#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> pii;

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int vertices, edge, way, sourceK;
   cin >> vertices >> edge >> way >> sourceK;

   while(vertices!=0 || edge!=0 || way!=0 || sourceK!=0){
      vector < vector <pii> > graph(vertices);

      for(int i=0; i<edge; i++){
         int from, to, price;
         cin >> from >> to >> price;

         graph[from].push_back(pii(price, to));
         graph[to].push_back(pii(price, from));
      }

      vector <int> toll(vertices,10e8);
      toll[sourceK]=0;
      vector <bool> processed(vertices);
      priority_queue <pii, vector<pii>, greater<pii> > queueGraph;
      queueGraph.push(pii(toll[sourceK],sourceK));

      while(!queueGraph.empty()){
         int dad = queueGraph.top().second;
         queueGraph.pop();
         processed[dad]=true;

         for(auto son : graph[dad]){
            int price = son.first;
            int node = son.second;

            if(dad < way-1 && node != dad+1){
               continue;
            }

            if(toll[node] > toll[dad]+price){
               toll[node] = toll[dad]+price;

               if(!processed[node]){
                  queueGraph.push(pii(toll[node], node));
               }
            }
         }
      }

      cout << toll[way-1] << endl;

      cin >> vertices >> edge >> way >> sourceK;
   }

   return 0;
}