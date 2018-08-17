#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

char rest[100][6];

int count = 0;
int N;

void swap(char *friends, int src, int dest){
	char tmp;
	tmp = friends[src];
	friends[src] = friends[dest];
	friends[dest] = tmp;
}

int checkRest(char *friends){
	for(int i=0; i<N; i++){
		char a = rest[i][0];
		char b = rest[i][2];
		int aIdx, bIdx;
		for(int idx=0; idx<8; idx++){
			if(friends[idx] == a)
				aIdx = idx;
			if(friends[idx] == b)
				bIdx = idx;
		}
		int dist = abs(aIdx - bIdx) - 1;
		if(rest[i][3] == '='){
			if(rest[i][4]-'0' != dist) return 0;
		}
		else if(rest[i][3] == '>'){
			if(rest[i][4]-'0' >= dist) return 0;
		}
		else if(rest[i][3] == '<'){
			if(rest[i][4]-'0' <= dist) return 0;
		}
	}
	return 1;
}

void getNum(char *friends, int depth, int n, int k){
	if(depth == k){
		if(checkRest(friends)) {
			count++;
		}
		return; 
	}

	for(int i=depth; i<n; i++){
		swap(friends, i, depth);
		getNum(friends, depth+1, n, k);
		swap(friends, i ,depth);
	}
}

int main(void){
	char friends[] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};
	cin >> N;
	for(int i=0; i<N; i++){
		scanf("%s", rest[i]);
	}
	
	getNum(friends, 0, 8, 8);
	cout << count;
	return 0;
}
