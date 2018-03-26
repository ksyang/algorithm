#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

bool visited[301][301];
queue<int> xCoor;
queue<int> yCoor;

int l;
int level;
int sourceX, sourceY;
int destX, destY;

void bfs(){
	int sizeQ;
	int x, y;

	xCoor.push(sourceX);
	yCoor.push(sourceY);

	while(!xCoor.empty()){
		sizeQ = xCoor.size();
		level++;
		for(int i=0;i<sizeQ;i++){
			x = xCoor.front();
			y = yCoor.front();
			
			if(x == destX && y == destY)
				return;

			xCoor.pop();
			yCoor.pop();

			if(x+2<=(l-1) && y+1<=(l-1) && !visited[x+2][y+1]){
				xCoor.push(x+2);
				yCoor.push(y+1);
				visited[x+2][y+1] = 1;
			}

			if(x+1<=(l-1) && y+2<=(l-1) && !visited[x+1][y+2]){
				xCoor.push(x+1);
				yCoor.push(y+2);
				visited[x+1][y+2] = 1;
			}

			if(x-1>=0 && y+2<=(l-1) && !visited[x-1][y+2]){
				xCoor.push(x-1);
				yCoor.push(y+2);
				visited[x-1][y+2] = 1;
			}

			if(x-2>=0 && y+1<=(l-1) && !visited[x-2][y+1]){
				xCoor.push(x-2);
				yCoor.push(y+1);
				visited[x-2][y+1] = 1;
			}


			if(x-2>=0 && y-1>=0 && !visited[x-2][y-1]){
				xCoor.push(x-2);
				yCoor.push(y-1);
				visited[x-2][y-1] = 1;
			}

			if(x-1>=0 && y-2>=0 && !visited[x-1][y-2]){
				xCoor.push(x-1);
				yCoor.push(y-2);
				visited[x-1][y-2] = 1;
			}

			if(x+1<=(l-1) && y-2>=0 && !visited[x+1][y-2]){
				xCoor.push(x+1);
				yCoor.push(y-2);
				visited[x+1][y-2] = 1;
			}

			if(x+2<=(l-1) && y-1>=0 && !visited[x+2][y-1]){
				xCoor.push(x+2);
				yCoor.push(y-1);
				visited[x+2][y-1] = 1;
			}
		}
	}
}

int main(void)
{
	int t;

	cin >> t;

	while(t--){
		level = 0;
		while(!xCoor.empty()) xCoor.pop();
		while(!yCoor.empty()) yCoor.pop();
		cin >> l;
		
		for(int i=0;i<l;i++){
			for(int j=0;j<l;j++){
				visited[i][j] = 0;
			}
		}
		
		cin >> sourceX >> sourceY;
		cin >> destX >> destY;	
	
		bfs();

		cout << level - 1 << '\n';
	}
	return 0;
}
