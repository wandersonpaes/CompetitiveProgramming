#include <bits/stdc++.h>

using namespace std;
typedef pair <int, int> pii;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int B,N;
    cin >> B >> N;

    while(B != 0 || N != 0){
        vector <pii> bank;
        int money;

        for(int i=0; i<B; i++){
            cin >> money;

            bank.push_back(pii(i+1, money));
        }

        int devedor, credor, valor;
        for(int i=0; i<N; i++){
            cin >> devedor >> credor >> valor;

            bank[devedor-1].second -= valor;
            bank[credor-1].second += valor;
        }

        char res='S';

        for(auto bb : bank){
            if(bb.second < 0){
                res = 'N';
                break;
            }
        }

        cout << res << endl;

        cin >> B >> N;
    }

    return 0;
}