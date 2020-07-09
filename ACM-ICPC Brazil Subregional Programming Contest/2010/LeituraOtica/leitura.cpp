#include <bits/stdc++.h>

using namespace std;

int main(){
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);

   unordered_map <int, char> dic;
   dic.insert(make_pair(0,'A'));
   dic.insert(make_pair(1,'B'));
   dic.insert(make_pair(2,'C'));
   dic.insert(make_pair(3,'D'));
   dic.insert(make_pair(4,'E'));

   int N, num;
   cin >> N;
   while(N!=0){
      for(int i=0; i<N; i++){
         unordered_set <char> resp;
         for(int j=0; j<5; j++){
            cin >> num;

            if(num <=127){
               resp.insert(dic[j]);
            }
         }
         if(resp.size() == 1){
            unordered_set <char>::iterator it=resp.begin();
            cout << *it << endl;
         }else{
            cout << "*\n";
         }
      }

      cin >> N;
   }

   return 0;
}