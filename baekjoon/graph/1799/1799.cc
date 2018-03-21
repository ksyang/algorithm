#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int cnt = 0;
int maxCnt = 0;

vector< vector<int> > adj;

void setDisable(int x, int y, int n){
	cnt += n;
	adj[x][y] += n;
	for(int i = 1 ; i < N - x ; i++){
		if(y + i < N)
			adj[x + i][y + i] += n;
		if(y - i >= 0)
			adj[x + i][y - i] += n;
	}
}

void printBishop(int x, int y){
	//if(x == N){
	//	maxCnt = max(cnt, maxCnt);
	//	return;
	//}
	int tmp = y;
	for(int i=x;i<N;i++){
		for(int j=tmp;j<N;j++){
			if(!adj[i][j]){
				setDisable(i, j, 1);
				if(j + 1 == N) printBishop(i + 1, 0);
				else printBishop(i, j + 1);
				maxCnt = max(cnt, maxCnt);
				setDisable(i, j, -1);
			}
		}
		tmp = 0;
	}
	//cout << cnt << '\n';
}

int main(void)
{
	cin >> N;
	adj.resize(N);
	for(int i=0;i<N;i++){
		adj[i].resize(N);
	}

	int board;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> board;
			adj[i][j] = board;
		}
	}

	printBishop(0, 0);
	cout << maxCnt;
	return 0;
}
