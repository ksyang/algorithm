#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Graph{
private: 
	int N;
	vector< vector<int> > adj;
	vector<bool> visited;

	void dfs(int dep){
		cout << dep << "has been visited!" << endl;
		visited[dep] = true;
		for(int i=0;i<adj[dep].size();i++){
			int g = adj[dep][i];
			if(visited[g] == false){
				dfs(g);
			}
		}
		return;
	}

public:
	Graph(): N(0){}

	Graph(int n): N(n){
		adj.resize(N);
		visited.resize(N);
		for(int i=0;i<N;i++){
			visited[i] = false;
		}
	}

	void addEdge(int i, int j){
		adj[i].push_back(j);
		adj[j].push_back(i);
	}

	void sortList(){
		for(int i=0;i<N;i++){
			sort(adj[i].begin(), adj[i].end());
		}
	}

	void dfs(){
		dfs(0);
	}
};


int main(){
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
	G.dfs();
}
