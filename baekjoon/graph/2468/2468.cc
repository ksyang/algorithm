#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector< vector<int> > adj;
vector< vector<bool> > saftyArea;
int N;

int find_safty(int h){
	for(int i=0; i<N; i++){
		
	}
}

int main(void)
{
	int maxH = 0;
	int maxS = 0;

	cin >> N;
	adj.resize(N);
	saftyArea.resize(N);
	for(int i=0;i<N;i++){
		adj[i].resize(N);
		saftyArea.resize(N);
	}
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> adj[i][j];
			maxH = max(maxH, adj[i][j]);
		}
	}
	
	
	for(int i=0; i<maxH; i++){
		for(int j=0; j<N; j++){
			fill(saftyArea.begin(), saftyArea.end(), false);
		}
		maxS = max(maxS, find_safty(i));
	}
	
	cout << maxS;
	return 0;
}
