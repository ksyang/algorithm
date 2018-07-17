#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Graph{
	private:
		int N;
		
		vector < vector<int> > adj;

	public:
		Graph(): N(0){}

		Graph(int num): N(num){
			adj.resize(N);
		}

		void addEdge(int i, int j){
			adj[j].push_back(i);
		}

		void sortList(){
			for(int i=0; i<N; i++){
				sort(adj[i].begin(), adj[i].end());
			}
		}
		
		void findHack(){
				
		}
};

int main(void)
{
	int N, M;
	int n, m;
	cin >> N >> M;
	Graph G(N);
	for(int i=0; i<M; i++){
		cin >> n >> m;
		G.addEdge(n, m);
	}
	G.sortList();
	G.findHack();
	return 0;
}
