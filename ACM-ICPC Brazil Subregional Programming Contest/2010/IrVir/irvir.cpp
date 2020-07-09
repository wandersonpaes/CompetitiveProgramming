#include <bits/stdc++.h>

using namespace std;

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, m;
   cin >> n >> m;

   while(n!=0 || m!=0){
      vector < vector <int> > graph(n+1);
      bool resp=true;

      //initializing a graph
      for(int i=0; i<m; i++){
         int from, to, type;
         cin >> from >> to >> type;

         if(type==1){
            graph[from].push_back(to);
         }else{
            graph[from].push_back(to);
            graph[to].push_back(from);
         }         
      }
      
      //breadth-first search in all node
      for(int node=1; node<=n; node++){
         
         vector <bool> processed(n+1);
         queue <int> queueGraph;
         unordered_set <int> no; //visited node
         queueGraph.push(node);

         while(!queueGraph.empty()){
            int dad = queueGraph.front();
            queueGraph.pop();
            processed[dad]=true;
            no.insert(dad);

            for(auto son : graph[dad]){

               if(!processed[son]){
                  processed[son]=true;
                  queueGraph.push(son);
                  no.insert(son);
               }
            }
         }

         //if not all of the nodes were visited, 
         //the connectivity criterion was not met
         if(no.size()<n){
            resp=false;
            break;
         }
      }

      if(resp){
         cout << "1\n";
      }else{
         cout << "0\n";
      }

      cin >> n >> m;
   }

   return 0;
}