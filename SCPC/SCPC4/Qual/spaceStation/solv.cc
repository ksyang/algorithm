#include <iostream>
#include <list>
#include <algorithm>
#include <stack>

using namespace std;

list<int> adj[200002];
stack<int> twoLegNode;

class Graph{
	private:
		int N;
		int adjCnt;

	public:
		Graph(): N(0){}

		Graph(int n): N(n){
			adjCnt = N;
		}

		void addEdge(int u, int v){
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int countEdge(int n){
			return adj[n].size();
		}
		
		int countNode(){
			return adjCnt;
		}

		void getTwoLegNode(){
			for(int i=1; i<=adjCnt; i++){
				if(adj[i].size() == 2) twoLegNode.push(i);
			}
		}

		bool checkCanRemove(int n){
			twoLegNode.pop();
			if(countEdge(n) != 2)
				return 0;
			int rmEdge1 = adj[n].front();
			int rmEdge2 = adj[n].back();
			int cmFlag = 0;
			
			list<int>::iterator iter;
			for(iter=adj[rmEdge1].begin(); iter!=adj[rmEdge1].end(); iter++){
				if(*iter == rmEdge2)
					cmFlag = 1;
			}
			if(cmFlag == 0)
				return 0;
			
			adj[rmEdge1].remove(n);
			if(adj[rmEdge1].size() == 2)
				twoLegNode.push(rmEdge1);
			adj[rmEdge2].remove(n);
			if(adj[rmEdge2].size() == 2)
				twoLegNode.push(rmEdge2);
			adjCnt--;
			return 0;
		}
};

int main(void){
	int T, caseCnt = 0;

	cin >> T;
	while(T--){
		for(int i=0; i<200001; i++){
			adj[i].clear();
		}
		while(!twoLegNode.empty()) twoLegNode.pop();
		
		caseCnt++;	
		
		int nodeNum, edgeNum;
		
		cin >> nodeNum;
		cin >> edgeNum;

		Graph G(nodeNum);
		
		for(int i=0; i<edgeNum; i++){
			int edge1, edge2;
			cin >> edge1;
			cin >> edge2;
			G.addEdge(edge1, edge2);
		}
		
		G.getTwoLegNode();

		while(!twoLegNode.empty()){
			G.checkCanRemove(twoLegNode.top());
		}

		cout << "Case #" << caseCnt << "\n";
		cout << G.countNode() <<"\n";
	}
	return 0;
}
