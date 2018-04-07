#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector< vector<int> > map;
vector< vector<int> > dp;
int M, N;

int findmap(int x, int y){
	int path = 0;
	if(x == M-1 && y == N-1) return 1;
	if(dp[x][y] != -1)
		return dp[x][y];
	if(x > 0 && map[x-1][y] < map[x][y])
		path += findmap(x-1, y);
	if(x < M-1 && map[x+1][y] < map[x][y])
		path += findmap(x+1, y);
	if(y > 0 && map[x][y-1] < map[x][y])
		path += findmap(x, y-1);
	if(y < N-1 && map[x][y+1] < map[x][y])
		path += findmap(x, y+1);
	dp[x][y] = path;
	return dp[x][y];
}

int main(void)
{
	cin >> M >> N;
	map.resize(M);
	dp.resize(M);
	for(int i=0;i<M;i++){
		map[i].resize(N);
		dp[i].resize(N);
	}

	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			dp[i][j] = -1;
		}
	}

	for(int i=0;i<M;i++){
		for(int j=0;j<N;j++){
			cin >> map[i][j];
		}
	}

	cout << findmap(0, 0);
	return 0;
}
