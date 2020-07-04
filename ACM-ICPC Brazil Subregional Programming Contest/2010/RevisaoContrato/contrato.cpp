#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	char D;
	string N, saida;

	cin >> D >> N;

	while(true){
		saida = "";
		for(int i=0; i<N.size(); i++){
			if(D != N[i]){
				if(N[i] == '0' && saida == ""){
					continue;
				}else{
					saida+=N[i];
				}

			}
		}

		if(saida == "") cout << "0\n";
		else cout << saida << endl;

		cin >> D >> N;
		if(D == '0' && N == "0") break;
	}

	return 0;
}