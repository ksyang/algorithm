#include <iostream>
#include <cstdio>

using namespace std;

int N;
int stairV[301];
int dp[301];

int getBiggest(int n){
	if(dp[n] != -1) return dp[n];
	dp[n] = max(stairV[n] + getBiggest(n-2), stairV[n] + stairV[n-1] + getBiggest(n-3));
	return dp[n];
}

int main(void){
	cin >> N;

	for(int i=0; i<N; i++){
		cin >> stairV[i];
	}

	for(int i=0; i<301; i++){
		dp[i] = -1;
	}
	
	dp[0] = stairV[0];
	dp[1] = stairV[0] + stairV[1];
	dp[2] = max(stairV[0] + stairV[2], stairV[1] + stairV[2]);

	cout << getBiggest(N-1);
	return 0;
}
