#include <bits/stdc++.h>

using namespace std;

#define MAXN 100100
#define dist first
#define nodo1 second.first
#define nodo2 second.second

typedef pair <int, pair <int, int> > pipii;

int dad[MAXN], weight[MAXN], amount[MAXN];

int find(int x){
   if(dad[x]==x){
      return x;
   }
   return dad[x]=find(dad[x]);
}


void join(int x, int y){
   x = find(x);
   y = find(y);

   if(x==y) return;
   
   //analyze weight array to choice the best dad 
   //and upgrade amount array
   if(weight[x]>weight[y]){
       swap(x,y);
   }
   dad[x]=y;
   amount[y]+=amount[x];

   if(weight[x]==weight[y]){
       weight[y]++;
   }

}

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL); cout.tie(NULL);

   int nodos, edge;
   cin >> nodos >> edge;
   vector <pipii> mst(edge+1);

   //initialize arrays
   for(int i=1; i<=nodos; i++){
      dad[i]=i;
      weight[i]=0;
      amount[i]=1;
   }

    //Minimum Spanning Tree
    //initialize graph information in an array
   for(int i=1; i<=edge; i++){
       cin >> mst[i].nodo1 >> mst[i].nodo2 >> mst[i].dist;
   }

    //sorting by weights
   sort(mst.begin()+1, mst.end());

   int total=0;

    //create MST and calculate minimum sum
   for(int i=1; i<=edge; i++){
       if(find(mst[i].nodo1) != find(mst[i].nodo2)){
           join(mst[i].nodo1, mst[i].nodo2);
           total+=mst[i].dist;
       }
   }

   cout << total << endl; 

   return 0;
}