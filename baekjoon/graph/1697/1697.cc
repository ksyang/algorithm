#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

queue<int> Q;
vector<bool> visited;
int N, K;
int level = 0;

void bfs(){
	int prev;
	Q.push(N);
	while(!Q.empty()){
		int Qsize = Q.size();
		
		for(int i=0;i<Qsize;i++){
			prev = Q.front();
			Q.pop();
			
			visited[prev] = true;
			if(prev == K) return;
			
			if((prev * 2) < 200000 && !visited[prev * 2])
				Q.push(prev * 2);
			if((prev  + 1) < 200000 && !visited[prev + 1])
				Q.push(prev + 1);
			if(prev > 0 && !visited[prev - 1])
				Q.push(prev - 1);
		}
		level++;
	}
}

int main(void)
{
	cin >> N >> K;
	visited.resize(300000);

	bfs();

	cout << level;
	return 0;
}
