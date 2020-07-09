#include <bits/stdc++.h>

using namespace std;

bool compara(pair <int, int> a, pair <int, int> b){
   if(a.first==b.first){
      return a.second<b.second;
   }else{
      return a.first>b.first;
   }
}

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int numPremio, numPilotos;
   
   while(cin >> numPremio >> numPilotos){
      if(numPremio==0 && numPilotos==0) break;

      vector < vector <int> > resultado(numPremio, vector <int> (numPilotos));
      for(int i=0; i<numPremio; i++){
         for(int j=0; j<numPilotos; j++){
            cin >> resultado[i][j];
         }
      }

      int sist;
      cin >> sist;
      for(int s=0; s<sist; s++){
         int k;
         cin >> k;
         vector < pair<int, int> > rank(numPilotos+1);
         vector <int> pontos(numPilotos+1);

         for(int p=1; p<=k; p++){
            cin >> pontos[p];            
         }

         for(int i=0; i<numPremio; i++){
            for(int j=0; j<numPilotos; j++){
               if(resultado[i][j]<=k){
                  rank[j+1].first += pontos[resultado[i][j]];
                  rank[j+1].second = j+1;
               }
            }
         }

         sort(rank.begin(), rank.end(), compara);
         cout << rank[0].second;
         for(int i=1; i<rank.size(); i++){
            if(rank[i].first==rank[0].first){
               cout << " " << rank[i].second;
            }else{
               break;
            }
         }
         cout << endl;
      }
   }

   return 0;
}