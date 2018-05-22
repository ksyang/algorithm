#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

vector< vector<int> > screen;

bool isBoxed(int x, int y, int interval){
	bool tmp;
	tmp = screen[x][y];
	for(int i=x; i<x+interval; i++){
		for(int j=y; j<y+interval; j++){
			if(tmp != screen[i][j]) return false;
		}	
	}
	return true;
}

string quardTree(int x, int y, int interval){
	string output="(";
	if(isBoxed(x, y, interval)){
		output.append(to_string(screen[x][y]));
	} else {
		output.append(quardTree(x, y, interval/2));
	}
	if(isBoxed(x, y+interval, interval)){
		output.append(to_string(screen[x][y+interval]));
	} else {
		output.append(quardTree(x, y+interval, interval/2));
	}
	if(isBoxed(x+interval, y, interval)){
		output.append(to_string(screen[x+interval][y]));
	} else {
		output.append(quardTree(x+interval, y, interval/2));
	}
	if(isBoxed(x+interval, y+interval, interval)){
		output.append(to_string(screen[x+interval][y+interval]));
	} else {
		output.append(quardTree(x+interval, y+interval, interval/2));
	}
	return output.append(")");
}

int main(void){
	int N;

	cin >> N;
	screen.resize(N);
	for(int i=0; i<N; i++){
		screen[i].resize(N);
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%1d", &screen[i][j]);
		}
	}
	if(isBoxed(0, 0, N))
		cout << screen[0][0] << '\n';
	else
		cout << quardTree(0, 0, N/2) << '\n';
	return 0;
}
