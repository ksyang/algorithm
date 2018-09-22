#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int HC[3][1001];
int dp[3][1001] = {{0,},};
int N;

int getMinCost(int c1, int n){
	int c2 = 0, c3 = 0;
	if(n >= N) return 0;
	if(dp[c1][n] != 0) return dp[c1][n];
	if(c1 == 0){
		c2 = 1;
		c3 = 2;
	}
	else if(c1 == 1){
		c2 = 0;
		c3 = 2;
	} else {
		c2 = 0;
		c3 = 1;
	}
	dp[c1][n] = HC[c1][n] + min(getMinCost(c2, n+1), getMinCost(c3, n+1));
	return dp[c1][n];
}

int main(void){
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> HC[0][i] >> HC[1][i] >> HC[2][i];
	}

	int tmp;
	tmp =	getMinCost(0, 0);
	tmp = min(tmp, getMinCost(1, 0));
	tmp = min(tmp, getMinCost(2, 0));
	cout << tmp;
	return 0;
}
