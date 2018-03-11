#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph{
	private:
		int N, M;
		int countEdge;
		int maxTrash;
		vector< vector<bool> > adj;
		
		void dfs(int i, int j){
			adj[i][j] = false;
			countEdge++;
		
			if(i<(N-1)){
				if (adj[i+1][j]) dfs(i+1,j);
			}
			if(i>0){
				if(adj[i-1][j]) dfs(i-1, j);
			}
			if(j<(M-1)){
				if(adj[i][j+1]) dfs(i, j+1);
			}
			if(j>0){
				if(adj[i][j-1]) dfs(i, j-1);
			}
			return;
		}

	public:
		Graph(): N(0), M(0){}

		Graph(int n, int m): N(n), M(m){
			adj.resize(N);
			for(int i=0;i<N;i++){
				adj[i].resize(M);
			}

			for(int i=0;i<N;i++){
				for(int j=0;j<M;j++){
					adj[i][j]=false;
				}
			}
		}

		void addEdge(int u, int v){
			adj[u-1][v-1] = true;
		}

		void printEdge(){
			for(int i=0;i<N;i++){
				for(int j=0;j<M;j++){
					cout << adj[i][j];
				}
				cout << '\n';
			}
		}

		void printLargeTrash(){
			maxTrash = 0;
			for(int i=0;i<N;i++){
				for(int j=0;j<M;j++){
					if(adj[i][j]){
						countEdge = 0;
						dfs(i, j);
						maxTrash = max(countEdge, maxTrash);
					}
				}
			}
			cout << maxTrash;
		}
};


int main(void)
{
	int N, M, K;
	int n, m;

	cin >> N >> M >> K;

	Graph G(N, M);
	for(int i=0;i<K;i++){
		cin >> n >> m;
		G.addEdge(n, m);
	}
	G.printLargeTrash();
	return 0;
}
