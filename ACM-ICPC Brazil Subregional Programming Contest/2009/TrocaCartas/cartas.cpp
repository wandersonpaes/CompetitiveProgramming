#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;
    
    while(a!=0 || b!=0){
        set <int> alice;
        set <int> beatriz;

        int num;
        for(int i=0; i<a; i++){
            cin >> num;
            alice.insert(num);
        }

        for(int i=0; i<b; i++){
            cin >> num;
            beatriz.insert(num);
        }

        int tamA = alice.size();
        int tamB = beatriz.size();

        if(tamA <= tamB){
            for(auto a : alice){
                beatriz.insert(a);
            }

            cout << beatriz.size()-tamB << endl;
        }else{
            for(auto b : beatriz){
                alice.insert(b);
            }

            cout << alice.size()-tamA << endl;
        }

        cin >> a >> b;
    }

    return 0;
}