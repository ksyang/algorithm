#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class Graph{
	private:
		int N;
		vector< vector<int> > adj;

	public:
		Graph(): N(0){}

		Graph(int n): N(n){
			adj.resize(N);
		}

		void addEdge(int u, int v){
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		
		void sortList(){
			for(int i=0;i<N;i++){
				sort(adj[i].begin(), adj[i].end());
			}
		}

		void bfs(){
			vector<int> visited(N, false);
			queue<int> Q;
			visited[0] = true;
			Q.push(0);
			
			int level = 0;
			int curr;
			while(!Q.empty()){
				level++;
				cout << "level : " << level << '\n';

				int sizeQ = Q.size();
				for(int i=0;i<sizeQ;i++){
					curr = Q.front();
					Q.pop();
	
					cout << "node : " << curr << '\n';
					for(int i=0;i<adj[curr].size();i++){
						if(!visited[adj[curr][i]]){
							visited[adj[curr][i]] = true;
							Q.push(adj[curr][i]);
						}
					}
				}
			}
		}
};

int main()
{
	Graph G(9);
	G.addEdge(0, 1); 
	G.addEdge(0, 2);
	G.addEdge(1, 3);
	G.addEdge(1, 5);
	G.addEdge(3, 4);
	G.addEdge(4, 5);
	G.addEdge(2, 6);
	G.addEdge(2, 8);
	G.addEdge(6, 7);
	G.addEdge(6, 8);
	G.sortList();
	G.bfs();
}
