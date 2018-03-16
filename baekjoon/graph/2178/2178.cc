#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector< vector<bool> > adj;
vector< vector<bool> > visited;
queue<int> xCoor;
queue<int> yCoor;

int N, M;
int level=0;

void bfs(int x, int y){
	int sizeQ;

	xCoor.push(x);
	yCoor.push(y);
	visited[x][y] = 1;
	

	while(!xCoor.empty()){
		sizeQ = xCoor.size();
		level++;
		//cout << "level : " << level << '\n';

		for(int i=0;i<sizeQ;i++){
			x = xCoor.front();
			y = yCoor.front();

			xCoor.pop();
			yCoor.pop();
			//cout << x << ' ' << y <<'\n';
			if(x == N-1 && y == M-1) return;
			if(x>0 && adj[x-1][y] && !visited[x-1][y]){
				xCoor.push(x-1);
				yCoor.push(y);
				visited[x-1][y] = 1;
			}
			if(x<(N-1) && adj[x+1][y] && !visited[x+1][y]){
				xCoor.push(x+1);
				yCoor.push(y);
				visited[x+1][y] = 1;
			}
			if(y>0 && adj[x][y-1] && !visited[x][y-1]){
				xCoor.push(x);
				yCoor.push(y-1);
				visited[x][y-1] = 1;
			}
			if(y<(M-1) && adj[x][y+1] && !visited[x][y+1]){
				xCoor.push(x);
				yCoor.push(y+1);
				visited[x][y+1] = 1;
			}
		}
	}
}

int main(void)
{
	cin >> N >> M;

	adj.resize(N);
	visited.resize(N);
	for(int i=0;i<N;i++){
		adj[i].resize(M);
		visited[i].resize(M);
	}
	
	char space;

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> space;
			adj[i][j] = space -'0';
		}
	}
	
	bfs(0, 0);
	cout << level;
	return 0;
}
