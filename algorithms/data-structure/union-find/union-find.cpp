#include <bits/stdc++.h>

#define MAXN 100100

using namespace std;

int dad[MAXN], dist[MAXN], amount[MAXN];

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
   
   //analyze distance array to choice the best dad 
   //and upgrade amount array
   if(dist[x]>dist[y]){
       swap(x,y);
   }
   dad[x]=y;
   amount[y]+=amount[x];

   if(dist[x]==dist[y]){
       dist[y]++;
   }

}

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int n, k; //nodes and operation number
   cin >> n >> k;

   //initialize arrays
   for(int i=1; i<=n; i++){
      dad[i]=i;
      dist[i]=0;
      amount[i]=1;
   }

   for(int i=0; i<k; i++){
      char op; //operation type
      int a, b; //nodes
      cin >> op >> a >> b;

      //Q = query and F = fusion
      if(op == 'Q'){
         (find(a) == find(b)) ? cout << "Y\n" : cout << "N\n";
      }else{
         join(a,b);
      }
   }

   return 0;
}