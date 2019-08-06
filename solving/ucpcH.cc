#include <iostream>
#include <stdlib.h>

using namespace std;

char room[3000][3000];//[3002][3002];		//have to fix

int main(void){
	int N, M, K, Q;
	cin >> N >> M >> K >> Q;
	
	for(int i=0; i<K; i++){
		int x, y;
		char tmpp;
		cin >> x >> y >> tmpp;
		room[x][y] = tmpp;
	}
	
	for(int i=0; i<Q; i++){
		char l;
		int n;
		int x, y;
		int p_x=0, p_y=0;
		int ghost=0, gidx=0, indx=0;
		cin >> l >> n;
		if(l=='L'){
			x=n;
			y=1;
			p_y=1;
		}
		else if(l=='D'){
			x=N;
			y=n;
			p_x=-1;
		}
		else if(l=='R'){
			x=n;
			y=M;
			p_y=-1;
		}
		else if(l=='U'){
			x=1;
			y=n;
			p_x=1;
		}
		ghost = 0;
		gidx = 0;
		indx = 0;
		while(1){
			indx++;
			if(x==0 || x==N+1 || y==0 || y==M+1)
				break;
			if(room[x][y] == '!'){
				ghost++;
				gidx+=indx;
			}

			else if(room[x][y] == '/'){
				if(p_x == 1){
					p_x=0;
					p_y=-1;
				}
				else if(p_y == 1){
					p_y=0;
					p_x=-1;
				}
				else if(p_x == -1){
					p_x=0;
					p_y=1;
				}
				else if(p_y == -1){
					p_y=0;
					p_x=1;
				}
			}

			else if(room[x][y] == '\\'){
				if(p_x == 1){
					p_x=0;
					p_y=1;
				}
				else if(p_y == 1){
					p_y=0;
					p_x=1;
				}
				else if(p_x == -1){
					p_x=0;
					p_y=-1;
				}
				else if(p_y == -1){
					p_y=0;
					p_x=-1;
				}
			}
			x+=p_x;
			y+=p_y;
		}
		cout << ghost << ' ' << gidx << '\n';
	}
/*
	for(int x=1; x<=N; x++){
		for(int y=1; y<=M; y++){
			if(!(room[x][y] == '!' || room[x][y] == '/' || room[x][y] == '\\' || room[x][y] == 'h')){
				cout << "  ";
			}
			else cout << room[x][y] << " ";
		}
		cout << endl;
	}
	cout << endl;
*/

	return 0;
}
