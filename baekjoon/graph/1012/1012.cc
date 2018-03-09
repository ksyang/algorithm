#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector< vector<bool> > node;
	int N, M, K;
	int n,m;

	cin >> N >> M >> K;
	
	node.resize(N);
	for(int i=0;i<N;i++){
		node[i].resize(M);
	}

	for(int i=0;i<K;i++){
		cin >> n >> m;
		node[n][m] = true;
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cout << node[N][M];
		}
		cout << "\n";
	}
	return 0;
}
