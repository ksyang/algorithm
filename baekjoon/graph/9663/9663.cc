#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int cnt = 0;

vector< vector<int> > adj;

void setDisable(int x, int y){
	for(int i=0;i<N;i++){
		adj[x][i]++;
		adj[i][y]++;
	}
	adj[x][y]--;

	for(int i=1;i<N;i++){
		if((x+i)<N && (y+i)<N)
			adj[x+i][y+i]++;
		if((x-i)>=0 && (y-i)>=0)
			adj[x-i][y-i]++;
		if((x+i)<N && (y-i)>=0)
			adj[x+i][y-i]++;
		if((x-i)>=0 && (y+i)<N)
			adj[x-i][y+i]++;
	}
}

void setEnable(int x, int y){
	for(int i=0;i<N;i++){
		adj[x][i]--;
		adj[i][y]--;
	}
	adj[x][y]++;

	for(int i=1;i<N;i++){
		if((x+i)<N && (y+i)<N)
			adj[x+i][y+i]--;
		if((x-i)>=0 && (y-i)>=0)
			adj[x-i][y-i]--;
		if((x+i)<N && (y-i)>=0)
			adj[x+i][y-i]--;
		if((x-i)>=0 && (y+i)<N)
			adj[x-i][y+i]--;
	}
}

void printQueen(int y){
	if(y == N-1){
		for(int i=0;i<N;i++){
			if(adj[i][y] == 0)
				cnt++;
		}
		return;
	}

	for(int i=0;i<N;i++){
		if(adj[i][y] == 0){
			setDisable(i, y);
			printQueen(y+1);
			setEnable(i, y);
		}
	}
}

int main(void)
{
	cin >> N;
	adj.resize(N);
	for(int i=0;i<N;i++){
		adj[i].resize(N);
	}

	printQueen(0);
	cout << cnt;
	return 0;
}
