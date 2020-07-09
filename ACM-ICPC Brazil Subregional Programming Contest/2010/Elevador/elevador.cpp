#include <bits/stdc++.h>

using namespace std;

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   int l, c, r1, r2;

   while(cin >> l >> c >> r1 >> r2){
      if(l+c+r1+r2 == 0) break;

      if(min(l,c) < max(r1*2,r2*2)){
         cout << "N\n";
         continue;
      }

      (sqrt(pow(l-r1-r2,2)+pow(c-r1-r2,2)) >= r1+r2) ? cout << "S\n" : cout << "N\n";
   }

   return 0;
}