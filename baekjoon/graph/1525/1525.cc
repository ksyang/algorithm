#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

vector< vector<int> > adj;
queue<int> xCoor;
queue<int> yCoor;

int N, M;
int level=0;

void printTomato(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout << adj[i][j];
		}
		cout << '\n';
	}
}

int checkZero(){
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(adj[i][j] == 0) return 0;
		}
	}
	return 1;
}

void bfs(){
	int sizeQ;
	int x, y;

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(adj[i][j] == 1){
				xCoor.push(i);
				yCoor.push(j);
			}
		}
	}

	while(!xCoor.empty()){
		sizeQ = xCoor.size();
		level++;
		for(int i=0;i<sizeQ;i++){
			x = xCoor.front();
			y = yCoor.front();

			xCoor.pop();
			yCoor.pop();

			if(x>0 && adj[x-1][y] != -1 && adj[x-1][y] != 1){
				xCoor.push(x-1);
				yCoor.push(y);
				adj[x-1][y] = 1;
			}
			if(x<(N-1) && adj[x+1][y] != -1 && adj[x+1][y] != 1){
				xCoor.push(x+1);
				yCoor.push(y);
				adj[x+1][y] = 1;
			}
			if(y>0 && adj[x][y-1] != -1 && adj[x][y-1] != 1){
				xCoor.push(x);
				yCoor.push(y-1);
				adj[x][y-1] = 1;
			}
			if(y<(M-1) && adj[x][y+1] != -1 && adj[x][y+1] != 1){
				xCoor.push(x);
				yCoor.push(y+1);
				adj[x][y+1] = 1;
			}
		}
	}
}

int main(void)
{
	cin >> M >> N;

	adj.resize(N);

	for(int i=0;i<N;i++){
		adj[i].resize(M);
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			scanf("%d", &adj[i][j]);
		}
	}
	
	bfs();
	//printTomato();
	if(!checkZero()) cout << "-1";
	else cout << level - 1;
	return 0;
}
