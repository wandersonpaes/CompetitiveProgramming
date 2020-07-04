#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int linha, coluna, numIntrucoes, x, y, figurinha, xAux, yAux;
	string matriz[110], instrucoes;

	cin >> linha >> coluna >> numIntrucoes;
	while(linha != 0 || coluna != 0 || numIntrucoes != 0){
		for(int i=0; i<linha; i++){
			cin >> matriz[i];
		}
		cin >> instrucoes;

		for(x=0; x<linha; x++){
			for(y=0; y<coluna; y++){
				if(matriz[x][y] == 'N' || matriz[x][y] == 'S' || matriz[x][y] == 'L' || matriz[x][y] == 'O'){
					xAux = x;
					yAux = y;
				}
			}
		}
		x = xAux;
		y = yAux;

		figurinha=0;
		for(int i=0; i<instrucoes.size(); i++){
			if(instrucoes[i] == 'D'){
				if(matriz[x][y] == 'N') matriz[x][y] = 'L';
				else if(matriz[x][y] == 'L') matriz[x][y] = 'S';
				else if(matriz[x][y] == 'S') matriz[x][y] = 'O';
				else matriz[x][y] = 'N';

			}else if(instrucoes[i] == 'E'){
				if(matriz[x][y] == 'N') matriz[x][y] = 'O';
				else if(matriz[x][y] == 'L') matriz[x][y] = 'N';
				else if(matriz[x][y] == 'S') matriz[x][y] = 'L';
				else matriz[x][y] = 'S';

			}else{
				if(matriz[x][y] == 'N'){
					if(x-1 >= 0){
						matriz[x][y] = '.';
						x--;
						if(matriz[x][y] == '*'){
							figurinha++;
						}else if(matriz[x][y] == '#'){
							x++;
						}
						matriz[x][y] = 'N';
					}
				}else if(matriz[x][y] == 'L'){
					if(y+1 < coluna){
						matriz[x][y] = '.';
						y++;
						if(matriz[x][y] == '*'){
							figurinha++;
						}else if(matriz[x][y] == '#'){
							y--;
						}
						matriz[x][y] = 'L';
					}
				}else if(matriz[x][y] == 'S'){
					if(x+1 < linha){
						matriz[x][y] = '.';
						x++;
						if(matriz[x][y] == '*'){
							figurinha++;
						}else if(matriz[x][y] == '#'){
							x--;
						}
						matriz[x][y] = 'S';
					}
				}else{
					if(y-1 >= 0){
						matriz[x][y] = '.';
						y--;
						if(matriz[x][y] == '*'){
							figurinha++;
						}else if(matriz[x][y] == '#'){
							y++;
						}
						matriz[x][y] = 'O';
					}
				}
			}

		}

		cout << figurinha << endl;

		cin >> linha >> coluna >> numIntrucoes;
	}

	return 0;
}