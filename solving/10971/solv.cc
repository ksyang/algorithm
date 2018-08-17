#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int > > cost;
vector<bool> visited;

int getMinPath(int s){
	visited[s] = true;
	int minPath = 0;
	int flag = 0;
	for(int i=0; i<N; i++){
		if(visited[i] == true || cost[s][i] == 0) continue;
		int pathCnt = getMinPath(i);
		//if(pathCnt == -100) continue;
		if(flag == 1){
			minPath = min(pathCnt + cost[s][i], minPath);
		}
		else {
			minPath = pathCnt + cost[s][i];
			flag = 1;
		}
	}

	int fullVisitFlag = 1;
	for(int i=0; i<N; i++){
		if(visited[i] == false) fullVisitFlag = 0;
	}

	visited[s] = false;

	if(fullVisitFlag == 0)
		return minPath;
	else{
		if(cost[s][0] == 0) return 210000000;
		else return cost[s][0];
	}
}

int main(void){
	cin >> N;

	cost.resize(N);
	visited.resize(N);
	for(int i=0; i<N; i++){
		cost[i].resize(N);
		visited[i] = false;
	}
	
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin >> cost[i][j];
		}
	}
	cout << getMinPath(0);
	return 0;
}
