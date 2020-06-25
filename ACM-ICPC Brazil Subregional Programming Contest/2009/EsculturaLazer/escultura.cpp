#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int A, C, laser[10010], cont=0;

	cin >> A >> C;

	while(A != 0 && C != 0){
		for(int i=0; i<C; i++){
			cin >> laser[i];
		}

		for(int i=0; i<C; i++){
			if(i == 0){
				cont = A - laser[i];
			}else{
				if(laser[i] < laser[i-1]){
					cont = cont + (laser[i-1] - laser[i]);
				}
			}
		}

		cout << cont << endl;

		cin >> A >> C;
	}
	
	return 0;
}