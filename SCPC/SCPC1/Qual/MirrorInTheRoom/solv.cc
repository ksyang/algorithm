#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>

using namespace std;

int main(void){
	int T;

	cin >> T;
	for(int testCase = 1; testCase <= T; testCase++){
		int N;
		vector< vector<int> > room;
		vector< vector<int> > visited;

		cin >> N;

		room.resize(N);
		visited.resize(N);
		for(int i=0; i<N; i++){
			room[i].resize(N);
			visited[i].resize(N);
		}

		for(int i=0; i<N; i++){
			for(int j=0; j<N; j++){
				scanf("%1d", &room[i][j]);
			}
		}
		
		int cntMirror = 0;
		int roomPos = 4;
		int curX = 0;
		int curY = 0;
		while(1){
			if(curX < 0 || curY < 0 || curX >= N || curY >= N) break;
			
			if(roomPos == 1){
				if(room[curX][curY] == 0){
					curX++;
				}
				else if(room[curX][curY] == 1){
					if(visited[curX][curY] != 1){
						visited[curX][curY] = 1;
						cntMirror++;
					}
					roomPos = 2;
					curY--;
				}
				else if(room[curX][curY] == 2){					
					if(visited[curX][curY] != 1){
						visited[curX][curY] = 1;
						cntMirror++;
					}
					roomPos = 4;
					curY++;
				}
			} 
			else if(roomPos == 2){
				if(room[curX][curY] == 0){
					curY--;
				}
				else if(room[curX][curY] == 1){
					if(visited[curX][curY] != 1){
						visited[curX][curY] = 1;
						cntMirror++;
					}
					roomPos = 1;
					curX++;
				}
				else if(room[curX][curY] == 2){
					if(visited[curX][curY] != 1){
						visited[curX][curY] = 1;
						cntMirror++;
					}
					roomPos = 3;
					curX--;
				}
			}
			else if(roomPos == 3){
				if(room[curX][curY] == 0){
					curX--;
				}
				else if(room[curX][curY] == 1){
					if(visited[curX][curY] != 1){
						visited[curX][curY] = 1;
						cntMirror++;
					}
					roomPos = 4;
					curY++;
				}
				else if(room[curX][curY] == 2){
					if(visited[curX][curY] != 1){
						visited[curX][curY] = 1;
						cntMirror++;
					}
					roomPos = 2;
					curY--;
				}
			}
			else if(roomPos == 4){
				if(room[curX][curY] == 0){
					curY++;
				}
				else if(room[curX][curY] == 1){
					if(visited[curX][curY] != 1){
						visited[curX][curY] = 1;
						cntMirror++;
					}
					roomPos = 3;
					curX--;
				}
				else if(room[curX][curY] == 2){
					if(visited[curX][curY] != 1){
						visited[curX][curY] = 1;
						cntMirror++;
					}
					roomPos = 1;
					curX++;
				}
			}
		}

		cout << "Case #" << testCase << '\n';
		cout << cntMirror << '\n';
	}
	return 0;
}
