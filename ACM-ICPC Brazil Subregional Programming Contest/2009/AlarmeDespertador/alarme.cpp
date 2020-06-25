#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h1, m1, h2, m2;
    cin >> h1 >> m1 >> h2 >> m2;

    while(h1!=0 || m1!=0 || h2!=0 || m2!=0){
        int t1 = (h1*60)+m1;
        int t2 = (h2*60)+m2;

        if(t1<t2){
            cout << (t2-t1) << endl;
        }else{
            cout << (1440+(t2-t1)) << endl;
        }

        cin >> h1 >> m1 >> h2 >> m2;
    }

    return 0;
}