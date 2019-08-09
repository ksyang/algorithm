#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool map[101][101];

int visited = 0;

void dfs(int N, int x, int y, int px, int py){
	if(map[x][y]==1){
		if(N==0)
			visited++;
		return;
	}
	if(N==0) {
		return;
	}
	map[x][y]=1;
	if((x%2==0 && y%2==0) || (x%2==1 && y%2==1)){
		if(!(px == x+1 && py == y))
			dfs(N-1, x+1, y, x, y);
	}
	else if((x%2==1 && y%2==0) || (x%2==0 && y%2==1)){
		if(!(px == x-1 && py == y))
			dfs(N-1, x-1, y, x, y);
	}
	if(!(px == x && py == y+1))
		dfs(N-1, x, y+1, x, y);
	if(!(px == x && py == y-1))
		dfs(N-1, x, y-1, x, y);
	map[x][y]=0;
	return;
}

int main(void){
	int N;

	cin >> N;

	for(int i=0; i<101; i++){
		for(int j=0; j<101; j++){
			map[i][j]=0;
		}
	}	
	
	map[50][50] = 1;
	dfs(N, 51, 50, 50, 50);
	cout << visited;
	return 0;
}
