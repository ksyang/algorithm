#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n;
int m;
int map[101][101];

int cmp(int i, int j) {
	if(i == 0) return j;
	if(j == 0) return i;
	return min(i, j);
}

int adder(int i, int j) {
	if(i == 0 || j == 0)
		return 0;
	return i+j;
}

int main(void) {
	cin >> n;
	cin >> m;

	for(int i=0; i<m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			if(!map[a][b]){
				map[a][b] = c;
			} else {
				map[a][b] = min(map[a][b], c);
			}
	}

	for(int k=1; k<n+1; k++){
		for(int i=1; i<n+1; i++){
			for(int j=1; j<n+1; j++){
				if(i==j || k==i || k==j) continue;
				map[i][j] = cmp(map[i][j], adder(map[i][k], map[k][j]));
			}
		}
	}

	for(int i=1; i<n+1; i++){
		for(int j=1; j<n+1; j++){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}
