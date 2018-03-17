#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

vector< vector<bool> > adj;
list<int> visited;
int N;
int homeCount = 0;
int cnt = 0;

void dfs(int x, int y){
	homeCount++;
	adj[x][y] = false;
	if(x>0 && adj[x-1][y])
		dfs(x-1, y);
	if(x<(N-1) && adj[x+1][y])
		dfs(x+1, y);
	if(y>0 && adj[x][y-1])
		dfs(x, y-1);
	if(y<(N-1) && adj[x][y+1])
		dfs(x, y+1);
	return;
}

void findDange(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(adj[i][j]){
				homeCount = 0;
				dfs(i, j);
				cnt++;
				visited.push_front(homeCount);
			}
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
	
	char block;

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> block;
			adj[i][j] = block - '0';
		}
	}
	
	findDange();
	cout << cnt << '\n';

	list<int>::iterator tmp;

	visited.sort();
	for(tmp=visited.begin();tmp!=visited.end();tmp++){
		cout << *tmp << '\n';
	}
	return 0;
}
