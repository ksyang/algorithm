#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<bool> > node;

int N, M, K;

void dfs(int i, int j){
	node[i][j] = false;
	if(i<(N-1)){
		if (node[i+1][j]) dfs(i+1, j);
	}
	if(i>0){
		if(node[i-1][j]) dfs(i-1, j);
	}
	if(j<(M-1)){
	 	if(node[i][j+1]) dfs(i, j+1);
	}
	if(j>0){
		if (node[i][j-1]) dfs(i, j-1);
	}
	return;
}

int main(void)
{
	int n,m;
	int test;
	int count=0;

	cin >> test;
	
	while(test--){
	
	count =0;
	cin >> N >> M >> K;
	
	node.resize(N);
	for(int i=0;i<N;i++){
		node[i].resize(M);
	}

	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			node[i][j] = false;

	for(int i=0;i<K;i++){
		cin >> n >> m;
		node[n][m] = true;
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(node[i][j]){
			 	dfs(i, j);
				count++;
			}
		}
	}

	cout << count << '\n';
	}
	return 0;
}
