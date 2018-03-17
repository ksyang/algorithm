#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int cnt = 0;

vector< vector<int> > adj;

void setDisable(int x, int y, int n){
	for(int i = 1;i<N - x;i++){
		if(y + i < N)
			adj[x + i][y + i] += n;
		if(y - i >= 0)
			adj[x + i][y - i] += n;
	}
}

void printBishop(int y){
	if(y == N-1){
		for(int i=0;i<N;i++){
			if(adj[i][y] == 0)
				cnt++;
		}
		return;
	}

	for(int i=0;i<N;i++){
		if(adj[i][y] == 0){
			setDisable(i, y, 1);
			printBishop(y+1);
			setDisable(i, y, -1);
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
	
	char board;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> board;
			adj[i][j] = board - '0';
		}
	}

	printBishop(0);
	cout << cnt;
	return 0;
}
