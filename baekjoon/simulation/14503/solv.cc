#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

#define U 0
#define R 1
#define D 2
#define L 3

#define DIRTY 0
#define WALL 1
#define CLEAN 2

using namespace std;

int map[51][51];
int N, M;
int r, c, d;
int total=0;

void ror(){
	if(d==U) d=L;
	else if(d==R) d=U;
	else if(d==D) d=R;
	else if(d==L) d=D;
}

pair<int, int> get_next_pos(){
	pair<int, int> pos(r, c);
	if(d==U) pos.first=r-1;
	else if(d==R) pos.second=c+1;
	else if(d==D) pos.first=r+1;
	else if(d==L) pos.second=c-1;
	return pos;
}

pair<int, int> get_back_pos(){
	pair<int, int> pos(r, c);
	if(d==U) pos.first=r+1;
	else if(d==R) pos.second=c-1;
	else if(d==D) pos.first=r-1;
	else if(d==L) pos.second=c+1;
	return pos;
}

void print_map(){
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cout << map[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void go_clean(){
	int cnt=0;
	while(true){
		if(map[r][c]==0){
			total++;
			map[r][c]=2;
			//print_map();
		}		//현재 위치가 더러우면 청소하고
		ror();
		cnt++;
		pair<int, int> next_pos = get_next_pos();
		if(map[next_pos.first][next_pos.second]==0){
			r=next_pos.first;
			c=next_pos.second;
			cnt=0;
			continue;
		}
		if(cnt==4){
			pair<int, int> back_pos = get_back_pos();
			if(map[back_pos.first][back_pos.second]==1) break;
			r=back_pos.first;
			c=back_pos.second;
			cnt=0;
		}
	}
}

int main(void){
	cin >> N >> M;
	cin >> r >> c >> d;
	for(int i=0; i<N; i++){
		for(int j=0; j<M; j++){
			cin >> map[i][j];
		}
	}

	go_clean();
	
	//print_map();

	cout << total;
	return 0;
}
